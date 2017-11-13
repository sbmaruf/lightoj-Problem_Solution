#include<bits/stdc++.h>
using namespace std ;

long long dp[51][51][51] ;

long long rec( int n , int k , int m )
{

    if( n == 0 ) {
        return k == 0 ;
    } else if( k == 0 ) return 0 ;

    if( dp[n][k][m] != -1 ) return dp[n][k][m] ;

    long long ret = 0 ;
    for( int i = 0 ; i < m ; i++ ) {
        if( i >= n ) break ;
        ret += rec( n - i - 1 , k - 1 , m ) ;
    }
    return dp[n][k][m]=ret ;
}

int main()
{

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;
    for( int i = 0 ; i < 51 ; i++ ) {
        for( int j = 0 ; j < 51 ; j++ ) {
            for( int k = 0 ; k < 51; k ++ ) {
                dp[i][j][k] = -1 ;
            }
        }
    }
    while( cases -- ) {
        int n , m , k ;
        scanf("%d%d%d",&n,&k,&m) ;
        cout << "Case " << caseno++ << ": " << rec( n , k , m ) << "\n" ;
    }

}

