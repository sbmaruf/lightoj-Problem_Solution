/*
ID: prime.m2
TASK:
LANG: C++
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

//int dirR8[]= {0,-1,-1,-1,0,1,1,1};
//int dirC8[]= {1,1,0,-1,-1,-1,0,1};
//int dirR4[]= {0,-1,0,1};
//int dirC4[]= {1,0,-1,0};
//int dirR[]={-2,-1, 1, 2, 2,1,-1,-2};
//int dirC[]={-1,-2,-2,-1, 1,2, 2, 1};

int arr1[502][502] ;
int arr2[502][502] ;
int dp[502][502] ;

int rec( int i ,int j ){

    if( i < 1 || j < 1 ) return 0 ;
    if( dp[i][j] != -1 ) return dp[i][j] ;
    return dp[i][j] = max( rec( i-1 , j ) + arr1[i][j] , rec( i , j-1 )+arr2[i][j] ) ;

}


int main(){

    int cases , caseno =1 ;
    SI( cases ) ;
    while( cases -- ){

        int m , n ;
        SI( m ) ; SI( n ) ;

        for( int i = 1 ; i <= m ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                SI( arr1[i][j] ) ;
                arr1[i][j] += arr1[i][j-1];
                dp[i][j] = -1 ;
            }
        }

        for( int i = 1 ; i <= m ; i++ ){
            for( int j = 1 ; j <= n ; j++ ){
                SI( arr2[i][j] ) ;
                arr2[i][j] += arr2[i-1][j];
            }
        }
        rec( m , n ) ;
        printf("Case %d: %d\n",caseno++, dp[m][n] ) ;
    }



return 0;
}

