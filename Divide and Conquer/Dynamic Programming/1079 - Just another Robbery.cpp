#include<bits/stdc++.h>
using namespace std;

double lim ;
int n ;
int M[100+1] ;
double P[100+1] ;
double dp[101][10001] ;

double rec( int idx , int rem ){
    if( rem <= 0 ) return 0 ;
    if( idx < 0 ) return 1 ;
    if( dp[idx][rem] > -1 )return dp[idx][rem] ;
    double ret = 0 ;
    ret = rec( idx-1 , rem ) ;
    ret = min( ret , P[idx]+(1-P[idx])*rec( idx-1 , rem-M[idx] ) ) ;
    return dp[idx][rem] = ret ;
}

bool ok( int mid ){
    double currans = rec( n-1 , mid ) ;
    return currans <= lim ;
}

int main(){

    //freopen("1.txt","r",stdin) ;
	int cases , caseno = 1;
	scanf("%d",&cases ) ;

	while( cases -- ){

        scanf("%lf",&lim) ;
        scanf("%d",&n ) ;
        int T = 0 ;
        for( int i = 0 ; i < n ; i++ ){
            scanf("%d%lf",&M[i],&P[i] ) ;
            T+=M[i] ;
        }

        memset( dp , -1 , sizeof( dp ) ) ;

        int ans = 0 ;

        int low=0 ;
        int high = T ;
        int mid ;

        while( high-low >= 4 ){

            mid = (low+high)/2 ;
            if( ok( mid ) ){
                low = mid ;
            }else high = mid-1 ;

        }

        for( int i = high ; i >= low ; i-- ){
            if( ok(i) ) {
                ans = i ;
                break ;
            }
        }


        cout << "Case " << caseno++ << ": " << ans << "\n" ;


	}
	return 0;
}

