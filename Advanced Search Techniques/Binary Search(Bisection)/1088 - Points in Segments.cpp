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



int main()
{
    int cases , caseno =1 ;
    SI( cases ) ;
    while( cases -- ) {
        int n , q ;
        SI( n ) ;
        SI( q ) ;
        int arr[n+1] ;
        rep( i , n ) {
            SI( arr[i] ) ;
        }
        printf("Case %d:\n",caseno++) ;
        rep( i , q ) {
            int a , b ;
            SI( a ) ;
            SI( b ) ;
            int *ptr1 ;
            ptr1 = lower_bound( arr , arr + n, a ) ;
            int *ptr2 ;
            ptr2 = upper_bound( arr , arr+ n , b ) ;
            printf("%d\n",(ptr2-ptr1)) ;
        }

    }
    return 0 ;
}

