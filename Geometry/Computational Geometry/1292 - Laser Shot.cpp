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
pair<int,int> TanOfLine( pair<int,int> a , pair<int,int> b )
{

    const int INF = 1<<30 ;
    pair<int,int> M ;

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
pair<int,int>Tangents[700+1] ;
inline int readInt()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }

    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}

int main()
{

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        int n ;
        //scanf("%d",&n) ;
        n = readInt() ;
        pair<int,int>P[n];
        for( int i = 0 ; i < n ; i++ ){
            //scanf("%d%d",&P[i].x,&P[i].y) ;
            P[i].x = readInt() ;
            P[i].y = readInt() ;
        }
        cout << "Case " << caseno++ << ": " ;
        if( n == 1 || n == 2 ){
            cout << n << "\n" ;
            continue ;
        }
        int ans = 0 ; ;
        for( int i = 0 ; i < n ; i++ ){
            int idx = 0 ;
            for( int j = i+1 ; j < n ; j++ ){
                Tangents[idx++] = TanOfLine(P[i] , P[j]) ;
            }
            sort( Tangents , Tangents+idx ) ;
            int cnt ;
            for( int i = 1 ; i < idx ; i++ ){
                cnt = 2 ;
                while( Tangents[i].x == Tangents[i-1].x && Tangents[i].y == Tangents[i-1].y  ){
                    cnt ++ ;
                    i++ ;
                    if( i == idx )break ;
                }
                ans = max( cnt , ans ) ;
            }
        }
        cout << ans << "\n" ;

    }


    return 0;
}

