#include<bits/stdc++.h>
using namespace std ;

string str[201] ;
int idx = 0 ;
int n , m , stx , sty , enx , eny ;
int dist[200+5][200+5] ;
int dirR[]= {1,-1,0,0};
int dirC[]= {0,0,1,-1};
int d[205][205] ;

struct node {
  int x , y ;
  node() {}
  node( int _f , int _s ) {
    x = _f , y = _s ;
  }
};

node door[201*201] ;

void Clear() {
  for( int i = 0 ; i < n ; i++ ) {
    for( int j = 0; j < m ; j++ ) {
      dist[i][j] = 1<<28 ;
      d[i][j] = 1<<28 ;
    }
  }
}

void rbfs() {
  Clear() ;
  queue<node>Q ;
  Q.push(node(enx,eny)) ;
  dist[enx][eny] = 0 ;
  while( !Q.empty() ) {
    node u = Q.front();
    Q.pop();
    for( int i = 0; i < 4 ; i++ ) {
      int R = u.x + dirR[i] ;
      int C = u.y + dirC[i] ;
      if( R >= 0 && C >= 0 && R < n && C < m ) {
        if( str[R][C] != '#' ) {
          if( dist[u.x][u.y]+1 < dist[R][C] ) {
            dist[R][C] = dist[u.x][u.y]+1 ;
            Q.push(node(R,C)) ;
          }
        }
      }
    }
  }
  return  ;
}

int bfs() {
  queue<node>Q ;
  Q.push(node(stx,sty)) ;
  d[stx][sty] = 0 ;
  while( !Q.empty() ) {
    node u = Q.front();
    Q.pop();
    for( int i = 0; i < 4 ; i++ ) {
      int R = u.x + dirR[i] ;
      int C = u.y + dirC[i] ;
      if( R >= 0 && C >= 0 && R < n && C < m ) {
        if( str[R][C] != '#' ) {
          if( str[R][C] == '*' ){
            int mn = 1<<28 , id = -1 ;
            for( int j = 0 ; j < idx ; j++ ){
              if( door[j].x == R && door[j].y == C ){
                continue ;
              }
              if( dist[door[j].x][door[j].y] < mn ){
                mn = dist[door[j].x][door[j].y] ;
                id = j ;
              }
            }
            if( id != -1 ){
              if( d[enx][eny] > mn+1+d[u.x][u.y]+1 ){
                d[enx][eny] = mn+1+d[u.x][u.y]+1 ;
                Q.push(node(enx,eny)) ;
              }
            }
            if( idx > 1 ){
              if( d[R][C] > d[u.x][u.y]+3 ){
                d[R][C] = d[u.x][u.y]+3 ;
                Q.push(node(R,C)) ;
              }
            }
          }else if( d[u.x][u.y]+1 < d[R][C] ) {
            d[R][C] = d[u.x][u.y]+1 ;
            Q.push(node(R,C)) ;
          }
        }
      }
    }
  }
  return d[enx][eny] ;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0) ;

  int cases , caseno = 1 ;
  cin >> cases ;
  while( cases -- ) {
    cin >> n >> m ;
    idx = 0 ;
    for( int i = 0 ; i < n ; i++ ) {
      cin >> str[i] ;
      for( int j = 0 ; j < m ; j++ ) {
        if( str[i][j]=='*' ) {
          door[idx++]=node(i,j);
        } else if( str[i][j] == 'P' ) {
          stx=i,sty=j ;
        } else if( str[i][j] == 'D' ) {
          enx=i,eny=j ;
        }
      }
    }
    rbfs();
    int ans = bfs() ;
    if( ans == (1<<28) )cout << "Case " << caseno++ << ": impossible\n" ;
    else cout << "Case " << caseno++ << ": " << ans << "\n" ;
  }
  return 0 ;
}

/*
*/
