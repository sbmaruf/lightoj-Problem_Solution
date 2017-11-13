#include<bits/stdc++.h>
using namespace std ;
vector< pair<int,int> >g[105] ;
int dp[105][105] ;
int vis[105][105] ;
int n , k , gc ;

int rec( int nd , int childIdx , int parent , int cost ){
  if( childIdx >= g[nd].size() ){
    if( cost >= 0 )return 0 ;
    return 1<<28 ;
  }
  int v = g[nd][childIdx].first ;
  if( v == parent ) return rec( nd , childIdx+1 , parent , cost ) ;
  if( vis[v][cost] == gc ) return dp[v][cost] ;
  vis[v][cost] = gc ;
  int ret = 1+rec( nd , childIdx+1 , parent , cost )+rec( v , 0 , nd , k ) ;
  if( g[nd][childIdx].second <= cost ){
    int rem = cost - g[nd][childIdx].second ;
    for( int i = 0 ; i <= rem ; i++ ){
      ret = min( ret , rec( nd , childIdx+1 , parent , i ) + rec( v , 0 , nd , rem-i ) ) ;
    }
  }
  return dp[v][cost] = ret ;
}

int main(){

  int cases , caseno = 1 ;
  cin >> cases ;
  while( cases -- ){
    for( int i = 0 ; i < 101 ; i++ )g[i].clear();
    scanf("%d%d",&n,&k) ;
    for( int i = 0 ; i < n-1 ; i++ ){
      int u , v , w ;
      scanf("%d%d%d",&u,&v,&w) ;
      g[u].push_back(make_pair(v,w)) ;
      g[v].push_back(make_pair(u,w)) ;
    }
    gc++ ;
    cout << "Case " << caseno++ << ": " << rec( 1 , 0 , -1 , k )+1 << "\n" ;
  }
  return 0 ;
}
