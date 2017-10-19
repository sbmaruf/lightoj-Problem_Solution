#include<bits/stdc++.h>
using namespace std ;
#define MOD1 1299827
#define MOD2 101747
int M , N ;
char str[13][13]  ;
pair<int,int>_next[4][13][13] ;
int dirR[] = { 0 , -1 , 1 , 0 };
int dirC[] = { 1 , 0 , 0 , -1 };
string dirS="ENSW" ;

bool isValid( int i , int j ) {
  return ( i >= 0 && j >= 0 && i < M && j < N ) ;
}

unsigned Hash( vector<pair<int,int> > V ) {
  unsigned h = 2166136261;
  for( int i = 0 ; i < V.size() ; i++ ) {
    h = (h * 16777619) ^ (V[i].first);
    h = (h * 16777619) ^ (V[i].second);
  }
  return h;
}

void calcNextMove() {
  for( int k = 0 ; k < 4 ; k++ ) {
    for( int i = 0 ; i < M ; i++ ) {
      for( int j = 0  ; j < N ; j++ ) {
        if( str[i][j] == '.' ) {
          int R = i ;
          int C = j ;
          while( isValid(R,C) && str[R][C] != '#' ) {
            R = R+dirR[k] ;
            C = C+dirC[k] ;
          }
          pair<int,int> val ;
          if( isValid(R,C) ) {
            val.first = R-dirR[k];
            val.second = C-dirC[k];
          } else {
            val.first = 1<<28 ;
            val.second = 1<<28 ;
          }
          R = i ;
          C = j ;
          while( isValid(R,C) && str[R][C] != '#' ) {
            R = R+dirR[k] ;
            C = C+dirC[k] ;
            _next[k][i][j] = val ;
          }
        }
      }
    }
  }
}

string bfs() {
  vector<pair<int,int> > state ;
  for( int i = 0 ; i < M ; i++ ) {
    for( int j = 0 ; j < N ; j++ ) {
      if( str[i][j] == '.' ) {
        state.push_back(make_pair(i,j)) ;
      }
    }
  }
  map<unsigned, string > vis ;
  queue<vector<pair<int,int> > > Q ;
  Q.push( state ) ;
  vis[Hash(state)]="" ;
  while( !Q.empty() ) {
    vector<pair<int,int> > u = Q.front() ;
    Q.pop() ;
    unsigned pp = Hash(u) ;
    if( u.size() == 0 )return vis[pp] ;
    for( int k = 0 ;  k < 4 ; k++ ) {
      vector<pair<int,int> > v ;
      for( int i = 0 ; i < u.size() ; i++ ) {
        pair<int,int> tmp = u[i] ;
        pair<int,int> nxt = _next[k][tmp.first][tmp.second] ;
        if( nxt.first != (1<<28) ) {
          v.push_back(nxt) ;
        }
      }
      sort(v.begin(),v.end()) ;
      v.erase(unique(v.begin(),v.end()),v.end()) ;
      unsigned qq = Hash(v) ;
      if( vis.find(qq) == vis.end() ) {
        Q.push(v) ;
        vis[qq]=vis[pp]+dirS[k] ;
      }
    }
  }
  return "Impossible" ;
}
int main() {

  //freopen("in.txt","r",stdin) ;
  ios_base::sync_with_stdio(0);
  cin.tie(0) ;
  int cases , caseno = 1 ;
  scanf("%d",&cases ) ;
  while( cases -- ) {
    scanf("%d%d",&M,&N) ;
    for( int i  = 0  ; i < M ; i++ ) {
      scanf("%s",str[i] ) ;
    }
    calcNextMove() ;
    string ans = bfs();
    cout << "Case " << caseno++ << ": " << ans << "\n" ;
  }


  return 0 ;
}

/*

1
12 12
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.
#.#.#.#.#.#.

*/

