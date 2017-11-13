#include<bits/stdc++.h>
using namespace std ;
#define read freopen("1.txt","r",stdin)
typedef unsigned long long ui64 ;

ui64 N , m ;
ui64 dp[52][52][2] ;
ui64 rec(int leftset , int hi, bool f ) {

    if( leftset == 0 && hi == 0 )return 1 ;
    if( dp[leftset][hi][f] != -1 )return dp[leftset][hi][f] ;
    ui64 ret = 0 ;
    if( f == 1 ) {
        for( int i = 1 ;i <= leftset ; i++ ) {
            ret += rec( i-1 , hi+(leftset-i) , 0 ) ;
        }
    } else {
        for( int i = 1 ; i <= hi ; i++ ) {
            ret += rec( leftset + (i-1) , hi-i , 1) ;
        }
    }
    return dp[leftset][hi][f] = ret ;

}

int main() {

    //read;
    int cases , caseno = 1 ;
    scanf("%d",&cases) ;
    memset( dp , -1 , sizeof( dp ) ) ;
    while( cases -- ) {

        scanf("%d%d",&N,&m) ;

        if( m == 1 ){
            if( N ==1 )cout << "Case "<<caseno++ << ": " << 1 << "\n" ;
            else if( N == 2 )cout << "Case "<<caseno++ << ": " << 1 << "\n" ;
            else {
                cout << "Case "<< caseno++ << ": " << rec( 0 , N-3 , 0 ) << "\n" ;
            }
        }
        else cout << "Case "<<caseno++ << ": " << rec( m-1 , N-m , 1 ) << "\n" ;


    }
}

