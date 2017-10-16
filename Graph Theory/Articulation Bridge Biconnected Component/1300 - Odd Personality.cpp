
#include<bits/stdc++.h>
using namespace std ;
#define MAX 20000+5

inline int readInt() {
  int ip = getchar_unlocked(), ret = 0, flag = 1;
  for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
    if(ip == 45) {
      flag = -1;
      ip = getchar_unlocked();
      break;
    }
  }
  for(; ip > 47 && ip < 58; ip = getchar_unlocked())
    ret = ret * 10 + ip - 48 ;
  return flag * ret;
}

struct _pair {
  int first , second ;
  _pair() {}
  _pair(int _first , int _second ) {
    first = _first , second = _second ;
  }
};
vector<_pair>g[MAX] ;
int _time , low[MAX] , vis[MAX] , disc[MAX] , isBridge[MAX] , col[MAX] ;

void dfs( int u , int bc = -1 ) {
  vis[u] = 1;
  low[u]=disc[u]=++_time ;  ;
  for( int i = 0 ; i < (int)g[u].size() ; i++ ) {
    int v = g[u][i].first ;
    if( v == bc )continue ;
    if( vis[v] )low[u] = min( low[u] , disc[v] ) ;
    else {
      dfs( v , u ) ;
      low[u] = min( low[u] , low[v] ) ;
      if( low[v] > disc[u] ) {
        isBridge[g[u][i].second]=1;
        //cout << u << " = " << v << "\n" ;
      }
    }
  }
}

void calcBridge(int n) {
  memset(vis,0,sizeof vis ) ;
  memset(isBridge,0,sizeof isBridge) ;
  _time = 0 ;
  for(int i = 0 ; i < n ; i++ ) {
    if( vis[i] == 0 ) {
      dfs( i ) ;
    }
  }
}

int bfs( int src ) {
  queue<_pair>Q ;
  Q.push(_pair(src,0)) ;
  vis[src] = 1 ;
  col[src] = 0 ;
  int ret = 0 ;
  bool f = 0 ;
  while( !Q.empty() ) {
    int u = Q.front().first ;
    int color = Q.front().second ;
    Q.pop() ;
    ret ++ ;
    for(  int i = 0 ; i < (int)g[u].size() ; i++ ) {
      int v = g[u][i].first ;
      if( !isBridge[g[u][i].second] ) {
        int newColor = 1 - color;
        if( vis[v] == 0 ) {
          col[v] = newColor ;
          vis[v] = 1 ;
          Q.push(_pair(v,newColor)) ;
        } else if( col[v] == col[u] ) {
          f = 1 ;
        }
      }
    }
  }
  if( !f )ret = 0 ;
  return ret ;
}

int solve(int n ,int m ) {
  calcBridge(n) ;
  memset(vis,0,sizeof vis) ;
  memset(col,0,sizeof col) ;
  int ret = 0 ;
  //for( int i= 0 ; i < m ; i++ )cout << isBridge[i] << " " ;
  //cout << "\n" ;
  for( int i = 0 ; i < n ; i++ ) {
    if( vis[i] == 0 ) {
      ret += bfs(i) ;
    }
  }
  return ret ;
}

int main() {
  int cases , caseno = 1 ;
  //cin >> cases ;
  cases = readInt() ;
  while( cases -- ) {
    int n , m ;
    //cin >> n >> m ;
    n = readInt() ;
    m = readInt() ;
    for( int i = 0 ; i < m ; i++ ) {
      int u , v ;
      //cin >> u >> v ;
      u = readInt() ;
      v = readInt() ;
      g[u].push_back(_pair(v,i)) ;
      g[v].push_back(_pair(u,i)) ;
    }
    cout << "Case " << caseno++ << ": " << solve(n,m) << "\n" ;
    for( int i = 0 ; i < MAX ; i++ ) {
      g[i].clear() ;
    }
  }
  return 0 ;
}


/*
  bridge separates two connected component.
  in each component there is at least 2 path from a node to another node.
  non-bicolorable connected graph has a cycle of odd length.
*/
