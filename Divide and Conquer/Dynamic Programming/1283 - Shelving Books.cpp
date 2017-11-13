#include<bits/stdc++.h>
using namespace std ;

int n ;
int arr[100+5] ;
char dp[105][100+5][100+5] ;

char rec( int idx , int l , int r )
{

    if( idx == (n+1) ) return 0 ;
    if( dp[idx][l][r] != '-' )return dp[idx][l][r] ;

    char ret = rec( idx+1 , l , r )  ;
    if( arr[idx] >= arr[l] && arr[idx] <= arr[r] ) {
        char ch = rec( idx+1 , idx , r ) ;
        ch = ch + 1 ;
        if( ch > ret )ret = ch ;

        ch = rec( idx+1 , l , idx ) ;
        ch = ch + 1 ;
        if( ch > ret )ret = ch ;
    }
    return dp[idx][l][r] = ret ;

}

int main()
{


    int cases , caseno =1 ;
    scanf("%d",&cases) ;

    while( cases -- ) {

        scanf("%d",&n) ;

        for( int i = 1 ; i <= n ; i++ ) {
            scanf( "%d", &arr[i] ) ;
        }
        arr[0] = -1;
        arr[n+1] = 100000+1 ;

        memset( dp , '-' , sizeof( dp ) ) ;
        char ch = rec( 1 , 0 , n+1 ) ;
        printf("Case %d: %d\n",caseno++ , ch) ;
    }

    return 0 ;

}

