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
int arr[10] ;
int l ;
int m , n  ;
int dp[100][100] ;

i64 rec( int i , int prev )
{

    if( i == l ) {
        return 1 ;
    }

    if( prev!= -1 && dp[i][prev] != -1 ) return dp[i][prev] ;

    i64 ret = 0 ;
    for( int k = 0 ; k < m ; k++ ) {
        if( prev == -1 ){
            ret += rec( i+1 , arr[k] );
        }
        else if( ( max( arr[k] , prev ) - min ( arr[k] , prev )) <= 2 ) {
            ret += rec( i+1 , arr[k] );
        }
    }
    return dp[i][prev] = ret;

}


int main()
{
    int cases , caseno =1 ;
    SI( cases ) ;
    while( cases -- ) {

        Si( m ) ;
        SI( n ) ;
        rep( i , m ) {
            SI( arr[i] ) ;
        }

        int k = arr[m-1] ;
        string number = "" ;

        for( int i = 0 ; i < n ; i++ ) {
            number += k+'0' ;
        }
        //cout << number << endl ;
        l = n ;

        rep( i , 100 ){
            rep( j , 100 ){
                dp[i][j] = -1 ;
            }
        }

        i64 ans = rec( 0 , -1 ) ;
        printf("Case %d: %lld\n",caseno++ , ans ) ;


    }

    return 0;
}

