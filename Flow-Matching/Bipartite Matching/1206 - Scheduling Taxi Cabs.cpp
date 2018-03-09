#include<bits/stdc++.h>
using namespace std;
#define MAX 505
int M ;
char ch ;
int h,m,x1[MAX],_y1[MAX],x2[MAX],y2[MAX] ;
int st[MAX],en[MAX] ;
vector<int> g[MAX] ;
int _left[MAX], _right[MAX], vis[MAX] ;

bool dfs( int u ) {
  if( vis[u] )return false ;
  vis[u] = 1 ;
  for( int i = 0 ; i < g[u].size() ; i++ ) {
    int v = g[u][i] ;
    if( _right[v] == -1 ) {
      _right[v] = u ;
      _left[u] = v ;
      return true ;
    }
  }
  for( int i = 0 ; i < g[u].size() ; i++ ) {
    int v = g[u][i] ;
    if( dfs( _right[v] ) ) {
      _right[v] = u ;
      _left[u] = v ;
      return true ;
    }
  }
  return false ;
}
int bpm( int n ) {
  int ret = 0 ;
  bool done ;
  memset( _left, -1, sizeof _left ) ;
  memset( _right, -1, sizeof _right ) ;
  do {
    done = true ;
    memset( vis, 0, sizeof vis ) ;
    for( int i = 0 ; i < n ; i++ ) {
      if( _left[i] == -1 && dfs(i) ) {
        done = false ;
      }
    }
  } while( !done ) ;
  for(int i = 0 ; i < n ; i++ ) {
    ret += ( _left[i] != -1 ) ;
  }
  return ret ;
}

void addEgde(int i, int j) {
  g[i].push_back(j);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int cases, caseno = 1 ;
  cin >> cases ;
  while( cases -- ) {
    cin >> M ;
    for( int i = 0 ; i < M ; i++ ) {
      cin >> h >> ch >> m >> x1[i] >> _y1[i] >> x2[i] >> y2[i] ;
      st[i] = h*60+m ;
      en[i] = st[i] + abs(x1[i]-x2[i]) + abs(_y1[i]-y2[i]) ;
    }
    for( int i = 0 ; i < M ; i++ ) {
      for( int j = 0 ; j < M ; j++ ) {
        if( st[j] > en[i] + abs(x1[j]-x2[i]) + abs(_y1[j]-y2[i]) ) {
          //cout << j << " " << i << "\n" ;
          addEgde(i,j) ;
        }
      }
    }
    cout << "Case " << caseno++ << ": " << M-bpm(M) << "\n" ;
    for( int i = 0 ; i < M ; i++ )g[i].clear() ;
  }
  return 0;
}


