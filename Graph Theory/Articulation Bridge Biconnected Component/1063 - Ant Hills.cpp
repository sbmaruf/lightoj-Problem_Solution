#include<bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ;i < n ; i++ )
int n , m , u , v ;
vector<int>G[10000+1] ;
bool vis[10000+1],AP[10000+1];
int dis[10000+1] , low[10000+1],par[10000+1] ;

void dfs( int u , int time ){
    vis[u] = 1 ;
    int child = 0 ;
    dis[u] = low[u] = time ;
    rep( i , G[u].size() ){
        int v = G[u][i] ;
        if( !vis[v] ){
            child++ ;
            par[v] = u ;
            dfs(v,time+1) ;
            low[u] = min(low[u],low[v]) ;
            if( par[u] == u && child>1 )AP[u] = true ;
            if( par[u] != u && low[v] >= dis[u] )AP[u] = true ;
        }else if( v!= par[u] ){
            low[u] = min(low[u],dis[v]) ;
        }
    }
}

int solve(){
    rep(i,n+1){
        vis[i] = 0 ;
        par[i] = i ;
        AP[i] = 0 ;
        dis[i] = -1 ;
        low[i] = -1 ;
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( vis[i] == 0 ){
            dfs( i , 0 );
        }
    }
    int cnt = 0 ;
    rep(i,n+1)if(AP[i])cnt ++ ;
    return cnt ;
}

int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ){
        scanf("%d%d",&n,&m) ;
        rep( i , m ){
            scanf("%d%d",&u,&v) ;
            G[u].push_back(v) ;
            G[v].push_back(u) ;
        }
        cout << "Case "<< caseno++ << ": " << solve() <<"\n" ;
        for( int i = 0 ;i <=n;i++ )G[i].clear() ;
    }
}
