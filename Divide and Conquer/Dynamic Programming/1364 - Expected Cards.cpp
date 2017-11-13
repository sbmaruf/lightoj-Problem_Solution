#include<bits/stdc++.h>
using namespace std ;
int C, D , H , S ;
int cases , caseno = 1 ;

int vis[16][16][16][16][3][3][3][3] ;
double dp[16][16][16][16][3][3][3][3] ;

double rec( int c , int d , int h , int s , int cc , int dd , int hh , int ss ) {

  if( c+cc >= C && d+dd >= D && h+hh >= H && s+ss >= S ) return 0 ;
  if( vis[c][d][h][s][cc][dd][hh][ss] == caseno ) {
    return dp[c][d][h][s][cc][dd][hh][ss] ;
  }
  vis[c][d][h][s][cc][dd][hh][ss] = caseno ;
  //probability of getting clubs,diamonds,hearts,spades,joker
  int tot_unused = 54-(c+d+h+s)-cc-dd-hh-ss ;
  double pC = (double(13-c)/double(tot_unused)) ;
  double pD = (double(13-d)/double(tot_unused)) ;
  double pH = (double(13-h)/double(tot_unused)) ;
  double pS = (double(13-s)/double(tot_unused)) ;
  double pJ = (double(2-(cc+dd+hh+ss))/double(tot_unused)) ;
  double ret = 0 ;
  if( c<=12 )ret += (1.0+rec( c+1 , d , h , s , cc , dd , hh , ss ))*pC ;
  if( d<=12 )ret += (1.0+rec( c , d+1 , h , s , cc , dd , hh , ss ))*pD ;
  if( h<=12 )ret += (1.0+rec( c , d , h+1 , s , cc , dd , hh , ss ))*pH ;
  if( s<=12 )ret += (1.0+rec( c , d , h , s+1 , cc , dd , hh , ss ))*pS ;
  if( pJ > 0 ) {
    double try1 = rec( c , d , h , s , cc+1 , dd , hh , ss ) ;
    double try2 = rec( c , d , h , s , cc , dd+1 , hh , ss ) ;
    double try3 = rec( c , d , h , s , cc , dd , hh+1 , ss ) ;
    double try4 = rec( c , d , h , s , cc , dd , hh , ss+1 ) ;
    ret += (1+min(try4,min(try3,min(try1,try2))))*pJ ;
  }
  return dp[c][d][h][s][cc][dd][hh][ss] = ret ;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie(0) ;

  cin >> cases ;
  while( cases -- ) {
    cin >> C >> D >> H >> S ;
    int diff = (C>13?(C-13):0)+(D>13?(D-13):0)+(H>13?(H-13):0)+(S>13?(S-13):0) ;
    if( (C+D+H+S)>54 ||  diff > 2 || C>15 || D>15 || H > 15 || S > 15 ) {
      cout << "Case " << caseno++ << ": " << -1 << "\n" ;
      continue ;
    }
    cout << setprecision(15) << "Case " << caseno << ": " << rec( 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 ) << "\n" ;
    caseno++ ;
  }
  return 0 ;
}

