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
int Set(int N,int pos){return N=N | (1<<pos);}
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

int r , c ;
struct Pair{
    int i , j ;
} ;
Pair arr[16] ;
int idx = 0 ;
Pair src ;
int dp[1<<15+1][15+2] ;
int rec( int mask , int last ){
    if( mask == ( (1<<idx) - 1) ){
        return max( abs( arr[last].i - src.i ) , abs( arr[last].j - src.j ) ) ;
    }
    if( dp[mask][last+1] != -1 )return dp[mask][last+1] ;
    int ret = 1<<30 ;
    int p = 0 ;
    for( int i = 0 ; i < idx; i ++ ){
        if( (mask & (1<<i)) == 0 ){
            if( mask == 0 ) p = max( abs( arr[i].i - src.i ) , abs( arr[i].j - src.j ) ) ;
            else {
                p= max( abs( arr[i].i - arr[last].i ) , abs(arr[i].j - arr[last].j) ) ;
            }
            ret = min ( ret , p+rec(mask|(1<<i) , i ) ) ;
        }
    }
    return dp[mask][last+1] = ret ;
}
//x....
//.....
//.....
//.....
//.....
int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;

    while( cases -- ){
        SI( r ) ;
        Si( c ) ;
        char ch ;
        mem( dp , -1 ) ;
        idx = 0 ;
        rep( i , r ){
            getchar();
            rep( j , c ){
                SC( ch ) ;
                if( ch == 'x' ){
                    src.i = i ;
                    src.j = j ;
                }else if( ch == 'g' ){
                    arr[idx].i = i ;
                    arr[idx++].j = j ;
                }
            }
            //getchar();
        }
        if( idx == 0 )printf("Case %d: 0\n",caseno++ ) ;
        else printf("Case %d: %d\n",caseno++ ,rec( 0 , -1 ) ) ;
    }

    return 0;
}

