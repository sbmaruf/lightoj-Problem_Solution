#include<bits/stdc++.h>
using namespace std ;
struct node {
  int v , c ;
  node() {}
  node( int _v , int _c ) {
    v = _v , c = _c ;
  }
  bool operator < ( const node & a )const {
    return c>a.c;
  }
};
int n , m , s , p ;
int u , v , w , src , dest , gc ;
vector<int>shops ;
vector<node>g[500+100] ;
int dist[500+100] , cost[20][20] ;

void dijkstra( int src ) {
  for( int i = 0 ; i < n ; i++ ) {
    dist[i] = 1<<28 ;
  }
  priority_queue<node>pq;
  pq.push(node(src,0)) ;
  dist[src] = 0 ;
  while( !pq.empty() ) {
    node u = pq.top() ;
    pq.pop();
    for( int i = 0 ; i < g[u.v].size() ; i++ ) {
      int v = g[u.v][i].v ;
      int w = g[u.v][i].c ;
      if( dist[u.v]+w < dist[v] ) {
        dist[v] = dist[u.v]+w ;
        pq.push(node(v,dist[v])) ;
      }
    }
  }
  return ;
}
int vis[18][(1<<17)+100] ;
pair<int,int> dp[18][(1<<17)+100] ;

pair<int,int> rec( int last , int mask ) {
  if( last == (shops.size()-1)  ) {
    return make_pair(0,0) ;
  }
  if( vis[last][mask] == gc ) {
    return dp[last][mask] ;
  }
  vis[last][mask] = gc ;
  pair<int,int> ret = make_pair(-(1<<28),1<<28) ;
  for( int i = 0 ; i < shops.size() ; i++ ) {
    if( (mask&(1<<i)) == 0 && cost[last][i] != (1<<28) ) {
      pair<int,int> tmp = rec( i , mask|(1<<i) ) ;
      tmp.first ++ ;
      tmp.second += cost[last][i] ;
      if( tmp.first > ret.first ) {
        ret = tmp ;
      } else if( tmp.first == ret.first && tmp.second < ret.second ) {
        ret = tmp ;
      }
    }
  }
  return dp[last][mask] = ret ;
}

int main() {
  int cases , caseno =1 ;
  scanf("%d",&cases ) ;
  while( cases -- ) {
    scanf("%d%d%d",&n,&m,&s) ;
    set<int> st ;
    src = 0 , dest = 0 ;
    st.insert(0) ;
    st.insert(n-1) ;
    for( int i = 0 ; i < s ; i++ ) {
      cin >> p ;
      st.insert(p) ;
      if( !p )src = 1 ;
      else if( p == n-1 )dest = 1 ;
    }
    for( set<int>:: iterator it = st.begin() ; it != st.end() ; it++ ) {
      shops.push_back(*it) ;
    }
    for( int i = 0 ; i < m ; i++ ) {
      scanf("%d%d%d",&u,&v,&w) ;
      g[u].push_back(node(v,w));
    }
    for( int i = 0 ; i < shops.size() ; i++ ) {
      dijkstra(shops[i]) ;
      for( int j = 0 ; j < shops.size() ; j++ ) {
        cost[i][j] = dist[shops[j]] ;
      }
    }

    gc++ ;
    pair<int,int> ans = rec(0,0|(1<<0)) ;
    if( !dest )ans.first-- ;
    if( src )ans.first++  ;
    if( ans.first <= 0 )cout << "Case " << caseno++ << ": Impossible\n" ;
    else cout << "Case " << caseno++ << ": " << ans.first << " " << ans.second << "\n" ;

    for( int i = 0 ; i < n ; i++ ) g[i].clear() ;
    shops.clear() ;
  }
  return 0 ;
}

