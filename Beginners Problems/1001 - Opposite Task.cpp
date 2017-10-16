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
#define rep(i,n) for(int i=0;i<n;i++)
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
using namespace std;

int dirR8[]= {0,-1,-1,-1,0,1,1,1};
int dirC8[]= {1,1,0,-1,-1,-1,0,1};
int dirR4[]= {0,-1,0,1};
int dirC4[]= {1,0,-1,0};
int dirR[]={-2,-1, 1, 2, 2,1,-1,-2};
int dirC[]={-1,-2,-2,-1, 1,2, 2, 1};

int cases,num;

int main()
{

    SI(cases);
    while(cases--)
    {
        SI(num);
        (num<11)?printf("0 %d\n",num):printf("10 %d\n",num-10);
    }
    return 0;
}

