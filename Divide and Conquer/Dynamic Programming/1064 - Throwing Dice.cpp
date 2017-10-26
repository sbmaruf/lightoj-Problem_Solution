//bismillahirrahmanirrahim
#include <bits/stdc++.h>
#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI vector<int>
#define VVI vector< VI >
#define VIit VI::iterator
#define pii pair<int,int>

#define pb(a) push_back(a)
#define mp make_pair


#define SI(a) scanf("%d",&a)
#define SU(a) scanf("%u",&a)
#define SHD(a) scanf("%hd",&a)
#define SHU(a) scanf("%hu",&a)
#define SLLD(a) scanf("%lld",&a)
#define SLLU(a) scanf("%llu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)
#define swp(type, a, b) {type x=a; a=b; b=x;}
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define pi acos(-1.0)
#define eps 1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define wez(n) int (n); scanf("%d",&(n));
#define wez2(n,m) int (n),(m); scanf("%d %d",&(n),&(m));
#define wez3(n,m,k) int (n),(m),(k); scanf("%d %d %d",&(n),&(m),&(k));
#define TEST1 wez1(testow)while(testow--)
#define TEST2 wez2(testow)while(testow--)
#define TEST3 wez3(testow)while(testow--)

#define fi          first
#define se          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())
#define i64         long long int
#define ui64        unsigned long long int
//int dR8[]= {0,-1,-1,-1,0,1,1,1};
//int dC8[]= {1,1,0,-1,-1,-1,0,1};
//int dR4[]= {0,-1,0,1};
//int dC4[]= {1,0,-1,0};
//int dR[]={-2,-1, 1, 2, 2,1,-1,-2};
//int dC[]={-1,-2,-2,-1, 1,2, 2, 1};
int n,x;
ui64 ret = 0;
ui64 dp[26][152];

ui64 gcd(ui64 i, ui64 j) {
    return ( j == 0 )? i : gcd( j, i % j );
}

ui64 rec( int sum, int d ){

    if( d==n ){
        if( sum>=x ) return 1;
        else return 0;
    }
    else if( dp[d][sum] != -1 )return dp[d][sum];
    else {
        ret = rec( sum+1 , d+1 ) + rec( sum+2 , d+1 ) + rec( sum+3 , d+1 ) + rec( sum+4 , d+1 ) + rec( sum+5 , d+1 ) + rec( sum+6 , d+1 );
        return dp[d][sum] = ret;
    }

}

int main()
{
    int cases,caseno=1;
    SI(cases);
    while(cases--){
        SI(n);SI(x);
        ui64 six=1;
        mem(dp,-1);
        rep( i, n )six*=6;
        ret = 0;
        ui64 p = rec( 0,0 );
        i64 GCD = gcd ( six , p );
        six /= GCD;
        p /= GCD;
        printf("Case %d: ",caseno++);
        if( p==0 ) printf("0\n");
        else if( six == 1 ) printf("1\n");
        else printf("%lld/%lld\n",p,six);
    }

    return 0;
}

