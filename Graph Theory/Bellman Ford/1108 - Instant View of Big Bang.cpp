#include<bits/stdc++.h>
using namespace std ;
struct Tuple{
  int u,v,w ;
  Tuple( int _u ,int _v ,int _w ){
    u = _u , v = _v , w = _w ;
  }
};
vector< Tuple > node ;
vector< int > G[1005] ;
int N , M ;
int dist[1000+5] ;
bool mark[1000+5],vis[1005] ;
void dfs( int u ) {
  if( mark[u] ) return ;
  mark[u] = 1 ;
  for( int i = 0 ; i < G[u].size() ; i++ ){
    dfs( G[u][i] ) ;
  }
  return ;
}
void solve() {
  for( int i = 0 ;  i < 1000+5 ; i++ ) {
    dist[i] = 1<<28 ;
    mark[i] = 0 ;
    vis[i] = 0 ;
  }
  int u , v , w ;
  bool f = 0 ;
  dist[1001] = 0 ;
  for( int itr = 0 ; itr < N ; itr ++ ) {
    for( int i = 0 ; i < node.size() ; i++ ) {
      u = node[i].u ;
      v = node[i].v ;
      w = node[i].w ;
      if( dist[u]+w < dist[v] ) {
        dist[v] = dist[u]+w;
        if( itr+1 == N ) {
          //cout << " = " << u << endl ;
          dfs(u) ;
          f = 1 ;
        }
      }
      //cout <<"u , v " <<  u << " " << v << " " << dist[u] << " " << dist[v] << endl ;
    }
    //cout << dist[0] << " " << dist[1] << " " << dist[2] << " " << dist[3] << " " << dist[4] << " " << dist[1001] <<  endl ;
  }
  for( int i = 0 ; i <= 1000 ; i++ ) {
    if( mark[i] ) cout << " " << i ;
  }
  if( f == 0 )
    cout << " impossible";
  cout << "\n" ;
  return ;
}

int main() {
  ios_base::sync_with_stdio(0) ;
  cin.tie() ;

  int cases , caseno = 1 ;
  cin >> cases ;
  while(cases -- ) {
    node.clear() ;
    for( int i = 0 ; i < 1005 ; i++ ){
      G[i].clear() ;
    }
    cin >> N >> M ;
    for( int i = 0 ; i < M ; i++ ) {
      int u , v , w ;
      cin >> u >> v >> w ;
      G[v].push_back( u ) ;
      node.push_back( Tuple(v,u,w) ) ;
      if( !vis[u] ){
        vis[u] = 1 ;
        node.push_back( Tuple(1001,u,0) ) ;
      }
      if( !vis[v] ){
        vis[v] = 1 ;
        node.push_back( Tuple(1001,v,0) ) ;
      }
    }
    cout << "Case " << caseno ++ << ":";
    N++ ;
    solve() ;
  }
  return 0 ;
}


/*

reverse graph do not affect cycle.
a-->b-->c-->a
a<--b<--c<--a

at each iteration of bellmanford,
    given graph == flow out from cycle to other nodes(nodes that are not in the cycle)
    can't detect as in this way, other nodes(nodes that are not in the cycle) can be updated.
    reverse graph == may be flow in to the cycle. No way to update the nodes that are not in the cycle.

1
5 5
0 1 10
1 2 -100
3 1 -100
4 3 -100
3 4 -100


*/
