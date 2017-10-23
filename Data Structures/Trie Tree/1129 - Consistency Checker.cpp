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
struct Trie{
    bool endmark ;
    Trie * node[10] ;
    Trie(){
        endmark = false ;
        for( int i = 0 ; i < 10 ; i++ ){
            node[i] = NULL ;
        }
    }
}*root ;
bool FLAG;


void Insert( string str ){

    Trie *curr = root ;
    int p = 0 ;
    for( int i = 0 ; str[i] ; i++ ){
        int id = str[i] - '0' ;
        if( curr->node[id] == NULL ){
            curr->node[id] = new Trie() ;
            p = 1 ;
        }
        curr= curr->node[id] ;
    }
    if( p == 0 )FLAG = 1 ;
    curr->endmark = true ;
}
void del( Trie *cur ){
    for( int i =0 ; i < 10 ; i++ ){
        if( cur ->node[i] ){
            del( cur->node[i] ) ;
            delete( cur->node[i] ) ;
        }
        cur->endmark = false ;
    }
}
int main()
{
    int cases,caseno=1 ;
    SI( cases ) ;

    while( cases -- ){
        root = new Trie() ;
        int p ;
        SI( p ) ;
        FLAG = 0 ;
        vector<string>str ;
        for( int i = 0 ;i < p  ;i++ ){
            string s ;
            cin >> s ;
            str.push_back(s) ;
        }
        sort( ALL( str ) , greater<string>() ) ;
        for( int i = 0 ; i < p ; i++ ){
            if( !FLAG )Insert( str[i] ) ;
        }

        if( FLAG ){
            printf("Case %d: NO\n",caseno++ ) ;
        }else{
            printf("Case %d: YES\n",caseno++ ) ;
        }
        del( root ) ;

    }

    return 0;
}

