    //bismillahirrahmanirrahim
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
#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI vector<int>
#define VVI vector< VI >
#define VIit VI::iterator

#define pb(a) push_back(a)
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

#define check(num,pos) number&(1<<pos)
#define set(num,pos) num|=(1<<pos)
#define clear(num,pos) num&=~(1<<x)
#define toggle(num,pops) num^=(1<<pos)

using namespace std;

//int dirR8[]= {0,-1,-1,-1,0,1,1,1};
//int dirC8[]= {1,1,0,-1,-1,-1,0,1};
//int dirR4[]= {0,-1,0,1};
//int dirC4[]= {1,0,-1,0};
//int dirR[]={-2,-1, 1, 2, 2,1,-1,-2};
//int dirC[]={-1,-2,-2,-1, 1,2, 2, 1};

int row,col;
int dp[102][102][102];
int arr[102][102];

long long int rec(int i1,int j1,int i2,int j2){

    if(i1==row && i2==row && j1==col && j2==col)return arr[i1][j1];
    else if(i1==i2 && j1==j2)return 0;
    else if(i1>row || i2>row || j1>col || j2>col)return 0;
    else if(dp[i1][j1][i2]!=-1)return dp[i1][j1][i2];
    else {
        j2=i1+j1-i2;
        dp[i1][j1][i2]=max(max(rec(i1,j1+1,i2,j2+1)+arr[i1][j1]+arr[i2][j2],rec(i1,j1+1,i2+1,j2)+arr[i1][j1]+arr[i2][j2]),max(rec(i1+1,j1,i2,j2+1)+arr[i1][j1]+arr[i2][j2],rec(i1+1,j1,i2+1,j2)+arr[i1][j1]+arr[i2][j2]));
        return dp[i1][j1][i2];
    }

}

int main()
{
    int cases,caseno=1;
    SI(cases);
    while(cases--){
        SI(row);SI(col);
        rep_1(i,row+1)rep_1(j,col+1)SI(arr[i][j]);
        mem(dp,-1);
        printf("Case %d: %lld\n",caseno++,rec(1,2,2,1)+arr[1][1]);
    }

    return 0;
}

