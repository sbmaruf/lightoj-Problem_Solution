#include<bits/stdc++.h>
#define x first
#define y second
#define pdd pair<double,double>
#define pi acos(-1.0)

using namespace std ;

int n ;
pdd arr[100000+1] ;
pdd unq[100000+1] ;
pdd ans[100000+1] ;
bool low(pdd a , pdd b){
    if( a.y == b.y )return a.x>b.x ;
    return a.y<b.y ;
}
bool comp( pdd a , pdd b )
{
    return (b.y-unq[0].y)*(a.x-unq[0].x)>(b.x-unq[0].x)*(a.y-unq[0].y);
}
bool isRight(pdd a , pdd b , pdd c )
{
    return ((c.y-a.y)*(b.x-a.x)<(c.x-a.x)*(b.y-a.y)) ;
}
double dist( pdd a , pdd b )
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y)  ) ;
}
int main()
{
    int cases , caseno = 1  ;
    scanf("%d",&cases ) ;

    while( cases -- ) {
        scanf("%d",&n) ;
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%lf%lf",&arr[i].x,&arr[i].y );
        }
        sort( arr , arr + n , low ) ;

        int idx = 0 ;
        unq[idx++] = arr[0] ;

        for( int i = 1 ; i< n ; i++ ) {
            if( arr[i].x == arr[i-1].x && arr[i].y == arr[i-1].y )continue ;
            unq[idx++] = arr[i] ;
        }

        n = idx ;
        sort( unq+1 , unq + n , comp ) ;

        idx = 0 ;
        if( n == 1 || n == 2 ) {
            cout << "Case " << caseno ++ << ": " << 0 << "\n" ;
            continue ;
        }

        ans[idx++] = unq[0] ;
        ans[idx++] = unq[1] ;
        ans[idx++] = unq[2] ;

        for( int i = 3 ; i < n ; i++ ) {
            while( isRight( ans[idx-2] , ans[idx-1] , unq[i] ) )
                idx-- ;
            ans[idx++] = unq[i] ;
        }

        double ANS = 400.0 ;
        n = idx ;
        for( int i = 0 ; i < n ; i++ ) {

            int j = (i+1)%n ;
            int k = (i+2)%n ;

            double len1 = dist( ans[i] , ans[j] ) ;
            double len2 = dist( ans[j] , ans[k] ) ;
            double len3 = dist( ans[k] , ans[i] ) ;

            double angle = acos(( len1*len1 + len2*len2 - len3*len3 )/(2*len1*len2)) ;
            angle = angle*(180/pi) ;

            ANS = min( ANS , angle ) ;

        }
        cout << setprecision( 15 ) << "Case " << caseno ++ << ": " << ANS << "\n" ;

    }

    return 0 ;
}

