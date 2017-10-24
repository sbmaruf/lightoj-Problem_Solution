/*
Author          :          Saiful Bari
LANG            :          C++
Problem No      :          Light Oj / UVA / SPOJ / LIVE Archive / Codeforces /
Problem Link    :

Learning        :
                            TASK
------------------------------------------------------------

------------------------------------------------------------
*/
   //bismillahirrahmanirrahim
#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI         vector<int>
#define VVI        vector< VI >
#define VIit       VI::iterator
#define pii        pair<int,int>
#define ui64       unsigned long long int
#define i64        long long int
#define pb(a)      push_back(a)
#define mp         make_pair


#define SI(a)      scanf("%d",&a)
#define Si(a)      scanf("%d",&a)
#define SU(a)      scanf("%u",&a)
#define SHD(a)     scanf("%hd",&a)
#define SHU(a)     scanf("%hu",&a)
#define SLLD(a)    scanf("%lld",&a)
#define SLLU(a)    scanf("%llu",&a)
#define SF(a)      scanf("%f",&a)
#define SLF(a)     scanf("%lf",&a)
#define SC(a)      scanf("%c",&a)
#define SS(a)      scanf("%s",a)
#define read       freopen("in.txt","r",stdin)
#define write      freopen("out.txt","w",stdout)
#define PI         acos(-1.0)
#define eps        1e-11
#define sq(a)      ((a)*(a))
#define x          first
#define y          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

int arr[20][20] ;
int n ;
int dp[17][1<<17] ;

int rec( int i , int bitmask ){

    if( i == n )return 0 ;

    if( dp[i][bitmask] != -1 )return dp[i][bitmask] ;

    int m = -1 ;

    rep( j , n ){
        if( !(bitmask & (1<<j )) ){
            m = max( m , rec( i+1 , bitmask | 1<<j )+arr[i][j] ) ;
        }
    }

    return dp[i][bitmask] = m ;

}

int main()
{
    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ){

        mem( dp , -1 ) ;

        SI( n ) ;
        rep(i,n)rep(j,n){
            Si( arr[i][j] ) ;
        }

        cout << "Case " << caseno++ << ": " << rec( 0 , 0 ) << "\n" ;

    }

    return 0;
}

