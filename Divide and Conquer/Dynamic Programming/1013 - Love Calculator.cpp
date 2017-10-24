/*
Author          :          Saiful Bari
LANG            :          C++
Problem No      :          Light Oj / UVA / SPOJ / LIVE Archive / Codeforces /
Problem Link    :

Learning        :
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
#define eps        1e-11
#define sq(a)      ((a)*(a))

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//bool equalTo ( double a, double b ){
//    if ( abs ( a - b ) <= eps ) return true;
//    else return false;
//}
//bool notEqual ( double a, double b ){
//    if ( abs ( a - b ) > eps ) return true;
//    else return false;
//}
//bool lessThan ( double a, double b ){
//    if ( a + eps < b ) return true;
//    else return false;
//}
//bool lessThanEqual ( double a, double b ){
//    if ( a < b + eps ) return true;
//    else return false;
//}
//bool greaterThan ( double a, double b ){
//    if ( a > b + eps ) return true;
//    else return false;
//}
//bool greaterThanEqual ( double a, double b ){
//    if ( a + eps > b ) return true;
//    else return false;
//}

#define x          first
#define y          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

int dp[31][31];
string s2 , s1 ;
i64 dp2[31][31][61] ;
int ans1 ;

int Edited_LCS( int i , int j )
{

    if( i == s1.length() ) {
        return s2.length() - j  ;
    } else if( j == s2.length() ) {
        return s1.length() - i  ;
    }

    if( dp[i][j] != -1 )return dp[i][j] ;

    if( s1[i] == s2[j] )dp[i][j] = Edited_LCS( i+1 , j+1 ) + 1 ;
    else {
        int ret1 = Edited_LCS( i+1 , j ) ;
        int ret2 = Edited_LCS( i , j+1 ) ;
        dp[i][j] = min( ret1 , ret2 )+1 ;
    }
    return dp[i][j] ;
}
i64 rec( int i , int j , int k )
{
    if( k == ans1 ){
        if( s1.length() == i && s2.length() == j )return 1 ;
        else return 0 ;
    }

    if( i == s1.length() ) {
        return dp2[i][j][k] = rec( i , j+1 , k+1 ) ;
    } else if( j == s2.length() ) {
        return dp2[i][j][k] = rec( i+1 , j , k+1 ) ;
    }

    if( dp2[i][j][k] != -1 )return dp2[i][j][k] ;

    if( s1[i] == s2[j] )dp2[i][j][k] = rec( i+1 , j+1 , k+1 ) ;
    else {
        i64 ret1 = rec( i+1 , j , k+1 ) ;
        i64 ret2 = rec( i , j+1 , k+1 ) ;
        dp2[i][j][k] = ret1+ret2 ;
    }
    return dp2[i][j][k] ;
}

int main()
{
    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {
        cin >> s1 >> s2 ;
        mem( dp , -1 ) ;
        ans1 = Edited_LCS(0,0) ;
        mem( dp2 , -1 ) ;
        i64 ans2 = rec( 0 , 0 , 0 ) ;
        cout << "Case " << caseno++ << ": " << ans1 << " " << ans2 << "\n" ;
    }

               return 0;
}

