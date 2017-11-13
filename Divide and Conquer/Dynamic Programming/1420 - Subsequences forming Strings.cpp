#include<bits/stdc++.h>
using namespace std ;
int cases, caseno = 1 ;
int dp[101][101][101][3] ;
int vis[101][101][101][3] ;
char str1[101],str2[101],str3[101] ;
int l1,l2,l3 ;
const int mod = 1000000007 ;
int rec( int idx1 , int idx2 , int idx3 , int perm ) {
    if( idx3 == l3 )return 1 ;
    if( idx2 >= l2 && idx1 >= l1 )return 0 ;
    if( vis[idx1][idx2][idx3][perm] == caseno ) {
        return dp[idx1][idx2][idx3][perm] ;
    }
    vis[idx1][idx2][idx3][perm] = caseno  ;
    int ret = 0 ;
    if( idx1 < l1 && str1[idx1] == str3[idx3] && perm != 2 ) {
        ret += rec( idx1+1 , idx2 , idx3+1 , 0 ) ;
        ret %= mod ;
    }
    if( idx1 < l1 && perm != 2 ) {
        ret += rec( idx1+1 , idx2 , idx3 , 1 ) ;
        ret %= mod ;
    }
    if( idx2 < l2 && str2[idx2] == str3[idx3] && perm != 1 ) {
        ret += rec( idx1 , idx2+1 , idx3+1 , 0 ) ;
        ret %= mod ;
    }
    if( idx2 < l2 && perm != 1 ){
        ret += rec( idx1 , idx2+1 , idx3 , 2 ) ;
        ret %= mod ;
    }
    return dp[idx1][idx2][idx3][perm] = ret ;
}

int main() {

    scanf( "%d" , &cases ) ;
    while( cases -- ) {
        scanf("%s%s%s",str1,str2,str3) ;
        l1 = strlen(str1) ;
        l2 = strlen(str2) ;
        l3 = strlen(str3) ;
        cout << "Case " << caseno << ": " << rec( 0 , 0 , 0 , 0 ) << "\n" ;
        caseno++ ;
    }
    return 0 ;
}

