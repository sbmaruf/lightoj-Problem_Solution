#include<bits/stdc++.h>
using namespace std ;
int n , k , m ;

char str[30][30] ;
int dirR[] = {0,0,1,-1} ;
int dirC[] = {1,-1,0,0} ;
int dist[30][30] ;
void bfs(int x , int y ) {
    for(int i = 0 ; i < n ; i++ ) {
        for( int j = 0 ; j < n ; j++ ) {
            dist[i][j] = (1<<30) ;
        }
    }
    queue<pair<int,int> > Q ;
    Q.push( make_pair(x,y) ) ;
    dist[x][y] = 0 ;
    while( !Q.empty() ) {
        pair<int,int> tmp = Q.front() ;
        Q.pop() ;
        for( int k = 0 ; k < 4 ; k++ ) {
            int R = tmp.first+dirR[k];
            int C = tmp.second+dirC[k];
            if( R >= 0 && C >= 0 && R < n && C < n && str[R][C] != '#' ) {
                if( dist[tmp.first][tmp.second] + 1 < dist[R][C] ){
                    dist[R][C] = dist[tmp.first][tmp.second] + 1 ;
                    Q.push(make_pair(R,C) );
                }
            }
        }
    }
}
#define MAX 900+5
vector<int>G[MAX] ;
int source = 902 , sink = 903 ;
int par[MAX] ;
int Dist[MAX] ;
int cap[MAX][MAX];
int cost[MAX][MAX];

void Insert(int u , int v , int w , int c ) {
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    cap[u][v] = c ;
    cap[v][u] = 0 ;
    cost[u][v] = w ;
    cost[v][u] = -w ;
}
void init() {
    for( int i = 0 ; i < MAX ; i++ ) {
        Dist[i] = (1<<30) ;
        par[i] = -1 ;
    }
    Dist[source] = 0 ;
}
int run() {
    init() ;
    for( int i = 0 ;i  < sink-1 ; i++ ){
        bool f = 0 ;
        for( int i = 0 ; i  <= sink ; i++ ) {
            for( int j = G[i].size()-1 ; j >= 0 ; j-- ) {
                int u = i ;
                int v = G[i][j] ;
                if( Dist[u] + cost[u][v] < Dist[v] && cap[u][v] > 0 ) {
                    Dist[v] = Dist[u] + cost[u][v] ;
                    par[v] = u ;
                    f = 1 ;
                }
            }
        }
        if( !f )break ;
    }
    return Dist[sink]!=(1<<30) ;
}

int min_cost_max_flow() {
    int global_flow = 0 ;
    while( run() ) {
        for(int i = sink ; i != source ; i = par[i] ) {
            cap[par[i]][i] -- ;
            cap[i][par[i]] ++ ;
            global_flow += cost[par[i]][i] ;
        }
    }
    return global_flow ;
}

int main() {

#ifdef kryptonyte
    freopen("in.txt","r",stdin) ;
#endif

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        scanf("%d%d%d",&n,&k,&m);
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%s",str[i] ) ;
        }
        int B[k] ;
        for( int i = 0 ; i < k ; i++ ) {
            scanf("%d",&B[i]) ;
        }
        vector<pair<char,pair<int,int> > >N ;
        vector<pair<int,int> > M ;
        for( int i = 0 ; i< n ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( str[i][j] >= 'A' && str[i][j] <= 'Z' ) {
                    N.push_back(make_pair(str[i][j],make_pair(i,j))) ;
                } else if( str[i][j] == 'm' ) {
                    M.push_back(make_pair(i,j));
                }
            }
        }

        for( int i = 0 ; i < N.size() ; i++ ) {
            bfs( N[i].second.first , N[i].second.second ) ;
            Insert( source , N[i].second.first*n+N[i].second.second , 0 , B[N[i].first-'A'] ) ;
            for( int j = 0 ; j < M.size() ; j++ ) {
                //cout << N[i].first << " = (" << (N[i].second.first) << "," << N[i].second.second << ")" << " dist (" << M[j].first << "," << M[j].second << ") " << dist[M[j].first][M[j].second] << "\n" ;
                if( dist[M[j].first][M[j].second] != (1<<30) ) {
                    Insert( N[i].second.first*n+N[i].second.second , M[j].first*n+M[j].second , dist[M[j].first][M[j].second] , 1 ) ;
                }
            }
        }

        for( int i = 0 ; i< M.size() ; i++ ){
            Insert( M[i].first*n+M[i].second , sink , 0 , 1 );
        }
        int ans = min_cost_max_flow() ;
        cout << "Case " << caseno++ << ": " << ans << "\n" ;
        for( int i = 0 ; i< MAX ; i++ )G[i].clear() ;

    }
    return 0 ;
}

