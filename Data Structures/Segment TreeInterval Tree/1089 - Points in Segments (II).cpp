#include<bits/stdc++.h>
using namespace std ;

int main() {


    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        int n , q ;
        scanf("%d%d",&n,&q) ;

        int A[n+1],B[n+1];
        A[0] = -1 ;
        B[0] = -1 ;
        for( int i = 1 ; i <= n ; i++ ) {
            scanf("%d%d",&A[i] , &B[i] ) ;
        }
        sort( A , A + n+1 ) ;
        sort( B , B + n+1 ) ;
//        for( int i = 0 ; i <= n ; i++ ) {
//            cout << A[i]  << " " << B[i] << endl ;
//        }
//        cout << endl ;

        cout << "Case " << caseno++ << ":\n" ;

        while( q -- ) {

            int m ;
            scanf("%d",&m) ;
            int hi = n ;
            int lo = 0 ;
            int mid ;
            int ans = 0 ;
            while( hi-lo > 3 ) {
                mid = (hi+lo)/2 ;
                if(A[mid] <= m ) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            for( int i = hi ; i >= lo ; i-- ) {
                if( A[i] <= m ) {
                    ans = (i) ;
                    break ;
                }
            }

            m-- ;
            hi = n ;
            lo = 0 ;
            while( hi-lo > 3 ) {
                mid = (hi+lo)/2 ;
                if(B[mid] <= m ) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            for( int i = hi ; i >= lo ; i-- ) {
                if( B[i] <= m ) {
                    ans -= (i) ;
                    break ;
                }
            }
            cout << ans << "\n" ;


        }


    }

    return 0 ;

}

