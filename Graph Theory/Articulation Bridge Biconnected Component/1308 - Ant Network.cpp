#include<bits/stdc++.h>
using namespace std ;
#define MAX 200000+5

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
  int first ;
  unsigned long long second ;
  _pair() {};
  _pair(int _first,unsigned long long _second ) {
    first = _first ;
    second = _second ;
  }
};
vector<int>g[MAX] ;
int low[MAX] , vis[MAX] , desc[MAX] , isArtc[MAX] , _time ;
map<int,int> mp ;
void dfs( int u , int bc ) {
  vis[u] = 1 ;
  desc[u] = low[u] = ++_time ;
  int child = 0 ;
  for( int i = 0 ; i < (int)g[u].size()  ; i++ ) {
    int v = g[u][i] ;
    if( v == bc ) continue ;
    if( vis[v] )low[u] = min( low[u] , desc[v] ) ;
    else {
      child++ ;
      dfs(v,u) ;
      low[u] = min(low[u], low[v]);
      if(low[v] >= desc[u]) isArtc[u] = 1 ;
    }
  }
  if( bc == -1 ) {
    if( child >= 2 ) {
      isArtc[u] = 1 ;
    } else isArtc[u] = 0 ;
  }
  return ;
}

void calcArticulation(int n , int m) {
  memset( vis, 0 , sizeof vis ) ;
  memset( isArtc , 0 , sizeof isArtc ) ;
  _time = 0 ;
  dfs(0,-1) ;
}
bool f = 0 ;
unsigned long long mul = 0 ;
void dfsCnt( int u , int bc ) {
  vis[u] = 1;
  mul++ ;
  for( int i = 0 ; i < (int) g[u].size() ; i++ ) {
    int v = g[u][i] ;
    if( v == bc )continue ;
    if( isArtc[v] == 1 )mp[v]++ ;
    if( vis[v] == 0 && isArtc[v] == 0 ) {
      dfsCnt(v,u);
    }
  }
}

_pair solve(int n ,int m ) {

  calcArticulation(n,m) ;
  memset( vis , 0 , sizeof vis ) ;
  int first=0 ;
  unsigned long long second=1 ;

  for( int i = 0 ; i < n ; i++ ) {
    if( vis[i] == 0 && isArtc[i] == 0 ) {
      mp.clear() ;
      f = 0 ;
      mul = 0 ;
      dfsCnt(i,-1) ;
      if( mp.size() == 0 ) {
        first += 2 ;
        second *= ( mul * (mul-1) )/2 ;
      } else if( mp.size() == 1 ) {
        first ++ ;
        second = second * mul ;
      }
    }
  }
  return _pair(first,second) ;
}

int main() {

  int cases , caseno = 1 ;
  cases = readInt() ;
  while( cases -- ) {
    int n , m ;
    n = readInt() ;
    m = readInt() ;
    for( int i = 0 ; i < m ; i++ ) {
      int u , v ;
      u = readInt() ;
      v = readInt() ;
      g[u].push_back(v) ;
      g[v].push_back(u) ;
    }
    _pair ans = solve(n,m) ;
    cout << "Case " << caseno++ << ": " << ans.first << " "<< ans.second << "\n" ;
    for(int i = 0 ; i < MAX ; i++ ) {
      g[i].clear() ;
    }
  }
  return 0 ;
}
