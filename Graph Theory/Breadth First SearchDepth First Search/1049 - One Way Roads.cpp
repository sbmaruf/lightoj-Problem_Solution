#include<bits/stdc++.h>
using namespace std ;

vector<int>G[100+1] ;
bool vis[100+1] ;
int W[101][101] ;

int rec( int src ){

    vis[src] = 1 ;
    int t = 0;
    for( int i = 0 ; i < G[src].size() ; i++ ){
        if( !vis[G[src][i]] ){
            vis[G[src][i]] = 1 ;
            t += W[src][G[src][i]] + rec( G[src][i] ) ;
        }
    }
    return t ;
}

int main(){

    int cases , caseno = 1;
    scanf("%d",&cases ) ;

    while( cases -- ){

        int edge ;
        scanf("%d",&edge) ;
        for( int i = 0 ; i < edge ; i++ ){
            int u , v , w ;
            scanf("%d%d%d",&u,&v,&w) ;
            G[u].push_back( v ) ;
            G[v].push_back( u ) ;
            W[u][v] = 0 ;
            W[v][u] = w ;
            vis[i+1] = 0 ;
        }
        int st = 0 ;
        for( int i = 1 ; i <= edge ; i++ ){
            if( G[i].size() == 2 ){
                st = i ;
                break ;
            }
        }
        vis[ st ] = 1 ;
        int src = G[st][0] ;
        int ans1 = rec( src ) ;

        memset( vis , 0 , sizeof vis ) ;

        vis[ st ] = 1 ;
        src = G[st][1] ;
        int ans2 = rec( src );
        cout << "Case " << caseno++ << ": " << min( ans1+W[st][G[st][0]]+W[G[st][1]][st] , ans2+W[st][G[st][1]]+W[G[st][0]][st] ) << endl ;

        for( int i = 1 ; i <= edge ; i++ )G[i].clear() ;
    }




}
