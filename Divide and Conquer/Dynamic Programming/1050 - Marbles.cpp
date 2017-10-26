#include<bits/stdc++.h>
using namespace std;
double dp[505][505] ;
double rec(int R , int B ) {
    if( R == 0.0 && B )return 1 ;
    if( R == 0.0 && !B )return 1 ;
    if( B <= 0 && R ) return 0 ;
    if( R==0 && B==0 )return 1 ;
    if( dp[R][B] > -1 ) return dp[R][B] ;
    return dp[R][B] = (double(R)/double(R+B))*rec( R-1 , B-1 )+(double(B)/double(R+B))*rec( R , B-2 );
}
int main() {

    int cases , caseno = 1;
    scanf("%d",&cases ) ;

    memset(dp , -1 , sizeof(dp) ) ;

    while( cases -- ) {

        int R , B ;
        scanf("%d%d",&R,&B) ;

        printf("Case %d: %.8f\n",caseno++,rec( R,B ) ) ;

    }
    return 0;
}

