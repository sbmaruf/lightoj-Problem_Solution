#include<bits/stdc++.h>
using namespace std ;


long long int nCr( int n , int r ){
    long long int ans = 1 ;
    if( n/2 < r ) r = n-r ;
    for( int i = 1 ; i <= r ; i++ ){
        ans *= n-r+i ;
        ans /= i ;
    }
    return ans ;
}


int main(){
    int cases ,caseno = 1 ;
    scanf("%d",&cases ) ;
    while( cases -- ){
        int n , k ;
        scanf("%d%d",&n,&k) ;
        cout << "Case " << caseno++ << ": " ;
        if( k > n ){
            cout << "0\n" ;
        }else if( k == 1 ){
            cout << n*n <<"\n" ;
        }else {
            long long int ans = 1 ;
            int last = n ;
            for( int i = 1 ; i <= k ; i++ ){
                ans *= last ;
                last-- ;
            }
            ans *= nCr( n , k ) ;
            cout << ans << "\n" ;
        }

    }



return 0 ;
}
//8
//1 1
//2 1
//3 1
//4 1
//4 2
//4 3
//4 4
//4 5

