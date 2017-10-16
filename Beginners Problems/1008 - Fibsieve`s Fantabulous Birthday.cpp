
    //Bismillah-hir-Rah-manir-rahim
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
#define FOR(i,n,k) for(int i=0;i<n;i=i+k)

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
using namespace std;

int main()
{
    //read;
        int cases,caseno=1;
        SI(cases);
        while(cases--){
            long long int n;
            SLLD(n);
            long long int r = 1 + int(floor(sqrt(n-1)));
            long long int t = r*2 - 1;
            long long int first = 1 + ( r-1 ) + ( r-1 ) * ( r-2 );
            long long int last = 1 + ( r+1 - 1 ) + ( r+1 - 1) * ( r+1 - 2) - 1;
            long long pos = n - first + 1;
            if( r&1 ){
                long long int m = t/2 + 1;
                if(pos==m)printf("Case %d: %lld %lld\n",caseno++,m,m);
                else if(pos<m)printf("Case %d: %lld %lld\n",caseno++,r,pos);
                else {
                    printf("Case %d: %lld %lld\n",caseno++,t-pos+1,r);
                }
            }else{
                long long int m = t/2 + 1;
                if(pos==m)printf("Case %d: %lld %lld\n",caseno++,m,m);
                else if(pos<m)printf("Case %d: %lld %lld\n",caseno++,pos,r);
                else {
                    printf("Case %d: %lld %lld\n",caseno++,r,t-pos+1);
                }
            }


        }
    return 0;
}
