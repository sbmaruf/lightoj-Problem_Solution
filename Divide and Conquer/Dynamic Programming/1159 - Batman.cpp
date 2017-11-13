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

string s1 , s2 , s3 ;
int l1 , l2 , l3 ;
int dp[51][51][51] ;

int lcs(){

    rep( i , l1 )dp[0][0][i] = 0 ;
    rep( i , l2 )dp[0][i][0] = 0 ;
    rep( i , l3 )dp[i][0][0] = 0 ;

    rep_1( i , l1+1 ){
         rep_1( j , l2+1 ){
             rep_1( k , l3+1 ){
                 if( s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1] ){
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1 ;
                 }
                 else {
                    dp[i][j][k] =max( dp[i-1][j][k] , max ( dp[i][j-1][k]  , dp[i][j][k-1] ) );
                 }
             }
         }
    }
    return dp[l1][l2][l3] ;

}

int main()
{
    int cases , casesno = 1 ;
    SI( cases ) ;
    while( cases -- ){

        cin >> s1 >>s2 >> s3 ;

        l1 = s1.size() ;
        l2 = s2.size() ;
        l3 = s3.size() ;

        printf("Case %d: %d\n",casesno++ , lcs()) ;
    }

    return 0;
}

