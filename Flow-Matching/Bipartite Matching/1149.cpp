#include<bits/stdc++.h>
using namespace std ;
#define MAX 205
int n , m , A[MAX/2] , B[MAX/2] , vis[MAX] ;
vector<int> G[MAX] ;
int _left[MAX] , _right[MAX] ;

bool dfs( int u ) {
  if( vis[u] )return false ;
  vis[u] = 1 ;
  for( int i = 0 ; i < G[u].size() ; i++ ) {
    int v = G[u][i] ;
    if( _right[v] == -1 ) {
      _right[v] = u ;
      _left[u] = v ;
      return true ;
    }
  }
  for( int i = 0 ; i < G[u].size() ; i++ ) {
    int v = G[u][i] ;
    if( dfs( _right[v] ) ) {
      _right[v] = u ;
      _left[u] = v ;
      return true ;
    }
  }
  return false ;
}

int BPM( int n ) {
  int ret = 0 ;
  bool done ;
  memset( _left , -1 , sizeof _left ) ;
  memset( _right , -1 , sizeof _right ) ;
  do {
    done = true ;
    memset( vis , 0 , sizeof vis ) ;
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


int main() {

  ios_base::sync_with_stdio(0) ;
  cin.tie(0) ;

  int cases , caseno = 1;
  cin >> cases ;
  while( cases -- ) {
    cin >> n ;
    for( int i = 0 ; i < n ; i++ ) {
      cin >> A[i] ;
    }
    cin >> m ;
    for( int i = 0 ; i < m ; i++ ) {
      cin >> B[i] ;
    }
    for( int i = 0 ; i < n ; i++ ) {
      for( int j = 0 ; j < m ; j++ ) {
        if( B[j] % A[i] == 0 ) {
          G[i].push_back(j+n) ;
          G[j+n].push_back(i) ;
        }
      }
    }
    cout << "Case " << caseno++ << ": " << (BPM(n+m)>>1) << "\n" ;
    for( int i = 0 ; i < MAX ; i++ ) {
      G[i].clear() ;
    }
  }

  return 0 ;
}

/*

2
4 2 3 4 5
4 6 7 8 9
3 100 200 300
1 150
matching is directional.
need to devide by 2 as from both side matching could be done.

*/
