#include<bits/stdc++.h>
using namespace std ;
#define MAX 30100
#define LGMAX 16
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
int par[MAX], head[MAX], depth[MAX], nChild[MAX], heavyNd[MAX], mp[MAX] ;
int nEdge, bit_n, tree[MAX], genies[MAX]  ;
vector<int>g[MAX] ;

void update( int idx , int val) {
  for( int j = idx ; j<= bit_n ; j += (j & -j) ) {
    tree[j] += val ;
  }
}
int read( int idx ) {
  int ret = 0 ;
  for( int j = idx ; j ; j -= (j & -j ) ) {
    ret += tree[j] ;
  }
  return ret ;
}
int atPos( int a ) {
  a = mp[a] ;
  return read(a)-read(a-1) ;
}
int rangeSum( int a , int b ) {
  a = mp[a] , b = mp[b] ;
  return read(b)-read(a-1) ;
}

void dfs( int u , int bc , int _depth ) {
  par[u] = bc ;
  nChild[u] = 1 ;
  depth[u] = _depth ;
  int mx = 0 ;
  for( int i = 0 ; i < (int)g[u].size() ; i++ ) {
    int v = g[u][i] ;
    if( v != bc ) {
      dfs(v,u,_depth+1) ;
      nChild[u]+=nChild[v] ;
      if( nChild[v] > mx ) {
        heavyNd[u] = v ;
        mx = nChild[v] ;
      }
    }
  }
}

int query( int u , int v ) {
  int ans = 0 ;
  while( 1 ) {
    int uChain = head[u] , vChain = head[v] ;
    if( uChain == vChain ) {
      if( depth[u] < depth[v] )
        ans += rangeSum(u,v) ;
      else ans += rangeSum(v,u) ;
      break ;
    } else if( depth[uChain] < depth[vChain] ) {
      ans += rangeSum(vChain,v) ;
      v = par[vChain] ;
    } else {
      ans += rangeSum(uChain,u) ;
      u = par[uChain] ;
    }
  }
  return ans ;
}

void buildChain(int u , bool isChainHead ) {
  head[u] = isChainHead ? u : head[par[u]] ;
  mp[u] = ++bit_n ;
  if( heavyNd[u] != -1 ) {
    buildChain( heavyNd[u] , 0 ) ;
  }
  for( int i = 0 ; i < (int)g[u].size() ; i++ ) {
    int v = g[u][i] ;
    if( v == par[u] )continue ;
    if( v != heavyNd[u] ) {
      buildChain( v, 1 ) ;
    }
  }
}

void buildSum(int n) {
  for( int i = 0 ; i < n ; i++ ) {
    update(mp[i],genies[i]) ;
  }
}

void init(int n) {
  nEdge = 0 , bit_n = 0;
  for( int i = 0 ; i < n ; i++ )g[i].clear() ;
  memset( tree , 0 , sizeof tree ) ;
  memset( heavyNd , -1 , sizeof heavyNd ) ;
}

int main() {
  int cases = readInt() ;
  int caseno = 1 ;
  while( cases -- ) {
    int n = readInt() ;
    init(n) ;
    for( int i = 0 ; i < n ; i++ ) {
      genies[i] = readInt() ;
    }
    for( int i = 0 ; i < n-1 ; i++ ) {
      int u = readInt() ;
      int v = readInt() ;
      g[u].push_back(v) ;
      g[v].push_back(u) ;
    }
    dfs( 0 , -1 , 0 ) ;
    buildChain( 0 , 1 ) ;
    buildSum( n ) ;
    cout << "Case " << caseno++ << ":\n" ;
    int q = readInt() ;
    while( q -- ) {
      int t = readInt() ;
      int u = readInt() ;
      int v = readInt() ;
      if( t ) {
        update( mp[u] , v-atPos(u) ) ;
      } else {
        cout << query( u , v ) << "\n" ;
      }
    }
  }
  return 0 ;
}
