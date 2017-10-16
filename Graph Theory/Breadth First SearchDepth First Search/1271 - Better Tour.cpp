#include<bits/stdc++.h>
using namespace std ;
struct node {
    int u , w ;
    node() {}
    node(int _u , int _w) {
        u = _u ;
        w = _w ;
    }
};
vector<int>G[50000+1] ;
int par[50000+1] ;
int D[50000+1] ;

void pre(){
    for( int i = 0; i < 50001 ; i++ )D[i] = 1<<30 ;
}
void bfs( int source ){

    memset( par ,-1 , sizeof par ) ;
    pre();
    queue<node> Q ;
    Q.push( node(source,0) ) ;
    D[source] = 0  ;

    while( !Q.empty() ){
        node u = Q.front() ;
        Q.pop() ;
        sort( G[u.u].begin() , G[u.u].end() ) ;
        for( int i = 0 ;i < G[u.u].size() ; i++ ){
            int v = G[u.u][i] ;
            if( u.w+1 < D[v] ){
                D[v] = u.w ;
                par[v] = u.u ;
                Q.push(node(v,D[v])) ;
            }
        }
    }
    return ;
}
int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {
        int n ;
        scanf("%d",&n) ;
        int tmp ;
        int source , dest;
        for( int i = 0 ; i < n ; i++ ) {
            int p ;
            scanf("%d",&p) ;
            if( i == 0 )tmp = p, source = p  ;
            else {
                G[tmp].push_back(p) ;
                G[p].push_back(tmp) ;
                tmp = p ;
                if( i == (n-1) )dest = p  ;
            }
        }
        bfs( source ) ;
        int arr[50000+1] ;
        int idx = 0 ;
        arr[idx++] = dest ;
        for( int i = dest ; i!= source ; i=par[i] ) {
            arr[idx++] = par[i];
        }
        cout << "Case " << caseno++ << ":\n" ;
        for( int i = idx-1 ; i>=0; i-- ) {
            if( i != idx-1 )cout << " " ;
            cout << arr[i] ;
        }cout << "\n" ;
        for( int i = 0 ; i  < 50000+1 ; i++ )G[i].clear() ;
    }

}
