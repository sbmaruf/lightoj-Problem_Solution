#include<bits/stdc++.h>
using namespace std ;
int n ;
int arr[16][16] ;
long long dp[(1<<15)+1][2][2] ;

long long rec( int mask , bool all , bool s ){
    if( mask == ( (1 << n)-1 ) ){
        return int( all || s ) ;
    }
    if( dp[mask][all][s] != -1 )return dp[mask][all][s] ;
    long long ret = 0 ;
    int upto = __builtin_popcount(mask) ;
    for( int i = 0 ;i < n ; i++ ){
        if( (mask & (1<<i)) ==  0 ){
            ret += rec( (mask|(1<<i)) ,arr[upto][i] && (all) , ((arr[upto][i]==2)?1:0) | (s)  ) ;
        }
    }
    return dp[mask][all][s] = ret ;
}

int main(){

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ){
        scanf("%d",&n) ;
        for( int i = 0; i < n ; i++ ){
            for( int j = 0 ;j < n ; j++ ){
                scanf("%d",&arr[i][j] ) ;
            }
        }
        memset( dp , -1 , sizeof( dp ) ) ;
        cout << "Case " << caseno++ << ": " << rec( 0 , 1 , 0 ) << "\n" ;
    }
    return 0 ;
}

