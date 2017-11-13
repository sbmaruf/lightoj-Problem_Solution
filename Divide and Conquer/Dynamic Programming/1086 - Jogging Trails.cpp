#include<bits/stdc++.h>
using namespace std ;
int n , m , idx;
int g[16][16] ;
int dp[(1<<16)+1] ;
int degree[16] ;

int rec( int mask ) {
  if( mask == ((1<<(n+1))-1) ) {
    return 0 ;
  }
  if( dp[mask] != -1 ) {
    return dp[mask] ;
  }
  int ret = 1<<28;
  int vis[16][16] = {0} ;
  for( int i = 1 ; i <= n ; i++ ) {
    if( !(mask & ( 1<<i )) ) {
      for( int j = 1 ; j <= n ; j++ ) {
        if( !( mask&(1<<j) ) && i != j && !vis[i][j] ) {
          ret = min( ret , rec( mask|(1<<i)|(1<<j)) + g[i][j] ) ;
          vis[i][j] =1 ;
          vis[j][i] =1 ;
        }
      }
    }
  }
  return dp[mask] = ret ;
}

int main() {

  ios_base::sync_with_stdio(0) ;
  cin.tie() ;

  int cases , caseno =1 ;
  cin >> cases ;
  while( cases -- ) {

    for( int i = 0 ; i < 16 ; i++ ) {
      for( int j = 0; j < 16 ; j++ ) {
        g[i][j] = 1LL<<28 ;
      }
      g[i][i] = 0 ;
      degree[i]=0 ;
    }

    cin >> n >> m ;

    int u , v , w  , tot = 0 ;;
    for( int i = 0; i< m ; i++ ) {
      cin >> u >> v >> w ;
      if( g[u][v]>w ) {
        g[u][v] = w ;
        g[v][u] = w ;
      }
      tot += w ;
      degree[u]++;
      degree[v]++;
    }

    for( int k = 1 ; k <= n ; k++ ) {
      for( int i = 1 ; i <= n ; i++ ) {
        for( int j = 1 ; j<= n ; j++ ) {
          g[i][j] = min( g[i][j] , g[i][k]+g[k][j] ) ;
        }
      }
    }

    int mask = 1<<0  ;
    for( int i = 1 ; i <= n ; i++ ) {
      if( !(degree[i] &1 ) ) {
        mask = (mask | (1<<i));
      }
    }
    memset( dp , -1 , sizeof dp ) ;
    cout << "Case " << caseno++ << ": " << tot + rec( mask ) << "\n" ;

  }
  return 0 ;
}

