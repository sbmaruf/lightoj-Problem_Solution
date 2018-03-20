#include<bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ;i < n; i ++ )
vector<int>G[55+55] ;
int source = 0 , sink = 105 ;
int par[55+55] ;
int dist[55+55] ;
int cap[55+55][55+55];
int cost[55+55][55+55];
int n ;
int N , K , g ;
void Insert(int u , int v , int w , int c ) {
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    cap[u][v] = c ;
    cap[v][u] = 0 ;
    cost[u][v] = w ;
    cost[v][u] = -w ;
}
void init() {
    for( int i = 0 ; i < 55+55 ; i++ ) {
        dist[i] = (1<<30) ;
        par[i] = -1 ;
    }
}
int run() {
    init() ;
    dist[source] = 0 ;
    for( int i = 0 ; i  < sink-1 ; i++ ) {
        bool f = 0 ;
        for( int i = 0 ; i  <= sink ; i++ ) {
            for( int j = G[i].size()-1 ; j >= 0 ; j-- ) {
                int u = i ;
                int v = G[i][j] ;
                if( dist[u] + cost[u][v] < dist[v] && cap[u][v] > 0 ) {
                    dist[v] = dist[u] + cost[u][v] ;
                    par[v] = u ;
                    f = 1 ;
                }
            }
        }
        if( !f )break ;
    }
    return dist[sink]!=(1<<30) ;
}
int min_cost_max_flow() {
    int global_flow = 0 ;
    int cnt = 0 ;
    while( run() ) {
        for(int i = sink ; i != source ; i = par[i] ) {
            cap[par[i]][i] -- ;
            cap[i][par[i]] ++ ;
            global_flow += cost[par[i]][i] ;
        }
        cnt ++ ;
    }
    if( cnt == N ) return global_flow ;
    else return (-(1<<30)) ;
}


int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        for( int i = 0 ; i < 55+55 ; i++ )G[i].clear() ;
        scanf("%d%d%d",&N,&K,&g) ;
        int A[N+1],B[N+1] ;
        for( int i = 1 ; i <= N ; i ++ ) {
            scanf("%d",&A[i]) ;
        }
        for( int i = 1 ; i <= N ; i++ ) {
            scanf("%d",&B[i]) ;
        }
        for(int i = 1 ; i <= N ; i++ ) {
            Insert( source , i , 0 , 1 ) ;
            Insert( i+50 , sink , 0 , 1 ) ;
            for( int j = 1  ; j <= N ; j++ ) {
                if( B[j] > A[i] ) {
                    int c = (B[j]-A[i]) ;
                    c = ( c - K )*( c - K ) ;
                    c = min( c , g ) ;
                    Insert( i , j+50 , c , 1 ) ;
                }
            }
        }
        int ans1 = min_cost_max_flow() ;
        cout << "Case " << caseno++ << ":" ;
        if( ans1 == (-(1<<30)) ) {
            cout << " impossible\n" ;
            continue ;
        }
        for( int i = 0 ; i < 55+55 ; i++ )G[i].clear() ;
        for(int i = 1 ; i <= N ; i++ ) {
            Insert( source , i , 0 , 1 ) ;
            Insert( i+50 , sink , 0 , 1 ) ;
            for( int j = 1  ; j <= N ; j++ ) {
                if( B[j] > A[i] ) {
                    int c = (B[j]-A[i]) ;
                    c = ( c - K )*( c - K ) ;
                    c = min( c , g ) ;
                    Insert( i , j+50 , -c , 1 ) ;
                }
            }
        }
        int ans2 = min_cost_max_flow()*(-1) ;
        for( int i = 0 ; i < 55+55 ; i++ )G[i].clear() ;
        if( ans2 == (-(1<<30)) ) {
            cout << " impossible\n" ;
            continue ;
        }
        cout << " " << ans1 << " " << ans2 << "\n";
    }
    return 0 ;
}

