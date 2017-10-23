/*
ID: prime.m2
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

#define MX 100001
int arr[ MX ] ;
int tree[ MX*3 ] ;
int n;

void init( int node , int b , int e ){

    if( b == e ){
        tree [ node ] = arr [ e ] ;
        return ;
    }

    int left = node * 2 ;
    int right = node * 2 + 1 ;
    int mid = ( b + e ) / 2 ;

    init ( left , b , mid ) ;
    init ( right , mid + 1 , e ) ;

    tree [ node ] = min ( tree [ left ] , tree [ right ] ) ;

}

int qry ( int node , int b , int e , int i , int j ){

    if( b > j || e < i ) return 2147483647 ;
    else if( b >= i && e <= j ) {
            return tree[ node ] ;
    }

    int left = node * 2 ;
    int right = node * 2 + 1 ;
    int mid = ( b + e ) / 2 ;

    return min( qry( left , b , mid , i , j ) , qry( right , mid+1 , e , i , j ) ) ;

}
int main()
{
    int cases , caseno = 1;
    SI( cases );
    while( cases-- ){
        SI(n);
        int query ;
        SI( query ) ;
        for( int i = 1 ; i<=n ; i++ ){
            SI( arr[i] ) ;
        }
        init( 1 , 1 , n ) ;
        //for( int i = 0 ; i < 20 ; i++ )cout << tree [ i ] << endl ;
        printf("Case %d:\n",caseno++);
        while( query-- ){
            int a , b ;
            SI( a ) ;
            SI( b ) ;
            printf( "%d\n", qry( 1 , 1 , n , a , b )) ;
        }
    }

    return 0;
}

