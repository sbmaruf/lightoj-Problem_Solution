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

struct node{

    int tot ;
    node *next[4] ;
    node(){
        tot = 0 ;
        rep( i , 4 ){
            next[i] = NULL ;
        }
    }

}*root;

char str[55] ;
i64 MAX ;

void insert(){
    node * curr = root ;

    for( int i = 1 ; str[i] ; i++ ){

        int id ;
        if( str[i] == 'A' ){
            id = 0 ;
        }else if( str[i] == 'C' ){
            id = 1 ;
        }else if( str[i] == 'G' ){
            id = 2 ;
        }else if( str[i] == 'T' ){
            id = 3 ;
        }

        if( curr->next[id] == NULL ){
            curr->next[id] = new node() ;
        }
        curr = curr->next[id] ;
        curr->tot ++ ;
        i64 p =  i*curr->tot ;
        if( p > MAX ) MAX = p ;
    }
}
int main()
{
    //read ;
    int cases , caseno = 1 ;
    SI( cases ) ;

    while( cases-- ){

        root = new node() ;
        MAX = -1 ;

        int n ;
        SI( n ) ;
        getchar() ;

        rep( i, n ){
            gets( str+1 ) ;
            insert() ;
        }

        printf("Case %d: %lld\n",caseno++ , MAX) ;
    }

    return 0;
}

