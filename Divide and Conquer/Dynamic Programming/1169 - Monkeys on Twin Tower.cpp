#include<bits/stdc++.h>
using namespace std ;
#define read freopen("1.txt" , "r" , stdin)
#define caseprint cout << "Case " << caseno++ << ": " ;
typedef long long i64 ;
int n ;
int LB[1000+1] , RB[1000+1] ;
int CL[1000+1] , CR[1000+1] ;
int dp[1000+1][2] ;

int rec(int floor , bool building ) {

    if( floor == n )return 0 ;
    if( dp[floor][building] != -1 ) return dp[floor][building] ;

    int ret = 0 ;

    if( building == 0 ) {
        ret = rec( floor+1 , 0 ) + LB[floor] ;
        ret = min( ret , rec( floor+1 , 1 ) + LB[floor] + CL[floor] ) ;
    } else {
        ret = rec( floor+1 , 1 ) + RB[floor] ;
        ret = min( ret , rec( floor+1 , 0 ) + RB[floor] + CR[floor] ) ;
    }
    return dp[floor][building] = ret ;

}



int main() {

    //read ;

    int cases , caseno =1 ;
    scanf("%d",&cases) ;

    while( cases -- ) {

        scanf("%d",&n) ;
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%d",&LB[i]) ;
        }
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%d",&RB[i]) ;
        }
        for( int i = 0 ; i < n-1 ; i++ ) {
            scanf("%d",&CL[i]) ;
        }
        for( int i = 0 ; i < n-1 ; i++ ) {
            scanf("%d",&CR[i]) ;
        }
        memset( dp , -1 , sizeof( dp ) ) ;
        cout << "Case " << caseno++ << ": " << min( rec( 0 , 0 ) , rec( 0 , 1 ) ) << "\n" ;
    }

    return 0 ;

}

