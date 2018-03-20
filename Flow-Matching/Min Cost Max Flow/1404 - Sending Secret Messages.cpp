#include<bits/stdc++.h>
using namespace std ;
#define MAX 50+5
int N , M , P ;
int dist[MAX] ;
pair<int,int> par[MAX] ;
struct edge {
    int  v , w ,c, idx ;
    edge() {}
    edge(  int _v , int _w ,int _c, int _idx) {
         v = _v , w = _w  , c = _c , idx = _idx ;
    }
};
vector<edge> G[MAX] ;
void Insert( int u , int v , int w , int c ) {
    G[u].push_back( edge( v , w , c , G[v].size() ) ) ;
    G[v].push_back( edge( u , -w , 0 , G[u].size()-1 ) ) ;
}
int source = 0 ;
int sink = MAX-1 ;

bool run(){
    fill( dist , dist + MAX , 1<<30 ) ;
    dist[source] = 0 ;
    while( 1 ) {
        bool f = 0 ;
        for( int i = 0 ;i <= sink ; i++ ){
            int u = i ;
            for(int j = G[i].size()-1 ; j >= 0 ; j-- ){
                int v = G[i][j].v ;
                int w = G[i][j].w ;
                int c = G[i][j].c ;
                if( dist[u]+w < dist[v] && c > 0 ){
                    par[v].first = i ;
                    par[v].second = j ;
                    f = 1 ;
                    dist[v] = dist[u]+w ;
                }
            }
        }
        if( !f )break ;
    }
    return dist[sink]!=(1<<30) ;
}

long long min_cost_max_flow() {
    long long global_flow = 0 ;
    int output = 0 ;
    while( run() ) {
        int mn = 1<<30 ;
        for( int i = sink ; i != source ; i = par[i].first ) {
            mn = min(mn , G[par[i].first][par[i].second].c ) ;
        }
        int tot = 0 ;
        for(int i = sink ; i != source ; i = par[i].first ) {
            G[par[i].first][par[i].second].c -= mn ;
            G[i][G[par[i].first][par[i].second].idx].c += mn ;
            tot += G[par[i].first][par[i].second].w ;
        }
        output += mn ;
        global_flow += ((long long)tot*(long long)mn) ;
    }
    return output==P ? global_flow : -(1<<30) ;
}

int main() {
    //freopen("in.txt","r",stdin) ;
    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        scanf("%d%d%d",&N,&M,&P) ;
        int u , v , w , c ;
        for( int i = 0 ; i < M ; i++ ) {
            scanf("%d%d%d%d" , &u,&v,&c,&w) ;
            Insert( u , v , w , c ) ;
            Insert( v , u , w , c ) ;
        }
        Insert( source , 1 , 0 , P ) ;
        Insert( N , sink , 0 , P ) ;
        long long ans = min_cost_max_flow() ;
        if( ans == (-(1<<30) ) )cout << "Case " << caseno++ << ": impossible\n" ;
        else cout << "Case " << caseno++ << ": " << ans << "\n" ;
        for( int i = 0; i < MAX; i ++ )G[i].clear() ;
    }
    return 0 ;
}

