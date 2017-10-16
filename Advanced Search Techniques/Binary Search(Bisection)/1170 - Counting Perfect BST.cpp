#include<bits/stdc++.h>
#define MOD 100000007
using namespace std ;
typedef long long i64 ;

i64 range[102510+1] ;
int idx = 0 ;

void precalc() {
    set< i64 > st ;
    i64 lim = 10000000000LL ;
    i64 sqrtN =sqrt(lim) ;
    for( i64 i = 2 ; i <= sqrtN ; i++ ) {
        i64 tmp = i*i ;
        while( tmp <= lim ) {
            if( st.find( tmp ) == st.end()) {
                st.insert( tmp ) ;
                range[idx++] = tmp  ;
            }
            tmp *= i ;
        }
    }
    sort( range , range + idx ) ;
}

long long dp[102510+1] ;
long long rec( int tot ){

    if( dp[tot] != -1 )return dp[tot] ;
    if( tot == 1 ) return 1 ;
    if( tot == 0 ) return 1 ;
    long long ret = 0 ;
    for( int i = 1 ; i<= tot ; i++ ){
        ret += (( rec( i-1 ) % MOD ) * ( rec( tot - i ) % MOD ))%MOD ;
    }
    return dp[tot] = ret%MOD ;
}

int main() {

    precalc() ;

    int cases  , caseno = 1 ;
    scanf("%d",&cases ) ;

    memset( dp , -1 , sizeof(dp) ) ;
    while( cases -- ) {

        long long a , b ;
        scanf("%lld%lld",&a,&b) ;

        int tot = int( upper_bound( range , range+idx , b ) - lower_bound( range , range+idx , a )) ;
        if( tot>0 ) cout << "Case " << caseno++ << ": " << rec( tot ) << "\n" ;
        else cout << "Case " << caseno++ << ": 0" << "\n" ;

    }



    return 0 ;

}

