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
//int SET(int &num,int pos){ return num''=(1<<(pos));}
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

#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

int n , h ;
int dp[25+1][16*60+1] ;
int f[25+1] , d[25+1] , t[25+1] ;

int rec( int idx , int timeleft )
{
    if( timeleft <= 0 )return 0 ;
    if( idx == n ) return 0 ;
    if( dp[idx][timeleft] != -1 ) return dp[idx][timeleft] ;

    int ret = 0 , x = 0 ;

    for( int i = 0 , j = 0; i <= timeleft ; i+= 5, j++ ) {
        ret = max( ret , x+rec( idx+1 , timeleft-t[idx]*5-i)) ;
        if( (f[idx] - j*d[idx]) > 0 ) {
            x += (f[idx]-j*d[idx]);
        }
    }
    return dp[idx][timeleft] = ret ;
}

void Path_Print( int idx , int ans , int timeleft ){

    if(idx>=n)return ;
    if( ans == 0 ){
        if( idx != 0 ) cout << ", " ;
        cout << "0" ;
        Path_Print(idx+1,0,0) ;
        return ;
    }

    for( int i = timeleft ; i>= 0 ; i-= 5 ){

        int tmp = 0 ;

        for( int j = 0 ;(5*j)<i; j ++ ){
            if( f[idx] - j*d[idx]  > 0 ){
                tmp += f[idx]-j*d[idx] ;
            }
        }

        int fish  = rec( idx+1 , timeleft-i-t[idx]*5 ) ;
        if( tmp+fish == ans ){
            if( idx != 0  )cout << ", " ;
            cout << i ;
            Path_Print( idx+1 , ans - tmp , timeleft-i-t[idx]*5 ) ;
            return ;
        }
    }


}

int main()
{
    int cases , caseno = 1 ;
    Si( cases ) ;

    while( cases -- ) {

        SI( n ) ;
        SI( h ) ;

        rep( i , n )SI(f[i]) ;
        rep( i , n )SI(d[i]) ;
        rep( i , n-1 )SI(t[i]) ;
        t[n-1] = 0 ;

        mem( dp , -1 ) ;

        printf("Case %d:\n",caseno++ ) ;

        int ans = rec( 0 , (h*60) );
//        for( int i = 0 ; i < n ;  i++ ){
//            for( int j = 0 ; j <= h*60 ; j+=5 ){
//                cout << rec( i , j  ) << " " ;
//            }cout << endl ;
//        }
        Path_Print(0,ans,h*60);
        cout << "\n" ;
        printf("Number of fish expected: %d\n",ans) ;

    }

    return 0;
}

