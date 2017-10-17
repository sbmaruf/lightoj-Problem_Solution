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

int tree[1000000] ;
int n ;
inline void update( int idx , int val )
{
    while( idx<= n ) {
        tree[idx] += val ;
        idx += ( idx & -idx );
    }
}

inline int read( int idx )
{
    int sum = 0 ;
    while( idx > 0 ) {
        sum += tree[idx] ;
        idx -= ( idx & -idx ) ;
    }
    return sum ;
}
//int readInt () {
//  bool minus = false;
//  int result = 0;
//  char ch;
//  ch = getchar();
//  while (true) {
//      if (ch == '-') break;
//      if (ch >= '0' && ch <= '9') break;
//      ch = getchar();
//  }
//  if (ch == '-') minus = true; else result = ch-'0';
//  while (true) {
//      ch = getchar();
//      if (ch < '0' || ch > '9') break;
//      result = result*10 + (ch - '0');
//  }
//  if (minus)
//      return -result;
//  else
//      return result;
//}
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

    int cases ,caseno =1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases -- ){
        //printf("Case %d:\n",caseno++) ;
        //getchar() ;
        cout << "Case "<<caseno++<<":\n";
        char s[1000000] ;
        //gets( s ) ;
        scanf("%s",s) ;
        n = 0 ; ;
        for( int i = 0 ; s[i] ; i++ ){
            tree[i+1] = 0 ;
            n++ ;
        }
        int query ;
        //scanf("%d",&query) ;
        query = readInt() ;
        while( query-- ){
            char ch ;
            int a , b ;
            //getchar() ;
            ch = getchar() ;
            if( ch == 73 ){
                //scanf("%d%d",&a,&b);
                a = readInt() ;
                b = readInt() ;
                update( a , 1 ) ;
                update( b+1 , -1 ) ;
            }else {
                //scanf("%d",&a);
                a = readInt() ;
                int p = read( a ) ;
                p += (s[a-1]-48);
                if( p & 1 ){
                    //puts("1");
                    cout << "1\n" ;
                }else {
                    //puts("0");
                    cout << "0\n" ;
                }
            }
        }
    }


    return 0;
}
//2
//0011001100
//6
//I 1 10
//I 2 7
//Q 2
//Q 1
//Q 7
//Q 5
//1011110111
//6
//I 1 10
//I 2 7
//Q 2
//Q 1
//Q 7
//Q 5

