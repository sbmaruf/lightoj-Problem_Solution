#include<bits/stdc++.h>
using namespace std ;

double dp[100000+1] ;
bool vis[100000+1] ;

double solve( int N ){

    if( N == 1 )return 0 ;
    if( vis[N] )return dp[N] ;
    vis[N] = 1 ;
    int sqrtN = sqrt( N ) ;
    int div = 1 ;
    double ret = 0 ;
    for( int i = 2 ;i <=sqrtN ; i++ ){
        if( N%i == 0 ){
            ret += 1 + solve( i ) ;
            div++ ;
            if( N/i != i ){
                ret += 1 + solve( N/i ) ;
                div++ ;
            }
        }
    }
    ret += 2 ;
    ret /= double(div) ;
    return dp[N] = ret ;

}


int main(){

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ){

        int N ;
        scanf("%d",&N) ;
        double ans = solve( N ) ;
        cout << setprecision(15) <<"Case " << caseno++ << ": " <<  ans << "\n" ;

    }




    return 0 ;

}

