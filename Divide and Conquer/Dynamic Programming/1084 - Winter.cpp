#include<bits/stdc++.h>
using namespace std ;

inline int readInt() {
    int ip = getchar_unlocked(), ret = 0, flag = 1;
    for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
        if(ip == 45) {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }
    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

int cases , caseno = 1 ;
int L[100000+5] ;
int dp[1100000+5] , vis[100000+5] ;
int N , K ;

int rec( int idx ) {
    if( idx >= N )return 0 ;
    if( vis[idx] == caseno )return dp[idx] ;
    vis[idx] = caseno ;
    int ret = 1<<28 ;
    for( int i = idx+1 ; i < N ; i++ ){
        if( L[i]-L[idx] > 2*K  )break ;
        if( (i-idx+1) >= 3 ){
            ret = min( ret , rec( i+1 ) + 1 );
        }
    }
    return dp[idx] = ret ;
}

int main() {
    ios_base::sync_with_stdio(0) ;
    cin.tie(0) ;
    //cin >> cases ;
    cases = readInt() ;
    while( cases -- ) {
        //cin >> N >> K ;
        N = readInt() ;
        K = readInt() ;
        for( int i = 0 ; i < N ; i++ ) {
            //cin >> L[i] ;
            L[i] = readInt() ;
        }
        sort( L , L + N ) ;
        int ans = rec( 0 ) ;
        //cout << ans << endl ;
        if( ans*3 > N )cout << "Case " << caseno << ": -1\n" ;
        else cout << "Case " << caseno << ": " << ans << "\n" ;
        caseno++ ;
    }
    return 0 ;
}

