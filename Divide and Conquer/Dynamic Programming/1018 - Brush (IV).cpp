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

struct Pair {
    int x , y ;
};

Pair P[16+1] ;
int Mask[16+1][16+1];
int N ;
int dp[1<<16+1];

Pair TanOfLine( Pair a , Pair b )
{

    const int INF = 1<<30 ;
    Pair M ;

    if( a.y == b.y ) {
        M.x = INF ;
        M.y = INF ;
    } else {
        M.x = a.x-b.x ;
        M.y = a.y-b.y ;
        int tmp = __gcd( (M.x),(M.y) ) ;
        M.x = M.x/tmp ;
        M.y = M.y/tmp ;
    }
    return M ;
}

bool OnLine(Pair a , Pair b , Pair p )
{

    Pair tan1 = TanOfLine( a , b ) ;
    Pair tan2 = TanOfLine( a , p ) ;
    //Pair tan3 = TanOfLine( b , p ) ;
    if( tan1.x == tan2.x && tan1.y == tan2.y /*&& tan1.x == tan3.x && tan1.y == tan3.y*/ ) {
        return true ;
    } else return false ;

}

void precalc()
{
    for(int i = 0 ; i < N ; i++ ) {
        for( int j = i ; j < N ; j++ ) {
            Mask[i][j] |= (1<<i) ;
            Mask[i][j] |= (1<<j) ;
            for( int k = 0 ; k < N ; k++ ) {
                if( OnLine(P[i],P[j],P[k]) ) {
                    Mask[i][j] |= (1<<k) ;
                }
            }
        }
    }
}

void PRINT( int a )
{
    for( int i = 31 ; i>=0; i--) {
        if( (a&(1<<i))==0 )cout << "0 " ;
        else cout << "1 " ;
    }
    cout << endl ;
}

int rec(int bitfield)
{
    //PRINT( bitfield ) ;
    if( bitfield == ((1<<N)-1) ) return 0 ;
    else if( dp[bitfield] != -1 )return dp[bitfield] ;

    int ret = 1<<30 ;
    for( int i = 0 ; i < N ; i++ ) {
        if( ((bitfield)&(1<<i)) == 0 ) {
            for( int j = i ; j < N ; j++ ) {
                if( ((bitfield)&(1<<j)) == 0 ) {
                    //PRINT( bitfield ) ;
                    //PRINT( Mask[i][j] ) ;
                    ret = min( ret , rec( bitfield | Mask[i][j] )+1 ) ;
                }
            }
            break ;
        }
    }
    return dp[bitfield] = ret ;


}

int main()
{
    int cases , caseno =1   ;
    SI( cases ) ;

    while(cases -- ) {
        SI( N ) ;
        rep( i , N ) {
            SI( P[i].x ) ;
            SI( P[i].y ) ;
        }
        precalc();
        mem( dp , -1 ) ;
        printf("Case %d: %d\n",caseno++,rec(0)) ;
        mem(Mask,0) ;
    }

    return 0;
}

