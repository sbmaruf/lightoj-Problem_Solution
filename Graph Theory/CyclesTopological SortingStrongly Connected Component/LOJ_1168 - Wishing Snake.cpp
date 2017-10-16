#include<bits/stdc++.h>
using namespace std ;
vector<int>g[10000+1],rev[10000+1],_g[10000+1] ;
int vis[10000+1] , component[10000+1] , stk[10000+1] , cvis[10000+1] , final_vis[10000+1] ;
int stidx , cnt , isOk;
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
void dfs( int nd ) {
  vis[nd] = 1 ;
  for( int i = 0 ; i < g[nd].size() ; i++ ) {
    if( vis[g[nd][i]] == -1 )dfs(g[nd][i]);
  }
  stk[stidx++] = nd ;
  return ;
}

void rev_dfs( int nd ) {
  cvis[nd] = 1 ;
  for( int i = 0 ; i < rev[nd].size() ; i++ ) {
    if( cvis[rev[nd][i]] == -1 )rev_dfs(rev[nd][i]);
  }
  component[nd] = cnt ;
  return;
}

void try_dfs( int nd ) {
  if( !isOk )return ;
  if( _g[nd].size() >= 2 ) {
    isOk = 0 ;
    return ;
  }
  final_vis[nd] = 1 ;
  if( _g[nd].size() == 0  )return ;
  for( int i = 0; i < _g[nd].size() ; i++ ) {
    try_dfs( _g[nd][i] ) ;
  }
  return ;
}

int main() {

  int cases , caseno =1 ;
  //scanf("%d",&cases) ;
  cases = readInt() ;
  while( cases -- ) {
    int n ;
    //scanf("%d",&n) ;
    n = readInt() ;
    set<int>st ;
    for( int i= 0 ; i < 10000+1 ; i++ ) {
      g[i].clear() ;
      rev[i].clear() ;
      _g[i].clear() ;
      component[i] = -1  ;
      vis[i] = -1 ;
      cvis[i] = -1 ;
      final_vis[i] = -1 ;
    }

    for( int i = 0 ; i < n ; i++ ) {

      int k ;
      //scanf("%d",&k) ;
      k = readInt() ;

      int u , v ;
      for(int j = 0 ; j < k ; j++ ) {
        //scanf("%d%d",&u,&v) ;
        u = readInt() ;
        v = readInt() ;
        st.insert(u);
        st.insert(v);
        g[u].push_back(v) ;
        rev[v].push_back(u) ;
      }

    }
    stidx = 0 ;
    for(set<int>:: iterator it = st.begin() ; it != st.end() ; it++ ) {
      if( vis[*it] == -1 ) {
        dfs( *it ) ;
      }
    }

    cnt= 0 ;
    for(int i = stidx-1 ; i >=0 ; i-- ) {
      int v = stk[i] ;
      //cout << "-> " << v << endl ;
      if( cvis[v] == -1 ) {
        rev_dfs( v ) ;
        cnt ++ ;
      }
    }

    set<int>C ;
    for(set<int>:: iterator it = st.begin() ; it != st.end() ; it++ ) {
      C.insert(component[(*it)]);
      //cout << *it  << " : " << component[*it] << "\n" ;
    }

    for( set<int>:: iterator it = st.begin() ; it != st.end() ; it++  ) {
      int u = *it ;
      for( int i = 0 ; i< g[u].size() ; i++ ) {
        int v = g[u][i] ;
        if( component[u] != component[v] ) {
          _g[component[u]].push_back(component[v]) ;
        }
      }
    }

    isOk = 1 ;
    try_dfs( component[0] ) ;
    for( set<int>:: iterator it = C.begin() ; it != C.end() ; it++ ) {
      if( final_vis[*it] == -1 ) {
        //cout << (*it) << endl ;
        isOk = 0 ;
        break ;
      }
    }
    if( isOk )cout << "Case " << caseno++ << ": YES\n" ;
    else cout << "Case " << caseno++ << ": NO\n" ;


  }
  return 0 ;
}
