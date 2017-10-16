#include<bits/stdc++.h>
using namespace std ;
#define MAXNODE 8*1000*2+1
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

vector<int>g[MAXNODE] ;
vector<int>revg[MAXNODE] ;
vector<int>dag[MAXNODE], sol ;
int totNode, vis[MAXNODE] ;
int stk[MAXNODE], stkidx  ;
int nodeScc[MAXNODE], sccCnt = 0 ;
int n, m, _time ;

int node( int idx ) {
  return ( idx >= 0 )? idx : -idx+totNode ;
}

void topdfs( int u ) {
  vis[u] = 1 ;
  for( int i = 0 ; i < g[u].size() ; i++ ) {
    int v = g[u][i] ;
    if( vis[v] == 0 ) {
      topdfs(v) ;
    }
  }
  stk[stkidx++] = u ;
  return ;
}
void dfs( int u ) {
  vis[u] = 1 ;
  nodeScc[u] = sccCnt ;
  for( int i = 0 ; i < revg[u].size() ; i++ ) {
    int v = revg[u][i] ;
    if( vis[v] == 0 ) {
      dfs( v ) ;
    }
  }
  return ;
}
void input() {
  //cin >> n >> m ;
  n = readInt() ;
  m = readInt() ;
  totNode = m ;
  for( int i = 0 ; i < n ; i++ ) {
    int u, v ;
    //cin  >> u >> v ;
    u = readInt() ;
    v = readInt() ;
    g[node(-u)].push_back(node(v)) ;
    g[node(-v)].push_back(node(u)) ;
    revg[node(v)].push_back(node(-u)) ;
    revg[node(u)].push_back(node(-v)) ;
  }
  return ;
}
void scc() {
  for( int i = 1 ; i <= 2*m ; i++ ) {
    if( vis[i] == 0 ) {
      topdfs(i) ;
    }
  }
  memset( vis, 0, sizeof vis ) ;
  sccCnt = 0  ;
  for( int i = stkidx-1 ; i >= 0 ; i-- ) {
    int v = stk[i] ;
    if( vis[v] == 0 ) {
      sccCnt++ ;
      dfs( v ) ;
    }
  }
  return ;
}
void init() {
  stkidx = 0 ;
  for( int i = 1 ; i <= 2*m ; i++ ) {
    g[i].clear() ;
    revg[i].clear() ;
    vis[i] = 0 ;
    dag[i].clear() ;
  }
  return ;
}
bool Two_Sat() {
  bool isPossible = 1 ;
  int anscnt = 0 ;
  for( int i = 1 ; i <= m ; i++ ) {
    if( nodeScc[i] == nodeScc[node(-i)] ) {
      isPossible = 0 ;
      return false ;
    }
  }
  return true ;
}
void createDAG() {
  for( int i= 1 ; i <= 2*m ; i++ ) {
    for( int j = 0 ; j < g[i].size() ; j++ ) {
      int v = g[i][j] ;
      if( nodeScc[i] != nodeScc[v] ) {
        dag[nodeScc[i]].push_back(nodeScc[v]) ;
      }
    }
  }
  return ;
}

void path(int u ) {
  for( int i = 0 ; i < dag[u].size() ; i++ ) {
    int v = dag[u][i] ;
    if( vis[v] == 0 ) {
      vis[v] = ++_time ;
      path(v) ;
    }
  }
  vis[u] = ++_time ;
  return ;
}
void findSol() {
  _time = 1 ;
  sol.clear() ;
  memset( vis, 0, sizeof vis ) ;
  for( int i = 1 ; i <= sccCnt ; i++ ) {
    if( vis[i] == 0 ) {
      path(i) ;
    }
  }
  for( int i = 1 ; i <= m ; i++ ) {
    if( vis[nodeScc[i]] < vis[nodeScc[node(-i)]] ) {
      sol.push_back(i) ;
    }
  }
}
int main() {

  int cases, caseno = 1;
  //cin >> cases ;
  cases = readInt() ;
  while( cases -- ) {
    input();
    scc() ;
    cout << "Case " << caseno++ << ":" ;
    if( !Two_Sat() )cout << " No\n" ;
    else {
      cout << " Yes\n"   ;
      createDAG() ;
      memset( vis, 0, sizeof vis ) ;
      findSol() ;
      cout << sol.size()  ;
      for( int i = 0 ; i < sol.size() ; i++ ) {
        cout << " " << sol[i] ;
      }
      cout << "\n" ;
    }
    init() ;
  }


  return 0 ;
}

