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

int arr[201],N;
int D,M;
long long int dp[202][12][22];
long long int rec( int n, int m, int sum ){
    if(!n && m!=0)return 0;
    if(!m){
        if(sum%D==0)return 1;
        else return 0;
    }
    int temp = sum;
    int temp1=arr[n]%D;
    if(temp1<0) temp1+=D;
    sum += temp1;
    sum=sum%D;
    if(dp[n][m][sum] != -1) return dp[n][m][sum];
    return dp[n][m][sum] = rec( n-1, m-1, sum) + rec( n-1, m, temp);
}
int main()
{
    int cases,caseno=1;
    SI(cases);
    int query;
    while(cases--){
        SI(N);SI(query);
        rep_1(i,N+1)SI(arr[i]);
        printf("Case %d:\n",caseno++);
        while(query--){
            mem(dp,-1);
            SI(D);SI(M);
            printf("%lld\n",rec(N, M, 0));
        }
    }
    return 0;
}

