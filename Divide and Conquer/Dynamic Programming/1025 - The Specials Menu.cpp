#include<bits/stdc++.h>
using namespace std ;
#define read freopen("1.txt" , "r" , stdin )
long long dp[61][61] ;
string s ;
long long rec( int st , int en ){

    if( st>en ) return 0 ;
    else if( dp[st][en] != -1 )return dp[st][en] ;
    long long ret = 0 ;
    if( s[st] == s[en] ){
        ret = rec( st+1 , en-1 ) +1 ;
    }
    ret += rec( st+1 , en ) ;
    ret += rec( st , en-1 ) ;
    ret -= rec( st+1 , en-1 ) ;
    return dp[st][en] = ret ;

}

int main(){

    //read ;

    int cases , caseno = 1 ;
    scanf("%d",&cases) ;

    while( cases -- ){

        cin >> s ;
        int l = s.size() ;
        for( int i = 0 ; i < l ; i++){
            for( int j = 0 ; j < l ; j++ ){
                dp[i][j] = -1 ;
            }
        }
        cout << "Case " <<caseno++ << ": " << rec( 0 , l -1 )  << "\n" ;
    }




    return 0 ;
}

