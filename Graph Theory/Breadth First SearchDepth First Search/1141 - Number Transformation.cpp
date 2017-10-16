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

#define MAX 1000000
bool status[MAX] ;
vector<int> prime ;
vector<int> factor[1000+1] ;
int s , t ;

void SOE(){

    int sqrtN = sqrt ( MAX ) ;
    for( int i = 3 ; i < sqrtN ; i+=2 ){
        if( status[i] == 0 ){
            for( int j = i*i ; j < MAX ; j+= i + i ){
                status[j] = 1 ;
            }
        }
    }

    prime.pb(2) ;
    for( int i =  3 ; i < MAX ; i+= 2 ){
        if( status[i] == 0 ) prime.pb(i);
    }

}

void primefactor( int n ){

    int p = n  ;

    int sqrtN = sqrt( n ) ;

    for( int i = 0 ; prime[i] <= sqrtN ; i++ ){
        if( n%prime[i] == 0 ){
            while( n%prime[i] == 0 ){
                n = n / prime[i] ;

            }
            factor[p].pb( prime[i] ) ;
        }
        sqrtN = sqrt( n ) ;
    }
    if( n > 1 ){
        if( p != n ) factor[p].pb( n ) ;
    }

}

int bfs( int a ){

    if( a == t ) return 0 ;
    int dp[1001] ;

    rep( i , 1001 ) dp [i] = 0 ;

    queue< pii > Q ;
    Q.push( mp(a,0) ) ;

    while( !Q.empty() ){

            pii temp = Q.front() ;
            Q.pop() ;

                for( int i = 0 ; i < factor[temp.first].size() ; i++ ){

                    pii curr ;
                    curr.first = temp.first + factor[temp.first][i]  ;
                    curr.second = temp.second + 1 ;

                    if( curr.first == t ) return curr.second ;
                    else if( curr.first > t ) break ;

                    if( !dp[curr.first] )Q.push( curr ) ;
                    dp[curr.first] = 1 ;
                }

    }

    return -1 ;

}

int main()
{

    SOE() ;
    rep( i , 1000+1 ){
        primefactor( i ) ;
    }

    int cases , casesno = 1 ;

    SI( cases ) ;
    while( cases -- ){

        SI( s ) ;
        SI( t ) ;

       printf("Case %d: %d\n",casesno++ , bfs(s) );


    }

    return 0;
}
