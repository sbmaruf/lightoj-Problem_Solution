#include<bits/stdc++.h>
#define MOD  1000000007

using namespace std ;

long long nCr[1000+1][1000+1] ;
long long dp[1000+1][1000+1] ;
long long fact[1000+1] ;

void precalc(){
    fact[0] = 1 ;
    for( int i = 0 ; i < 1001 ; i++ )nCr[i][0] = 1 ;
    for( int i = 1 ; i < 1001 ; i++ ){
        for( int j = 1 ; j <= i ; j++ ){
            nCr[i][j] = (nCr[i-1][j-1]%MOD + nCr[i-1][j]%MOD)%MOD ;
        }
        fact[i] = (((long long)i)*fact[i-1])%MOD ;
    }
}

long long rec( long long tot , long long dearrangement ){

    if( dearrangement == 0 ) return fact[tot] ;
    if( dp[tot][dearrangement] != -1 )return dp[tot][dearrangement] ;
    else if ( dearrangement == 1 ) return dp[tot][dearrangement] = ((tot-dearrangement)*rec( tot-1 , dearrangement - 1 ))%MOD ;
    else {
        long long ret = ((tot-1 )*rec( tot-1 , dearrangement - 1 ))%MOD ;
        ret += ( (dearrangement-1) * ( rec( tot-2 , dearrangement - 2 ) ) )%MOD ;
        return dp[tot][dearrangement] = ret%MOD ;
    }
}
int main(){

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    precalc() ;
    memset( dp , -1 , sizeof dp ) ;

    while( cases -- ){

            int n , m , k ;
            scanf("%d%d%d",&n,&m,&k);
            cout << "Case " << caseno++ << ": " << ( nCr[m][k] * rec( n-k , m-k )) % MOD << "\n" ;
    }

}

