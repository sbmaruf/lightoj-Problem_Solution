#include<bits/stdc++.h>
using namespace std ;

int _left[501] , _right[501] , visited[501] ;
vector<int>G[501] ;

bool dfs( int u ){
  if( visited[u] )return 0 ;
  visited[u] = 1 ;
  for( int i = 0 ; i < (int)G[u].size() ; i++ ){
    int v = G[u][i] ;
    if( _right[v] == -1 ){
      _right[v] = u ; _left[u] = v ;
      return 1 ;
    }
  }
  for( int i = 0 ; i < (int)G[u].size() ; i++ ){
    int v = G[u][i] ;
    if( dfs( _right[v] ) ){
      _right[v] = u , _left[u] = v ;
      return 1 ;
    }
  }
  return 0 ;
}

int BPM( int n ) {
  memset( _left , -1 , sizeof _left ) ;
  memset( _right , -1 , sizeof _right ) ;
  int ret = 0 , done = -1 ;
  do{
    done = 1 ;
    memset( visited , 0 ,sizeof visited ) ;
    for( int i = 0 ; i < n ; i++ ){
      if( _left[i] == -1 && dfs(i) ){
        done = 0 ;
      }
    }
  }while( !done ) ;
  for( int i = 0 ; i < n ; i++ ){
    ret += (_left[i]!=-1) ;
  }
  return ret ;
}

int main(){

  int cases , caseno =1 ;
  scanf("%d",&cases) ;

  while( cases -- ){
    int m , f , v ;
    scanf("%d%d%d",&m,&f,&v) ;
    for( int i =0 ; i <= v; i++ ){
      G[i].clear() ;
    }
    char c1,c2 ;
    int a , b ;
    pair<string,string> P[v] ;
    string s , s1 ;
    for( int i = 0 ;i < v ; i++ ){
      cin >> s >> s1 ;
      P[i].first = s ;
      P[i].second = s1 ;
    }
    for( int i =0 ; i < v ; i++ ){
      for( int j = 0 ; j < v ; j++ ){
        if( i == j )continue ;
        if( P[i].first == P[j].second ){
          G[i].push_back(j) ;
          G[j].push_back(i) ;
        }
      }
    }
    //cout << v << " " << BPM(v) << endl ;
    cout << "Case " << caseno++ << ": " << v-BPM(v)/2 <<"\n" ;
  }


  return 0 ;
}

