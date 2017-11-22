#include<bits/stdc++.h>
using namespace std ;

int main(){

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ){
        int n ;
        scanf("%d",&n ) ;
        int F[n] , S[n] ;

        for( int i = 0 ; i < n ; i++ ){
            scanf("%d%d",&F[i],&S[i] );
        }
        sort( F , F+ n );
        sort( S , S+ n );

        int t = 0 ;
        int cnt = 0 ;
        for( int i = 0 , j = 0 ; i < n ; i++ , j++ ){
            if( F[i] <= S[j] ){
                if( t == 0 )cnt ++ ;
                else t -- ;
                j-- ;
            }else i-- , t++ ;
        }
        cout << "Case " << caseno ++ << ": " << cnt << "\n" ;
    }



    return 0 ;
}

