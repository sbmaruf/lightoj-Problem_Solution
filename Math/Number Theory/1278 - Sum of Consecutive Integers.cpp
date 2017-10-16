#include<bits/stdc++.h>

#define rep(i,n) for( int i = 0 ;i < n ; i ++ )

#define pi pair<int,int>
#define pii64 pair<long long ,long long>
#define pd pair<double,double>


#define x first
#define y second
#define PI acos(-1.0)
using namespace std;

#define MAX 10000000
unsigned flag[MAX/64];
vector<long long>prime ;

#define chkC(n) (flag[n>>6]&(1<<((n>>1)&31)))
#define setC(n) (flag[n>>6]|=(1<<((n>>1)&31)))
int lim;
void sieve() {
    unsigned i, j, k;
    flag[0]|=0;
    int sqrtN = sqrt(MAX) ;
    for(i=3; i<= sqrtN ; i+=2)
        if(!chkC(i))
            for(j=i*i,k=i<<1; j<MAX; j+=k)
                setC(j);
    prime.push_back(2);

    for(i=3; i<MAX; i+=2)
        if(!chkC(i))
            prime.push_back(i) ;
    lim = prime.size() ;
}

long long pf( long long n ) {
    while( n%2 == 0 )n/=2 ;
    long long ans = 1  ;
    for( int i = 0; i < lim and prime[i]*prime[i] <= n ; i++ ) {
        if( n%prime[i] == 0 ) {
            int cnt = 1 ;
            while( n%prime[i] == 0 ) {
                cnt++ ;
                n/=prime[i] ;
            }
            ans *= cnt ;
        }
    }
    if( n > 1 )return (ans<<1)-1 ;
    return ans-1 ;
}

int main() {

    sieve() ;
    int cases , caseno =1  ;
    scanf("%d",&cases ) ;

    while( cases --  ) {

        long long  int n ;
        scanf("%lld",&n ) ;
        cout << "Case " << caseno++ << ": " << pf(n) << "\n" ;

    }
    return 0;
}
/*
This is the classical problem. The problem is named after thepoliteness of a number.
Solution is #numer of odd divisor-1

The impolite numbers are exactly the powers of two.
(I+1) + (I+2) + (I+3) .... (J) = T(j) - T(i-1)

*/
