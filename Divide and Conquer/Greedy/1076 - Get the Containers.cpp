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
int arr[1001];
int n , m ;
bool ok( int mid ) {
    int j = 0 ;
    for( int i = 0 ; i < m ; i++ ){
            int temp = mid ;
            for( j = j ; j < n ; j++ ){
                temp -= arr[ j ] ;
                if( temp < 0 ){
                        temp += arr[ j ] ;
                        //j-- ;
                        break ;
                }
            }
            if( j == n )break ;
    }
    if( j == n ) return true ;
    else return false ;
}
int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases-- ){

        SI( n ) ;
        SI( m ) ;

        int cap = 0 ;
        rep( i , n ) SI( arr[i] ) , cap += arr[i] ;
        int l = 0 ;
        int r = cap+1 ;
        while( r - l >= 5 ){
            int mid = ( l + r ) / 2 ;
            if( ok( mid ) ) r = mid ;
            else l = mid + 1 ;
        }
        for( int i = l ; i <= r ; i++ ){
            if( ok( i ) ){
                printf("Case %d: %d\n",caseno++,i) ;
                break ;
            }
        }

    }

    return 0;
}

