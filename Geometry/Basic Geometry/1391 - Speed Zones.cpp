#include<bits/stdc++.h>
using namespace std ;
int N  ;
double D ;
double arr[100+1] ;
double ret ;
int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases)  ;
    while( cases -- ) {
        scanf("%d%lf",&N,&D) ;
        for( int i = 0 ; i < N ; i++ )scanf("%lf",&arr[i] ) ;
        double lo = 0 ;
        double hi = 100;
        double mid ;
        for( int i = 0 ; i < 80 ; i++ ) {
            mid = (lo+hi)/2 ;
            ret = 0 ;
            for( int i = 0 ; i < N ; i++ ) {
                ret += (100*mid*arr[i])/sqrt(1-mid*mid*arr[i]*arr[i]) ;
            }
            if( ret<D ) lo = mid ;
            else hi = mid ;
        }
        double ans = 0 ;
        for( int i = 0 ; i < N ; i++ ) {
            double xi = (100*mid*arr[i])/sqrt(1-mid*mid*arr[i]*arr[i]) ;
            ans += sqrt(100.0*100.0+xi*xi)/arr[i] ;
        }
        cout << "Case " << setprecision( 12 ) << caseno++ << ": " << ans << "\n" ;
    }
    return 0 ;
}

