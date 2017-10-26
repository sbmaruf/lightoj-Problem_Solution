#include<bits/stdc++.h>
using namespace std ;
char str[8][8];
pair<int,int>p[8] ;
int idx = 0 , memidx  ;
int vis[8][8] = {0} ;
vector< vector<int> > allBoard ;
vector<int>pos ;
int dp[1<<9] , mem[1<<9]  ;
int dirR[]={1,-1,-1,1} ;
int dirC[]={1,-1,1,-1} ;

bool isOk( int r , int c ) {
  for( int i = 0 ; i < 8 ; i++ ){
    if( vis[r][i] == 1 || vis[i][c] ){
      return 0 ;
    }
    for( int k = 0 ; k < 4 ; k++ ){
      int R = r+dirR[k]*i ;
      int C = c+dirC[k]*i ;
      if( R >= 0 && C >= 0 && R < r && C < 8 ){
        if( vis[R][C] == 1 )return 0 ;
      }
    }
  }
  return 1 ;
}

int Solve( int row , int col , int nThQueen ){
  if( p[nThQueen].first == row
  && p[nThQueen].second == col )return 0 ;
  if( p[nThQueen].first == row ) return 1 ;
  if( p[nThQueen].second == col ) return 1 ;
  if( abs( p[nThQueen].first-row ) ==
      abs( p[nThQueen].second-col )){
    return 1 ;
  }else return 2  ;
}

int rec( int mask ) {

  if( mask == ((1<<8)-1) ){
    return 0 ;
  }
  if( mem[mask] == memidx ) return dp[mask] ;
  mem[mask] = memidx ;
  int ret = (1<<28) ;
  for( int i = 0 ; i < idx ; i++ ){
    if( (mask&(1<<i))==0 ){
      ret = min( ret , rec(mask|(1<<i))+
      Solve(i,pos[i],__builtin_popcount(mask) ) ) ;
    }
  }
  return dp[mask] = ret ;

}

void backtrack( int row ) {
  if( row == 8 ){
    allBoard.push_back(pos) ;
    return ;
  }
  int mn = (1<<28) ;
  for( int i = 0 ; i < 8 ; i++ ){
    if( isOk( row , i ) ){
      vis[row][i] = 1 ;
      pos.push_back(i) ;
      backtrack(row+1) ;
      vis[row][i] = 0 ;
      pos.pop_back() ;
    }
  }
  return ;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie() ;

  int cases , caseno =1 ;
  cin >> cases ;

  backtrack( 0 ) ;
  while( cases -- ){
    idx = memidx = 0 ;
    for( int i = 0 ; i < 8 ; i++ ){
      cin >> str[i] ;
      for(int j = 0 ; j < 8 ; j++ ){
        if( str[i][j] == 'q' ){
          p[idx++]=make_pair(i,j) ;
        }
      }
    }
    int ans = 1<<28 ;
    for( int i = 0 ;i < allBoard.size() ; i++ ){
      memidx++ ;
      pos=allBoard[i] ;
      ans=min(ans,rec(0));
    }
    cout << "Case " << caseno++ << ": " << ans << "\n" ;

  }

  return 0 ;
}

