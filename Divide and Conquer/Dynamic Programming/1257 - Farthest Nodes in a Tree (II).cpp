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
#define pi        pair<int,int>
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

vector< pi > G[30000+1] ;
int visited[30000+1] ;
int vis[30000+1] ;

pi bfs( int src ){

    mem( visited , -1 ) ;
    queue< int > Q ;
    Q.push( src ) ;
    visited[src] = 0 ;

    int MAX = numeric_limits<int>::min() ;
    int node = -1 ;

    while( !Q.empty() ){
        int temp = Q.front() ;
        Q.pop();
        for( int i = 0 ; i < G[temp].size() ; i++ ){

            int dest = G[temp][i].first ;
            if( visited[dest] == -1 ){
                visited[dest] = G[temp][i].second + visited[temp] ;
                Q.push( dest ) ;
                if( MAX < visited[dest] ){
                    MAX = visited[dest] ;
                    node = dest ;
                }
            }
        }
    }

    return make_pair(node,MAX) ;

}


void bfsans( int src ){

    mem( vis , -1 ) ;
    queue< int > Q ;
    Q.push( src ) ;
    vis[src] = 0 ;

    while( !Q.empty() ){
        int temp = Q.front() ;
        Q.pop();
        for( int i = 0 ; i < G[temp].size() ; i++ ){
            int dest = G[temp][i].first ;
            if( vis[dest] == -1 ){
                vis[dest] = G[temp][i].second + vis[temp] ;
                if( vis[dest] > visited[dest] )visited[dest] = vis[dest] ;
                Q.push( dest ) ;
            }
        }
    }

}
int main()
{
    int cases , caseno=1 ;
    SI( cases ) ;
    while( cases -- ){
        int n ;
        SI( n ) ;
        for( int i = 0 ;i < n-1 ; i++ ){
            int u , v , w ;
            SI( u ) ;
            SI( v ) ;
            Si( w ) ;
            G[u].pb( make_pair(v,w) ) ;
            G[v].pb( make_pair(u,w) ) ;
        }
        pi far = bfs(0) ;
        far = bfs( far.first ) ;
        bfsans( far.first ) ;

        printf("Case %d:\n",caseno++);
        rep( i , n ){
            printf("%d\n", visited[i] ) ;
        }

        rep( i , n )
            G[i].clear() ;


    }

    return 0;
}

