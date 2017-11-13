#include<bits/stdc++.h>
using namespace std ;
unsigned long long dp[5][14][14][14][14] ;
int vis[5][14][14][14][14] ;
int gc ;
unsigned long long rec( int last , int c1 , int c2 , int c3 , int c4 ){

  if( c1 == 0 && c2 == 0 && c3 == 0 && c4 == 0 ){
    return 1 ;
  }
  if( vis[last][c1][c2][c3][c4] == gc ){
    return dp[last][c1][c2][c3][c4] ;
  }
  vis[last][c1][c2][c3][c4] = gc ;
  unsigned long long ret = 0 ;
  if( c1 > 0 ){
    if( last == 2 )ret += (c1-1)* rec( 1 , c1-1 , c2 , c3 , c4 ) ;
    else ret += c1* rec( 1 , c1-1 , c2 , c3 , c4 ) ;
  }
  if( c2 > 0 ){
    if( last == 3 )ret += 2*(c2-1)*rec( 2 , c1+1 , c2-1 , c3 , c4 ) ;
    else ret += 2*c2*rec( 2 , c1+1 , c2-1 , c3 , c4 ) ;
  }
  if( c3 > 0 ){
    if( last == 4 )ret += 3*(c3-1)*rec( 3 , c1 , c2+1 , c3-1 , c4 );
    else ret += 3*c3*rec( 3 , c1 , c2+1 , c3-1 , c4 );
  }
  if( c4 > 0 ){
      ret +=4*c4*rec( 4 , c1 , c2 , c3+1 , c4-1 ) ;
  }
  return dp[last][c1][c2][c3][c4] = ret ;
}


int main() {

  int cases , caseno =1 ;
  scanf("%d",&cases) ;
  gc++;
  while( cases -- ) {
    int n ;
    scanf("%d",&n) ;
    char s[4] ;
    int cnt[5] = {0} ;
    int suit[14] = {0} ;
    for( int i = 0 ; i < n ; i++ ) {
      scanf(" %s",s) ;
      if( s[0] >= '0' && s[0] <= '9' ) {
        //cout << s[0] << " " << int(s[0]-'2') << "\n" ;
        suit[s[0]-'2']++;
      } else if( s[0] == 'T' ) {
        suit[8]++ ;
      } else if( s[0] == 'J' ) {
        suit[9]++ ;
      } else if( s[0] == 'Q' ) {
        suit[10]++ ;
      } else if( s[0] == 'K' ) {
        suit[11]++ ;
      } else if( s[0] == 'A' ) {
        suit[12]++ ;
      }
    }
    for( int i = 0 ; i < 14 ; i++ ){
      cnt[suit[i]]++ ;
    }
    cout << "Case "<< caseno++ << ": " << rec( 0 , cnt[1] , cnt[2] , cnt[3] , cnt[4] ) << "\n" ;
  }
  return 0 ;
}

