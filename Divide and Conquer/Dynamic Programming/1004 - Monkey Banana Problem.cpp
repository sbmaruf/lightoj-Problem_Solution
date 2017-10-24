/*
ID: Ordinary_Sheep
LANG: C++
TASK:
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
#define pi         acos(-1.0)
#define eps        1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi          first
#define se          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

int n , p ;
int arr[200+20][200+20] ;
int dp[200+20][200+20] ;

i64 rec( int r , int c ){

    if( r == p ) return 0 ;
    else if( c < 0 ) return 0 ;
    else if( arr[r][c] == 200 ) return 0 ;
    else if( dp[r][c] != -1 ) return dp[r][c]  ;
    else if( r >= n-1 ){
        return dp[r][c] = max( rec(r+1 , c-1 ) + arr[r][c] , rec ( r+1 , c ) + arr[r][c]) ;
    }else {
        return dp[r][c] = max( rec( r+1 , c ) + arr[r][c], rec( r+1 , c+1 ) + arr[r][c] ) ;
    }

}

int main()
{
    int cases , casesno = 1  ;
    SI( cases ) ;

    while( cases -- ){

        SI( n ) ;
        p = 2*n - 1 ;

        rep( i , 200 )
            rep( j , 200 )
                arr[i][j] = 200 ;

        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < i+1 ; j++ ){
                SI( arr[i][j] ) ;
                dp[i][j] = -1 ;
            }
        }

        for( int i = n , k = n-1 ; i < p ; i++ , k-- ){
            for( int j = 0 ; j < k ;  j++ ){
                SI( arr[i][j] ) ;
                dp[i][j] = -1 ;
            }
        }

        printf("Case %d: %lld\n",casesno++ , rec( 0 , 0 ));
    }

    return 0;
}

