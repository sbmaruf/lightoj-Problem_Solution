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

struct item{
int low , high , cost ;
}arr[30000+10];
int L[30000+10] ;
int H[30000+10] ;

int dp[30000+10] ;
int n ;

int rec( int i ){

    if( i == n ) return 0 ;
    else if( dp[i] != -1 ) return dp[i] ;
    else {
        return dp[i] = max ( rec( i + 1 ) , rec( upper_bound( L , L+n , H[i]  ) - L )+ arr[i].cost ) ;
    }

}

bool comp ( item i , item j ){

    if( i.low == j.low ){
        return i.high<j.high ;
    }else return i.low<j.low ;

}
int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases -- ){

        SI( n ) ;
        for( int i = 0 ; i < n ; i++ ){
            SI( arr[i].low ) ;
            SI( arr[i].high ) ;
            SI( arr[i].cost ) ;
        }
        sort( arr , arr + n  , comp ) ;

        rep( i, n )
        {
            L[i] = arr[i].low ;
            H[i] = arr[i].high + arr[i].low - 1 ;
            dp[i] = -1 ;
        }

        printf("Case %d: %d\n",caseno++ , rec( 0 ) ) ;


    }
    return 0;
}

