/*
Author          :          Saiful Bari
LANG            :          C++
Problem No      :          Light Oj / UVA / SPOJ / LIVE Archive / Codeforces /
Problem Link    :

Learning        :           1.  acos(( sq(a) + sq(b) - sq(c) )/(2*a*b)) ;
                            2.  sqrt( s*(s-a)*(s-b)*(s-c) )
                            These laws could easily overflow.
                            That's why we can not solve this problem by
                            guessing radius.

                            TASK
------------------------------------------------------------

------------------------------------------------------------
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

double L , n , C , len ;

bool ok( double mid )
{
   double R = L / ( 2* sin(mid) ) ;
   double l = R*2*mid ;
   if( l<=len )return true ;
   else return false ;
}


int main()
{
    int cases , caseno = 1 ;
    Si( cases ) ;
    while( cases -- ) {

        SLF( L ) ;
        SLF( n ) ;
        SLF( C ) ;
        if( L == 0 ) {
            printf("Case %d: 0\n",caseno++ ) ;
            continue ;
        }
        len = ( 1.0 + n * C ) * L ;
        double left = 0 ;
        double right = PI/2 ;
        double mid ;
        for( int i = 0 ; i < 30 ; i++ ) {

            mid = ( left + right ) / 2.0 ;

            if( ok(mid) ) {
                left = mid ;

            } else {
                right = mid ;
            }
        }


        double R = L / ( 2* sin(mid) ) ;
        double s = ( R + R + L )/2.0 ;
        double temp = sqrt( s * (s-R) * (s-R) * (s-L)) ;
        temp = temp * 2 ;
        temp = temp / L ;
        double ans = R -  temp  ;
        printf("Case %d: %.10lf\n",caseno++ , ans+1e-10  ) ;


    }


    return 0;
}

