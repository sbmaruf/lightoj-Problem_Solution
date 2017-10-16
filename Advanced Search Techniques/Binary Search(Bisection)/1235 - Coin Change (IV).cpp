#include<bits/stdc++.h>
using namespace std ;
int n , k ;
int arr[2][9];
vector<int>V[2] ;
int l[2] ;
void rec( int idx , int sum , bool flag ) {

    if (idx == l[flag] ){
        V[flag].push_back( sum ) ;
        return ;
    }
    rec( idx+1 , sum , flag ) ;
    rec( idx+1 , sum + arr[flag][idx] , flag ) ;
    rec( idx+1 , sum + 2*arr[flag][idx] , flag ) ;
}

int main()
{
    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        scanf("%d%d",&n,&k) ;
        l[0] = n/2 ;
        l[1] = n - l[0] ;

        for( int i = 0 ; i < l[0]  ; i++ ) {
            scanf( "%d" , &arr[0][i] ) ;
        }
        for( int i = 0 ; i < l[1]  ; i++ ) {
            scanf( "%d" , &arr[1][i] ) ;
        }

        V[0].clear() ;
        V[1].clear() ;

        rec( 0 , 0 , 0 ) ;
        rec( 0 , 0 , 1 ) ;

        sort( V[0].begin() , V[0].end() ) ;
        bool flag = 0 ;
        for( int i = 0 ; i < V[1].size() ; i++ ){
            int Find = k-V[1][i] ;
            if( binary_search(V[0].begin() , V[0].end() , Find ) == true ){
                flag = 1 ;
                break ;
            }
        }
        if( flag ){
            cout<< "Case " << caseno++ << ": " << "Yes\n" ;
        }else {
            cout<< "Case " << caseno++ << ": " << "No\n" ;
        }

    }

}

