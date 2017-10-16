
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
int posarr[30+1][30+1] ;
int negarr[30+1][30+1] ;
int sol[30+1] ;
int per[30+1] ;
int sim[30+1] ;
int main()
{
    int cases , casesno = 1 ;
    SI( cases ) ;
    while( cases -- ){

        int n , m , k ;
        SI( n ) ;
        SI( m ) ;
        SI( k ) ;

        rep_1( i , n + 1 ){
            rep_1( j , m+1 ) {
                posarr[i][j] = 0 ;
                negarr[i][j] = 0 ;
            }
        }

        int p ;
        int flg = 0 ;
        rep_1( i , n+1 ){
            rep( j , k ) {
                SI( p ) ;
                if( p >=0 ) posarr[i][p] = 1 ;
                else negarr[i][-p] = 1 ;
            }
            sol[i] = 0  ;
        }


        rep_1( i , m+1)
            sim[i] = 0 ;

        int q ;
        SI( p ) ;
        rep( i , p ){
            SI( q ) ;
            sim[q] = 1 ;
        }

//        cout << endl << endl ;
//        rep_1( i , n + 1 ){
//            rep_1( j , m+1 ) {
//                cout << posarr[i][j] << " " ;
//
//            }
//            cout << endl ;
//        }cout << endl << endl ;
//
//                cout << endl << endl ;
//        rep_1( i , n + 1 ){
//            rep_1( j , m+1 ) {
//                cout << negarr[i][j] << " " ;
//
//            }
//            cout << endl ;
//        }cout << endl << endl ;
//

        rep_1( i , m+1 ){
            if( sim[i] == 1 ){
                rep_1 ( j , n+1 ){
                    if( posarr[j][i] == 1 )sol[j] = 1 ;
                }
            }
            else{
                rep_1( j , n+1 ){
                    if( negarr[j][i] == 1 ) sol[j] = 1 ;
                }
            }
        }

        int flag = 0 ;
        rep_1( i, n+1 ){
            if( sol[i] == 0 )flag = 1 ;
        }
        if( !flag )printf("Case %d: Yes\n",casesno++);
        else printf("Case %d: No\n",casesno++);

    }


    return 0;
}
