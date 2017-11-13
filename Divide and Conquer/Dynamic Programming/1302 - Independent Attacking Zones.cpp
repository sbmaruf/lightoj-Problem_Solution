#include<bits/stdc++.h>
using namespace std ;
char str[71] ;
int l ;
long long dp[71][71] ;
bool ok( int l , int i , int j ){
    int n = 0 ;
    if( str[l]=='R' )n++ ;
    if( str[i]=='R' )n++ ;
    if( str[j]=='R' )n++ ;
    return n < 2 ;

}
long long rec( int l , int r ){

    if( l > r ) return 1 ;
    if( dp[l][r] != -1 ) return dp[l][r] ;
    long long ret = 0 ;
    for( int i = l+1 ; i<= r ; i++ ){
        for( int j = i+1 ; j <= r ; j++ ){
            if( ok( l, i , j )){
                ret += ( rec( l+1 , i-1 ) * rec( i+1 , j-1 ) )* rec( j+1 , r ) ;
            }
        }
    }
    return dp[l][r] = ret ;
}
int main(){

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ){

        scanf("%s",str) ;
        memset( dp , -1 , sizeof dp ) ;
        cout << "Case " << caseno ++ << ": " << rec( 0 , strlen( str )-1 ) << "\n" ;
    }

    return 0 ;
}

