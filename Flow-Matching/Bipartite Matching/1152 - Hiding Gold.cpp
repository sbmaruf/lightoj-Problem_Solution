#include<bits/stdc++.h>
using namespace std ;
#define MAX 20*20
int m ,n ;
char str[MAX][MAX] ;
vector<int> G[MAX] ;
int dirR[] = { 0 , 0 , 1 , -1 } ;
int dirC[] = { 1 , -1 , 0 , 0 } ;
int _left[MAX] , _right[MAX] ;
bool visited[MAX] ;
int mp[MAX][MAX] ;


bool dfs( int u ) {
  if( visited[u] )return 0 ;
  visited[u] = 1 ;
  for( int i = 0; i < (int)G[u].size() ; i++ ) {
    int v = G[u][i] ;
    if( _right[v] == -1 ) {
      _right[v] = u , _left[u] = v ;
      return 1 ;
    }
  }
  for( int i =0 ; i < (int)G[u].size() ; i++ ) {
    int v = G[u][i] ;
    if( dfs( _right[v] ) ) {
      _right[v] = u , _left[u] = v ;
      return 1 ;
    }
  }
  return 0 ;
}

int BPM(int n) {
  memset( _left , -1 , sizeof _left ) ;
  memset( _right , -1 , sizeof _right ) ;
  int ret = 0 , done ;
  do {
    done = 1 ;
    memset( visited , 0 , sizeof visited ) ;
    for( int i = 0 ; i < n  ; i++ ) {
      if( _left[i] == -1 && dfs(i) ) {
        done = 0 ;
      }
    }
  } while( !done ) ;
  for( int i =0  ; i < n ; i++ ) {
    ret += (_left[i]!=-1) ;
  }
  return ret ;
}

int main() {

  int cases , caseno =1 ;
  scanf("%d",&cases ) ;

  while( cases -- ) {
    scanf("%d%d",&m,&n) ;
    for( int i =0 ; i < m ; i++ ) {
      scanf("%s",str[i]) ;
    }
    for( int i =0 ; i < MAX ; i++ ) {
      G[i].clear() ;
    }
    int cnt = 0 ;
    int tot = 0 ;
    memset(mp , -1 , sizeof mp ) ;
    for( int i = 0; i < m ; i++ ) {
      for( int j = 0 ; j < n ; j++ ) {
        if( str[i][j] == '*' ) {
          for( int k = 0 ; k < 4 ; k++ ) {
            int r = i + dirR[k] ;
            int c = j + dirC[k] ;
            if( r >= 0 && c >= 0 && r < m && c < n && str[r][c] == '*') {
              if( mp[i][j] == -1 )mp[i][j] = cnt ++ ;
              if( mp[r][c] == -1 )mp[r][c] = cnt ++ ;
              G[mp[i][j]].push_back(mp[r][c]) ;
              //G[mp[r][c]].push_back(mp[i][j]) ;
            }
          }
          tot++ ;
        }
      }
    }
    //cout << tot << " " << cnt << endl  ;
    cout << "Case " << caseno++ << ": " << tot - (BPM(cnt)>>1) << "\n" ;
  }
  return 0 ;
}

/*

2
5 8
oo**oooo
*oo*ooo*
******oo
*o*oo*oo
******oo
3 4
**oo
**oo
*oo*

*/


