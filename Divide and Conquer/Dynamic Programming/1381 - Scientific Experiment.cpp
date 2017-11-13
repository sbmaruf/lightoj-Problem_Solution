#include<bits/stdc++.h>
using namespace std ;
int dp[1005][2] ;
int n , x , y , z ;

int rec( int totRange , bool haveEgg ) {

    if(totRange == 1){
        if( haveEgg )return -x/2 ;
        else return 0 ;
    }

    if( dp[totRange][haveEgg] != -1 )
        return dp[totRange][haveEgg] ;

    int ret = 1<<28 ;
    int enter = 0 ;
    if( haveEgg == 0 )enter = x + y ;
    else enter = z ;

    for( int i = 1 ; i < totRange ; i++ ) {
        int ret1 = rec( i , 1 ) ;
        int ret2 = rec( totRange - i , 0 ) ;
        ret = min( ret , max( ret1 , ret2 ) ) ;
    }

    return dp[totRange][haveEgg] = ret + enter ;
}

int main() {

    int cases , caseno =1 ;
    cin >> cases ;
    while( cases -- ) {
        cin >> n >> x >> y >> z ;
        memset( dp, -1 , sizeof dp ) ;
        cout <<"Case " << caseno++ << ": " << rec(n,0) << "\n" ;
    }
    return 0 ;
}

