#include<bits/stdc++.h>
using namespace std ;

int N ;
double  D ;
struct Quad {
    double x,y ;
    int n , m ;
    Quad() {}
    Quad( double _x , double _y , int _n , int _m ) {
        x = _x ;
        y = _y ;
        n = _n ;
        m = _m ;
    }
};
Quad arr[100+1];

vector<int>G[2*100+2] ;
int par[2*100+2] ;
int cost[2*100+2][2*100+2] , dist[2*100+2][2*100+2] ;

void insert( int u , int v  , int w ) {
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    cost[u][v] += w ;
    cost[v][u] = 0 ;
}


int run(int source , int sink ) {

    int vis[2*100+2] ;
    memset( vis , 0 , sizeof vis ) ;
    queue< pair<int,int> >Q ;
    Q.push( {source,1<<30} ) ;
    vis[source] = 1 ;

    while( !Q.empty() ) {
        int u = Q.front().first ;
        int mn = Q.front().second ;
        Q.pop() ;
        for( int j = 0 ; j < G[u].size() ; j++ ) {
            int v = G[u][j] ;
            if( vis[v] == 0 && dist[u][v] > 0 ) {
                vis[v] = 1;
                par[v] = u ;
                mn = min( mn , dist[u][v] ) ;
                if( v == sink ) return mn ;
                Q.push( {v,mn} ) ;
            }
        }
    }
    return 0 ;
}
int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {
        scanf("%d%lf",&N,&D) ;

        memset(cost,0,sizeof cost ) ;
        double x,y;
        int n,m ;
        int flow_output = 0 ;
        for( int i = 1 ; i <= N ; i++ ) {
            scanf("%lf%lf%d%d",&x,&y,&n,&m) ;
            arr[i] = Quad( x , y , n , m ) ;
            insert( 0 , i , n ) ;
            insert( i , N+i , m ) ;
            flow_output += n ;
        }
        D = D*D ;
        for( int i = 1 ; i <= N ; i++ ) {
            for( int j = 1 ; j <= N; j++ ) {
                if( i == j ) continue ;
                double d = (arr[i].x-arr[j].x)*(arr[i].x-arr[j].x)
                           + (arr[i].y-arr[j].y)*(arr[i].y-arr[j].y) ;
                if( d <= D ) {
                    insert( N+i, j , 1<<30 ) ;
                }
            }
        }
        bool f = 0 ;
        cout << "Case " << caseno++ << ":" ;
        for( int j = 1 ; j <= N ; j++ ) {
            int source = 0 ;
            int sink = j ;
            for( int i = 0 ; i <= 201 ; i++ ) {
                for( int k = 0 ; k <= 201 ; k++ ) {
                    dist[i][k] = cost[i][k] ;
                }
            }
            int global_ans = 0 ;
            int local_ans ;
            while( local_ans = run(source,sink)) {
                global_ans += local_ans ;
                for( int i = sink ; i!= source ; i= par[i] ) {
                    dist[par[i]][i] -= local_ans ;
                    dist[i][par[i]] += local_ans ;
                }
            }
            if( global_ans == flow_output )cout << " " << j-1 , f=1 ;
        }
        if( !f )cout << " -1\n" ;
        else cout << "\n" ;

        for( int i = 0 ; i < 202 ; i++ )G[i].clear() ;
    }


}

