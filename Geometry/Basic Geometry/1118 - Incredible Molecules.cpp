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
#define sq(x) ((x)*(x))
#define rad(x) ((x*PI)/180.0)

int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases -- ) {
        double x1 , y1 , r1 , x2 , y2 , r2 ;
        SLF( x1 ) ;
        SLF( y1 ) ;
        SLF( r1 ) ;
        SLF( x2 ) ;
        SLF( y2 ) ;
        SLF( r2 ) ;
        if( r1 < r2 ) {
            swap( r1 , r2 ) ;
            swap( x1,x2) ;
            swap( y1,y2) ;
        }
        double d = sqrt(sq(x1-x2) + sq(y1-y2)) ;
        if( (d >= (r1+r2)) ) {
            printf("Case %d: 0\n",caseno++ );
        } else if((d <= (r1-r2))) {
            printf("Case %d: %.10lf\n",caseno++,PI*sq(r2));
        } else {
            double thetal = acos((sq(d)+sq(r1)-sq(r2))/(2*d*r1)) ;
            double thetar = acos((sq(d)+sq(r2)-sq(r1))/(2*d*r2)) ;
// double area = (PI * sq(r1) *thetal) / 180.0 - .5 * r1 * sin (2*rad(thetal)) + (PI * sq(r2) *thetar) / 180.0 - .5 * r2 * sin (2*rad(thetar)) ;
            double s = ( r1+r2+d )/2.0 ;
            double quad = 2*sqrt(s*(s-r1)*(s-r2)*(s-d)) ;
            double area = ( (sq(r1)*thetal)+(sq(r2)*thetar) ) - quad ;

            printf("Case %d: %.10lf\n",caseno++ , area +1e-12) ;
        }
    }

    return 0 ;
}

