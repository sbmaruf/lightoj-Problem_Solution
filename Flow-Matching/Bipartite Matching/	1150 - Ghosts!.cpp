#include<bits/stdc++.h>
using namespace std ;
int R ;
int dirR[] = {0,0,1,-1} ;
int dirC[] = {-1,1,0,0} ;
int str[25+1][25+1] ;
struct data {
  int x, y , w ;
  data() {}
  data(int _x , int _y , int _w ) {
    x = _x ;
    y = _y ;
    w = _w ;
  }
};


data src[700] , dest[700] ;
int srcidx , destidx ;
int D[30][30] ;

void bfs( int x , int y ) {
  for( int i = 0 ; i < 30 ; i++ ) {
    for( int j = 0 ; j < 30 ; j++ ) {
      D[i][j] = 1<<30 ;
    }
  }
  queue<data> Q ;
  Q.push( data(x,y,0) );
  D[x][y] = 0 ;
  while( !Q.empty() ) {
    data u = Q.front() ;
    Q.pop();
    for( int k = 0 ; k <4 ; k++ ) {
      int r = u.x+dirR[k] ;
      int c = u.y+dirC[k] ;
      if( r>= 0 && c >= 0 && r < R && c < R  ) {
        if( u.w+1 < D[r][c] && str[r][c] != '#') {
          D[r][c] = u.w+1 ;
          Q.push(data(r,c,D[r][c])) ;
        }
      }
    }
  }
  return ;
}

#define MAX 155
vector<int>G[MAX] ;
int par[MAX] ;
int cost[MAX][MAX] ;
int cap[MAX][MAX] ;
int source = 0 ;
int sink = 150 ;

void insert( int u , int v , int w ) {
  G[u].push_back( v ) ;
  G[v].push_back( u ) ;
  cost[u][v] = w ;
}

int run() {
  memset( par , -1 , sizeof par ) ;
  queue<pair<int,int> > Q ;
  Q.push( {source , 1<<30}) ;

  while( !Q.empty() ) {
    pair<int,int> p = Q.front() ;
    Q.pop() ;
    int u = p.first ;
    int mn = p.second ;
    for( int i = 0 ; i  < G[u].size() ; i++ ) {
      int v = G[u][i] ;
      if( cap[u][v] > 0 && par[v] == -1 ) {
        par[v] = u ;
        mn = min( cap[u][v] , mn ) ;
        if( v == sink )return mn ;
        Q.push( {v,mn}) ;
      }
    }
  }
  return 0 ;
}

void pre(int mid) {
  for( int i = 0 ; i < MAX ; i++ ) {
    for( int j = 0 ; j  < MAX ; j++ ) {
      if( cost[i][j] <= mid ) {
        cap[i][j] = bool(cost[i][j]) ;
      } else if( cost[i][j] == (1<<30) ) {
        cap[i][j] = cost[i][j] ;
      } else cap[i][j] = 0 ;
    }
  }
}
bool ok( int mid ) {

  pre(mid);
  int local_ans = 0 ;
  int global_ans = 0 ;
  while( local_ans = run() ) {
    global_ans ++ ;
    if( global_ans == destidx ) return true ;
    for( int i = sink ; i != source ; i = par[i] ) {
      cap[par[i]][i] -= local_ans ;
      cap[i][par[i]] += local_ans ;
    }
  }
  return false ;

}
int main() {

  int cases  ,caseno = 1 ;
  scanf("%d",&cases ) ;
  while( cases -- ) {
    scanf("%d",&R) ;
    int newNode = 1 ;
    memset( cost , 0 , sizeof cost ) ;
    for( int i = 0 ; i < MAX ; i++ )G[i].clear() ;
    srcidx = 0 ;
    destidx = 0 ;
    for( int i = 0 ; i < R ; i++ ) {
      getchar();
      for( int j = 0 ; j < R ; j++ ) {
        scanf("%c" , &str[i][j] ) ;
        if( str[i][j] == 'G' ) {
          src[srcidx++] = data(i,j,newNode++) ;
        } else if( str[i][j]  == 'H' ) {
          dest[destidx++] = data(i,j,newNode++) ;
        }
      }
    }

    cout << "Case " << caseno++ << ": " ;

    if( destidx > srcidx ) {
      cout << "Vuter Dol Kupokat\n" ;
      continue ;
    }
    for( int i = 0 ; i  < srcidx ; i++ ) {
      insert( source , src[i].w , 1 ) ;
      bfs( src[i].x , src[i].y ) ;
      for( int j = 0 ; j < destidx ; j++ ) {
        if( D[dest[j].x][dest[j].y] != (1<<30) ) {
          insert(src[i].w ,dest[j].w , D[dest[j].x][dest[j].y] ) ;
          //cout << src[i].x << " " << src[i].y << " to " << dest[j].x << " " << dest[j].y << " = " << D[dest[j].x][dest[j].y] << "\n" ;
        }
      }
    }
    for( int j = 0 ; j < destidx ; j++ ) {
      insert(dest[j].w , sink , 1);
    }
    int lo = 0 ;
    int hi = 50;
    int mid ;
    while( hi-lo >= 4 ) {
      mid = (hi+lo)/2 ;
      if( ok( mid ) )hi = mid ;
      else lo = mid ;
    }
    bool f = 0 ;
    for( int i = lo ; i <= hi ; i++ ) {
      if( ok(i) ) {
        cout << (i+1)*2 << "\n" ;
        f =1 ;
        break ;
      }
    }
    if( !f ) cout << "Vuter Dol Kupokat\n" ;
  }
  return 0 ;
}

/*
4

8
....##..
.....#..
..#...G.
G...####
H#..HG.G
#....#.#
H.#G..H.
..##...#

6
......
G.....
......
......
......
.....H

6
.....G
.H....
......
......
....H.
G.....

6
#.#G#.
G....#
G..##.
H###.#
...#H#
..#GHH
*/

