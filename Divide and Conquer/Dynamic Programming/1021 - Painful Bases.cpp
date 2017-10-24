#include<bits/stdc++.h>
using namespace std ;
#define read freopen( "1.txt" , "r" , stdin )
#define i64 long long
i64 dp[1<<16+1][21] ;
int tmp , l , Base  , K ;
string s ;
i64 rec( int mask , int mod  ){

    if( mask == ( (1<<l)-1 ) ) {
        return mod == 0 ;
    }
    if( dp[mask][mod] != -1 )return dp[mask][mod] ;
    i64 ret = 0 ;
    for( int i = 0 ;i  < l ; i++ ){
        if((mask&(1<<i))==0 ){
            if( isdigit(s[i]) ){
                tmp = s[i] - '0' ;
            }else tmp = s[i]-'A'+(10)*1 ;
            int nextmod = ((mod%K)*(Base%K)+tmp%K)%K ;
            ret+=rec( mask|(1<<i) , nextmod ) ;
        }
    }
    return dp[mask][mod] = ret ;

}

int main(){

    //read ;
    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    int t = 1<<16+1 ;
    while( cases -- ){

        scanf("%d%d",&Base,&K) ;
        cin >> s ;
        l= s.size() ;

        for( int i = 0 ; i < t ; i++ ){
            for( int j = 0 ; j  < 21 ; j ++ ){
                dp[i][j] = -1 ;
            }
        }
        cout << "Case "<<caseno++ << ": " << rec(0,0) << "\n" ;

    }

    return 0 ;
}

