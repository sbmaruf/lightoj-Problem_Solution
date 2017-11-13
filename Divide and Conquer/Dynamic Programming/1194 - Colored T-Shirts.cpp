#include<bits/stdc++.h>
using namespace std ;

int cases,caseno=1 ;
long long dp[(1<<16)+1] ;
long long predp[17][17] , cum[17] ;
int n , m , color ;
int vis[(1<<16)+1] ;
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

long long rec( int mask ) {
    if( (mask) == ((1<<(m))-1) ) return 0LL ;
    if( vis[mask] == caseno )return dp[mask] ;
    vis[mask] = caseno ;
    long long ret = 1LL<<62;
    for( int i = 0 ; i < m ; i++ ) {
        if( (mask&(1<<i))==0 ) {
            long long cost = 0 ;
            for( int j = 0 ; j < m ; j++ ) {
                if( (mask&(1<<j))==0 && i!=j ) {
                    cost += predp[i][j] ;
                }
            }
            ret = min( ret , rec( mask|(1<<i) )+cost ) ;
        }
    }
    return dp[mask] = ret ;
}

int main() {
    cin >> cases ;
    while( cases -- ) {
        //cin >> n >> m ;
        n = readInt() ;
        m = readInt() ;
        memset( predp , 0 , sizeof predp ) ;
        memset( cum , 0 , sizeof cum ) ;
        for( int i = 0 ; i < n ; i++ ) {
            //cin >> color ;
            color = readInt() ;
            for( int j = 0 ; j < m ; j++ ) {
                predp[color-1][j] += cum[j] ;
            }
            cum[color-1]++ ;
        }
        cout << "Case " << caseno << ": " << rec(0) << "\n" ;
        caseno++ ;
    }
    return 0 ;
}

