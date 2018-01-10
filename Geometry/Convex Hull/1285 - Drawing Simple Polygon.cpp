#include<bits/stdc++.h>
#define x first
#define y second
using namespace std ;

pair< pair< double, double >, int >arr[2000+1] ;
pair< pair< double, double >, int >Ref , head , tail ;

bool low(pair< pair< double, double >, int > a , pair< pair< double, double >, int > b ){
    if( a.x.y == b.x.y )return a.x.x<b.x.x ;
    return a.x.y<b.x.y ;
}

double dist( pair< pair< double, double >, int > a , pair< pair< double, double >, int > b ){
    return sqrt((a.x.x-b.x.x)*(a.x.x-b.x.x)+(a.x.y-b.x.y)*(a.x.y-b.x.y)) ;
}

bool comp(pair< pair< double, double >, int > a , pair< pair< double, double >, int > b ){
    if( (a.x.y-Ref.x.y)*(b.x.x-Ref.x.x) == ((a.x.x-Ref.x.x)*(b.x.y-Ref.x.y)) ){
        return dist( a , Ref )<dist( b , Ref) ;
    }
    else
        return (((a.x.y-Ref.x.y)*(b.x.x-Ref.x.x)) < ((a.x.x-Ref.x.x)*(b.x.y-Ref.x.y))) ;
}
bool OnLine(  pair< pair< double, double >, int > a  ){
    return ((a.x.y-head.x.y)*(tail.x.x-head.x.x) == (a.x.x-head.x.x)*(tail.x.y-head.x.y)) ;
}
int main()
{

    int cases , caseno = 1;
    scanf("%d",&cases ) ;

    while(cases -- ) {

        int n ;
        scanf("%d",&n ) ;

        scanf("%lf%lf",&arr[0].x.x , &arr[0].x.y) ;
        arr[0].y = 0 ;
        pair< pair < double , double > , int > m = arr[0] ;

        for( int i = 1 ; i< n ; i ++ ) {
            scanf("%lf%lf",&arr[i].x.x , &arr[i].x.y) ;
            arr[i].y = i ;
            if( low( arr[i] , m ) ) {
                m = arr[i] ;
            }

        }

        swap( arr[m.y] , arr[0] ) ;
        Ref = head = arr[0] ;

        sort( arr+1 , arr+n , comp ) ;
        tail = arr[n-1] ;
        int back = -1 ;
        for( int i = n-2 ; i> 0 ; i-- ){
            if( !OnLine( arr[i] ) ) {
                back = i ;
                break ;
            }
        }

        cout << "Case "  << caseno ++ << ":\n" ;
        if( back == -1 ){
            cout << "Impossible" << "\n" ;
            continue ;
        }

        bool f = 0 ;
        for( int i = 0 ; i <= back ; i++ ){
            if( i ) cout << " " ;
            cout << arr[i].y ;
            f = 1 ;
        }

        for( int i = n-1 ; i > back ; i-- ){
            if( f && i == n-1 )cout << " " ;
            if( i <= n-2 )cout << " " ;
            cout << arr[i].y ;
        }

        cout << "\n" ;

    }

}

