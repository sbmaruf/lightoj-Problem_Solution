#include<bits/stdc++.h>
using namespace std ;
int n , m , u , v ;
int dp[(1<<15)+2]  ;
bool prevMask[15+1][(1<<15)+1] , vis[(1<<15)+1] ;
vector<int>g[15+1] ;

void dfs( int node , int mask ) {
  prevMask[node][mask] = 1 ;
  vis[mask] = 1 ;
  for( int i = 0; i < (int)g[node].size() ; i++ ) {
    int v = g[node][i] ;
    if( !prevMask[v][mask|(1<<v)] ) {
      dfs( v,mask|(1<<v) ) ;
    }
  }
  return ;
}

int rec( int mask ) {
  if( mask == 0 ) return 0 ;
  if( dp[mask] != -1 ) return dp[mask] ;
  int ret = 1<<28 ;
  for( int i = mask ; i > 0 ; i= (mask)&(i-1) ) {
    if( vis[i] ) {
      ret = min( ret , rec(mask^i)+1 ) ;
    }
  }
  return dp[mask] = ret ;
}

int main() {

  int cases , caseno =1 ;
  scanf("%d",&cases ) ;

  while( cases -- ) {
    scanf("%d%d",&n,&m) ;
    for( int i = 0 ; i< m ; i++ ) {
      scanf("%d%d",&u,&v) ;
      u--;
      v-- ;
      g[u].push_back(v) ;
    }
    memset( prevMask , 0 , sizeof prevMask ) ;
    memset( vis , 0 , sizeof vis ) ;
    memset( dp , -1 , sizeof dp ) ;
    for( int i = 0 ; i < n ; i++ ) {
      dfs( i , 1<<i ) ;
    }
    cout << "Case " << caseno++ << ": " << rec( (1<<n)-1 ) << "\n" ;
    for(int i = 0; i < 15 ; i++ )g[i].clear() ;
  }


  return 0 ;
}

/*

2

3 2
1 2
2 3

6 6
1 2
2 3
2 4
5 4
4 6
4 2

*/

