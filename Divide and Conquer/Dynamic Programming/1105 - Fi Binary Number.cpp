#include<bits/stdc++.h>
using namespace std ;
#define read freopen("1.txt","r",stdin)
typedef unsigned long long ui64 ;

int fib[50] ;


int main()
{

    //read;
    int cases , caseno = 1 ;

    fib[0] = 1 ;
    fib[1] = 2 ;
    for( int i = 2 ; i < 44 ; i++ ) {
        fib[i] = fib[i-1]+fib[i-2] ;
    }

    scanf("%d",&cases) ;


    while( cases -- ) {

        int n ;
        scanf("%d",&n) ;

        cout << "Case " << caseno++ << ": " ;

        long long bitfield = 0 ;

        for( int i = 43 ; i >= 0 ; i-- ) {

            if( fib[i] <= n ) {
                bitfield |= ((1LL) << i );
                n-=fib[i] ;
                if( n == 0 )break ;
            }

        }

        int startpos = 44 ;
        while( !( bitfield & ((1LL)<<startpos) ) )startpos -- ;

        for( int i = startpos ; i >= 0 ; i-- ) {
            cout<<bool( bitfield & ((1LL)<<i) ) ;
        }
        cout << "\n" ;

    }
}

