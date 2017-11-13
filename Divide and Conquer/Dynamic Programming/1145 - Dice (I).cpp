#include<bits/stdc++.h>

using namespace std;
#define MOD 100000007

long long dp[15000][2] ;
int main() {

    //freopen("1.txt","r",stdin) ;

    int cases , caseno = 1;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        long long N , K, S ;
        scanf("%lld%lld%lld",&N,&K,&S) ;
        bool r = 0 ;
        memset( dp , 0 , sizeof dp ) ;
        dp[0][0] = 1 ;
        for( int i = 1 ; i <= N ; i++ ){
            r = !r ;
            for( int j = 0 ; j <= S ; j++ ){
                if( j == 0 )dp[j][r] = 0 ;
                else {
                    //cout << j << " " << r << "\n" ;
                    long long temp =0;

                    if((j-K-1 )>= 0 )temp = dp[j-K-1][!r] ;

                    dp[j][r] = dp[j-1][r]+dp[j-1][!r]-temp;
                    dp[j][r] = ( dp[j][r] + MOD ) % MOD ;

                    //cout << dp[j][r] << "\n" ;
                }

            }
        }
        printf("Case %d: %lld\n",caseno++ , dp[S][r]) ;

    }
    return 0;
}

