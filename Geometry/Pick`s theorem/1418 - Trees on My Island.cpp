#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI vector<int>
#define VVI vector< VI >
#define VIit VI::iterator
#define pi pair<int,int>
#define ui64 unsigned long long int
#define i64 long long int
#define pb(a) push_back(a)
#define mp make_pair


#define SI(a) scanf("%d",&a)
#define Si(a) scanf("%d",&a)
#define SU(a) scanf("%u",&a)
#define SHD(a) scanf("%hd",&a)
#define SHU(a) scanf("%hu",&a)
#define SLLD(a) scanf("%lld",&a)
#define SLLU(a) scanf("%llu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define PI acos(-1.0)
#define eps 1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi first
#define se second
#define bg begin()
#define en end()
#define ALL(x) (x).begin(), (x).end()
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x) (int)(x.size())
struct points {
    long long int x,y;
} point[10000+10];
template<class T>inline T ABS(T a)
{
    return (a>0)?a:-a;
}
long long int Gcd(long long int a,long long int b)
{
    return !b?a:Gcd(b,a%b);
}
int main()
{
    int t,n;
    scanf("%d",&t);
    for(int l=1; l<=t; l++) {
        scanf("%d",&n);
        for(int i=0; i<n; i++)scanf("%lld%lld",&point[i].x,&point[i].y);
        double left=0,right=0;
        long long int sum=0;
        for(int i=0; i<n; i++) {
            left+=point[i].x*point[(i+1)%n].y;
            right+=point[(i+1)%n].x*point[i].y;
            sum+=Gcd(ABS(point[i].x-point[(i+1)%n].x),ABS(point[i].y-point[(i+1)%n].y));
        }
        double area=ABS((left-right)/2.0);
        area =area + 1 - ((sum)/2.0);
        printf("Case %d: %lld\n",l,(long long int)(area));
    }
    return 0 ;
}


