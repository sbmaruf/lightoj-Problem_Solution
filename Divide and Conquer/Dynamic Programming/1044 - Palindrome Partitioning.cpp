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

string s ;
int pre[1000+1][1000+1] ;

void func(int interval )
{
    for( int i = 0 ; i < s.size()-interval+1 ; i++ ) {
        if( pre[i+1][i+interval-2]==1 && s[i] == s[i+interval-1] ) {
            pre[i][i+interval-1] = 1 ;
        }
    }
}

void precalc()
{
    for( int i = 0 ; i <s.size() ; i++ ) {
        for( int j = 0 ; j < s.size() ; j++ ) {
            pre[i][j] = 0 ;
        }
    }

    for( int i = 0 ; i < s.size() ; i++ ) {
        pre[i][i] = 1 ;
    }

    for( int i = 0 ; i < s.size()-1 ; i++ ) {
        if( s[i] == s[i+1] ) {
            pre[i][i+1] = 1 ;
        }
    }

    for( int i = 0 ; i < s.size()-2 ; i++ ) {
        if( s[i]==s[i+2] ) {
            pre[i][i+2] = 1 ;
        }
    }

    for( int i = 4 ; i <= s.size() ; i++ ) {
        func(i) ;
    }
}

int dp[1000+1] ;

int rec( int partition )
{

    if( dp[partition] != -1 )return dp[partition] ;
    if( pre[partition][s.size()-1] == 1 )return 1 ;

    int mn = 1<<30 ;
    for( int i = partition+1 ; i< s.size() ; i++ ){
        if( pre[partition][i-1] == 1 ){
//            cout << partition << " " << i << endl ;
//            getchar();getchar() ;
            mn = min(mn , 1 + rec( i )) ;
        }
    }
    return dp[partition] = mn ;

}
int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;

    while( cases -- ) {

        cin >> s ;
        precalc();
        for( int i = 0 ; i <= s.size() ; i++ ){
            dp[i] = -1 ;
        }
        printf("Case %d: %d\n",caseno++ , rec(0)) ;

    }
    return 0;
}

