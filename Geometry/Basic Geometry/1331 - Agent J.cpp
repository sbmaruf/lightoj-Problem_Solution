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

int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;

    while( cases -- ){

        double a , b , c ;
        SLF( a ) ; SLF( b ) ; SLF( c ) ;
        double p = a + b ;
        double q = a + c ;
        double r = b + c ;

        double s = ( p + q + r ) / 2.0 ;
        double area = sqrt ( s * ( s - p ) * ( s - q ) * ( s - r ) ) ;

        double theta = acos((p*p + q*q - r*r)/( 2*p*q ) );
        double area_a = (( pi*a*a )/ ( 2*pi ))*theta ;

        theta = acos((q*q + r*r - p*p )/( 2*r*q ) );
        double area_c = (( pi*c*c )/ ( 2*pi ))*theta ;

        theta = acos(( p*p + r*r - q*q )/( 2*p*r ) );
        double area_b = (( pi*b*b )/ ( 2*pi ))*theta ;

        printf("Case %d: %.10lf\n",caseno++ , area - area_a - area_b - area_c ) ;


    }

    return 0;
}

