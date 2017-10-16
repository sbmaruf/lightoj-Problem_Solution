#include<bits/stdc++.h>
using namespace std ;
#define MAX 100505
int N , M , q  ;
vector<int>G[MAX],V[MAX] ;
int vis[MAX],dist[MAX] ;
int nd[MAX],ans[MAX] ;

void dfs( int nd , int bc , int color ) {
  vis[nd] = color ;
  for( int i = 0 ; i < (int)G[nd].size() ; i++ ) {
    int v = G[nd][i] ;
    if( v == bc )continue ;
    if( vis[v] == 0 ) {
      dfs(v,nd,color) ;
    }
  }
  return ;
}

struct node {
  int u , w ;
  node() {}
  node( int _u , int _w ) {
    u = _u , w = _w ;
  }
};

inline int calcDiameterNode(int root , int color , int type ) {
  queue<node>pq ;
  pq.push(node(root,0));
  for( int i = 0 ; i < (int)V[color].size() ; i++ ) {
    dist[V[color][i]] = 1<<28 ;
  }
  dist[root] = 0 ;
  int st = root , mx = 1 ;
  while( !pq.empty() ) {
    node u = pq.front() ;
    pq.pop() ;
    for( int i = 0 ; i < (int)G[u.u].size() ; i++ ) {
      int v = G[u.u][i] ;
      if( u.w+1 < dist[v] ) {
        dist[v] = u.w+1 ;
        pq.push(node(v,dist[v])) ;
        if( dist[v] > mx ) {
          mx = dist[v] ;
          st = v ;
        }
      }
    }
  }
  if( type == 0 ) return st ;
  else return mx+1 ;
}
inline int readInt()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }

    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
int main() {

  int cases , caseno = 1 ;
  //scanf("%d",&cases ) ;
  cases = readInt() ;
  while( cases -- ) {
    //scanf("%d%d",&N,&M) ;
    N = readInt() ;
    M = readInt() ;
    for( int i = 0 ; i < MAX ; i++ ) {
      G[i].clear() ;
      V[i].clear() ;
      ans[i] = 1<<28 ;
    }
    for( int i = 0 ; i < M ; i++ ) {
      int u , v ;
      //scanf("%d%d",&u,&v) ;
      u = readInt() ;
      v = readInt() ;
      G[u].push_back(v) ;
      G[v].push_back(u) ;
    }

    memset( vis , 0 , sizeof vis ) ;
    int color = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {
      if( vis[i] == 0 && G[i].size() > 0 ) {
        dfs(i,-1,++color) ;
      }
    }
    map<int,int>mp ;
    for( int i = 1 ; i <= N ; i++ ) {
      if( G[i].size() > 0 ) {
        mp[vis[i]]++ ;
        nd[vis[i]] = i ;
        V[vis[i]].push_back(i) ;
      }
    }
    for( int i = 1 ; i <= color ; i++ ) {
      int tot = mp[i] ;
      int diam,st ;
      if( tot == 1 )diam = 1 ;
      else {
        st = calcDiameterNode(nd[i],i,0) ;
        diam = calcDiameterNode(st,i,1) ;
      }
      for( int j = 1 ; j <= diam ; j++ ) {
        ans[j] = min( ans[j] , j-1 )  ;
      }
      for( int j = diam+1 ; j <= tot ; j++ ) {
        ans[j] = min( ans[j] , 2*j-diam-1 ) ;
      }
    }
    cout << "Case " << caseno++ << ":\n" ;
    //cin >> q ;
    q = readInt() ;
    while( q -- ) {
      int K ;
      //scanf("%d",&K) ;
      K = readInt() ;
      if( ans[K] != (1<<28) ) {
        cout << ans[K] << "\n" ;
      } else cout << "impossible\n" ;
    }
  }

  return 0 ;
}
