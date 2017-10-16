#include<bits/stdc++.h>
using namespace std ;
int dp[50000+5] ;
vector<int>g[50000+5] ;
int vis[50000+5] ;
int cnt = 0 ;
void updateLoop( int node , int root , bool f ) {
  if( node == root && f )return ;
  for( int i = 0; i < (int) g[node].size() ; i++ ) {
    int v= g[node][i] ;
    cnt ++ ;
    updateLoop(v,root,1) ;
  }
  dp[node] = cnt ;
  return ;
}

int dfs( int node ) {
  if( g[node].size() == 0 )return 0 ;
  if( dp[node] != -1 )return dp[node] ;
  int ret = 0;
  vis[node] = 1 ;
  for( int i = 0 ; i < (int) g[node].size() ; i++ ) {
    int v = g[node][i] ;
    if( vis[v] == 0 ) {
      ret = max( ret , dfs(v)+1 );
    } else if( vis[v] ) {
      if( dp[v] == -1 ) {
        cnt = 0 ;
        updateLoop( v , v , 0 ) ;
      } else ret = max( ret , dp[v]+1 );
    }
  }
  if( dp[node]==-1 )return dp[node]=ret ;
  else return dp[node] ;
}

int main() {

  int cases , caseno = 1  ;
  scanf("%d",&cases ) ;

  while( cases -- ) {

    int  n ;
    scanf("%d",&n) ;

    for( int i = 0; i < n ; i++ ) {
      int u , v ;
      scanf("%d%d",&u,&v) ;
      g[u].push_back(v) ;
    }
    memset(vis , 0 , sizeof vis ) ;
    memset(dp , -1 , sizeof dp ) ;
    int mx , idx  ;
    for( int i = 1 ; i <= n ; i++ ) {
      if( i == 1 )mx = dfs(i) , idx = 1  ;
      else {
        int tmp = dfs(i) ;
        if( tmp > mx ) {
          mx = tmp ;
          idx = i ;
        }
      }
      //cout << "-->" << i <<" - " << dfs(i) << endl ;
    }
    cout << "Case " << caseno++ << ": " << idx << "\n" ;

    for( int i = 0 ; i <= n ; i++ ) {
      g[i].clear() ;
    }

  }

  return 0 ;
}