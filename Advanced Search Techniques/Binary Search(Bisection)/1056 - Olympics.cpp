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
#define eps        1e-9
 
#define sq(a)      ((a)*(a))
 
//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }
 
#define x          first
#define y          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())
double len , wid ;
char ch ;
 
bool ok(double mid)
{
 
    double d = .5* sqrt ( sq(mid*len) + sq(mid*wid) ) ;
    double angle = acos( (sq(d)+sq(d) - sq(mid*wid))/(2*d*d)  );
    double peri1 = 2*d*angle ;
    double totperi = peri1+2*mid*len ;
    if( totperi>400.0 ) return 0;
    else return 1 ;
 
}
 
 
int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases -- ) {
        SLF( len ) ;
        SC( ch ) ;
        SC( ch ) ;
        SC( ch ) ;
        SLF( wid ) ;
        double left = 0 ;
        double right = 1000000000 ;
 
        for( int i = 0 ; i < 200 ; i++ ) {
 
            double mid = ( left + right )/2.0 ;
            if( ok(mid) ) {
                left = mid ;
            } else {
                right = mid ;
            }
 
        }
        double length = len * left ;
        double width = wid * left ;
       // printf("Case %d: %.8lf %.8lf\n",caseno++ , length , width ) ;
       printf("Case %d: ",caseno++ ) ;
       cout <<setprecision(15)<< length << " " << width << endl;
 
 
    }
 
 
    return 0;
}
 
