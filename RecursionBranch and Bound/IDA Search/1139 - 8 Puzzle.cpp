#include<bits/stdc++.h>
using namespace std ;
int dirR[] = {0,0,1,-1} ;
int dirC[] = {1,-1,0,0} ;
map<vector<int>, int> mp ;
void precalc(){
  int k = 0 ;
  int board[3][3] ;
  vector<pair<int,int> >pos ;
  for( int i = 0 ; i < 3 ; i++ ){
    for( int j = 0 ; j < 3 ; j++ ){
      board[i][j] = k ;
      pos.push_back(make_pair(i,j)) ;
      k++ ;
    }
  }
  vector<int>v ;
  for( int i = 1 ; i < 9 ; i++ ){
    v.push_back(i) ;
  }
  v.push_back(0);
  queue< pair<vector<int>,int> > q ;
  q.push( make_pair(v,8) );
  mp[v] = 0 ;
  while( !q.empty()){
    vector<int> u = q.front().first ;
    int p = q.front().second ;
    q.pop() ;
    vector<int>tmp = u ;
    for( int k = 0 ; k < 4 ; k++ ){
      int R = pos[p].first+dirR[k] ;
      int C = pos[p].second+dirC[k] ;
      if( R >= 0 && R < 3 && C >= 0 && C < 3 ){
        int pp = board[R][C] ;
        swap(u[pp],u[p]) ;
        if( mp.find(u) == mp.end() ){
          mp[u] = mp[tmp]+1;
          q.push(make_pair(u,pp)) ;
        }
        swap(u[pp],u[p]) ;
      }
    }
  }
  return ;
}

int main(){

  int cases , caseno = 1 ;
  scanf("%d",&cases ) ;
  precalc();
  while( cases -- ){
    vector<int> V ;
    for( int i = 0 ; i < 3 ; i++ ){
      for( int j = 0 ; j < 3 ; j++ ){
        int p ;
        scanf("%d",&p);
        V.push_back(p) ;
      }
    }
    if( mp.find(V) == mp.end() ) {
      cout << "Case " << caseno++ << ": " << "impossible" << "\n" ;
    }else {
      cout << "Case " << caseno++ << ": " << mp[V] << "\n" ;
    }
  }
  return 0 ;
}

