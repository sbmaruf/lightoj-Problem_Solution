#include<bits/stdc++.h>
using namespace std ;
int A[10000+1]  ;
int arr[10000+1] ;
int inf = 1 << 30 ;
int n ;
bool ok(int i ) {
    if( arr[i] == inf && arr[n-i-1] == inf ) return 0 ;
    if( arr[i] != inf && arr[n-i-1] != inf )arr[n-i-1] = inf ;
    else if( arr[i] != inf && arr[n-i-1] == inf )arr[i] = inf ;
    else if( arr[i] == inf && arr[n-i-1] != inf ) arr[n-i-1] = inf ;
    return 1 ;
}

int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        scanf("%d",&n) ;
        memset( arr , 0 , sizeof arr ) ;
        bool f = 1 ;
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%d",&A[i] ) ;
            if( A[i] >= n ) {
                f = 0 ;
                continue ;
            }
        }
        if( f ) {
            for( int i = 0 ; i < n ; i++ ) {
                if( !ok(A[i]) ) {
                    f = 0 ;
                    break ;
                }
            }
        }
        cout << "Case " << caseno++ << ": " << (f?"yes":"no")  << "\n" ;
    }


}

