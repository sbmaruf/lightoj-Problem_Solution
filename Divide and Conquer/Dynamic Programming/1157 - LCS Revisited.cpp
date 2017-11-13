#include<bits/stdc++.h>
using namespace std ;
#define MOD 1000007
char str1[1000+1] , str2[1000+1] ;
int l1 , l2 ;
int dp[1001][1001] ;
int L[1001][1001] ;

int lcs( int st , int en ){

    if( st == 0 ) return 0 ;
    if( en == 0 ) return 0 ;

    if( L[st][en] != -1 ) return L[st][en] ;
    int ret = 0 ;

    if( str1[st] == str2[en] )ret = lcs ( st-1 , en-1 )+1 ;
    else {
        ret = max( lcs( st -1 , en ) , lcs( st , en-1 ) ) ;
    }
    return L[st][en] = ret ;

}


long long rec( int st , int en ){

    if( st == 0 ) return 1 ;
    if( en == 0 ) return 1 ;

    if( dp[st][en] != -1 ) return dp[st][en] ;

    long long ret = 0 ;

    if( str1[st] == str2[en] )ret = rec( st-1 , en-1 )%MOD ;
    else {
        if( lcs( st , en ) == lcs( st-1 , en-1 ) ){
            ret -= rec( st-1 ,  en-1 ) ;
            ret = ( ret + MOD ) % MOD ;
            // Hebby para dise.... :(
        }
        if( lcs( st , en ) == lcs( st-1 , en ) ){
            ret += rec( st-1 , en )%MOD ;
        }
        if( lcs( st , en ) == lcs( st , en-1 ) ){
            ret += rec( st ,  en-1 )%MOD ;
        }

    }
    return dp[st][en] = ret%MOD ;
}

int main(){

    //freopen("1.txt" , "r" , stdin ) ;

    int cases , caseno =1 ;

    scanf("%d",&cases ) ;

    while( cases -- ){

        scanf("%s%s",str1+1,str2+1) ;

        l1 = strlen( str1+1 ) ;
        l2 = strlen( str2+1 ) ;

        for( int i = 0 ; i < l1+1 ; i++ ){
            for( int j = 0 ; j < l2+1 ; j++ ){
                dp[i][j] = -1 ;
                L[i][j] = -1 ;
            }
        }
        cout << "Case " << caseno++ << ": " << rec( l1 , l2 ) << "\n" ;

    }



}

