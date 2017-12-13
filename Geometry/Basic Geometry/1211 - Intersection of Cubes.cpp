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

        int n ;
        SI( n ) ;

        int ans1x = -1 , ans1y=-1 , ans1z=-1 , ans2x=1001 , ans2y=1001 , ans2z=1001 ;

        int x1,x2,y1,y2,z1,z2 ;

        rep( i , n ){

                SI( x1 ) ;SI( y1 ) ; SI( z1 ) ; SI( x2 ) ;SI( y2 ) ; SI( z2 ) ;

                ans1x = max ( x1 , ans1x ) ;
                ans2x = min ( x2 , ans2x ) ;

                ans1y = max ( y1 , ans1y ) ;
                ans2y = min ( y2 , ans2y ) ;

                ans1z = max ( z1 , ans1z ) ;
                ans2z = min ( z2 , ans2z ) ;

        }
        int volume = ( ans2x - ans1x )*( ans2y - ans1y )*( ans2z - ans1z ) ;
        printf("Case %d: %d\n",caseno++ , (volume)<0?0:volume ) ;


    }

    return 0;
}

