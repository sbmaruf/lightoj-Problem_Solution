#include<bits/stdc++.h>
using namespace std ;
int isRival[13][13] ;
int n , k , q , t ,tmp ;
long long dp[13][13][(1<<12)+1] ;

long long rec( int _back , int _taken , int mask ) {

  if( mask == ((1<<(n+1))-1) )
    return 1 ;

  if(dp[_back][_taken][mask] != -1)
    return dp[_back][_taken][mask] ;

  long long ret = 0;

  for( int i = 1 ; i<= n ; i++ ) {
    if( !(mask&(1<<i)) ) {
      if( _taken-isRival[_back][i] >= 0 ) {
        ret += rec( i , _taken-isRival[_back][i] , mask|(1<<i) ) ;
      }
    }
  }

  return dp[_back][_taken][mask] = ret ;
}

int main() {

  int cases , caseno = 1 ;
  scanf("%d",&cases ) ;
  while( cases -- ) {

    memset( isRival , 0 , sizeof isRival ) ;
    memset( dp , -1 , sizeof dp ) ;

    scanf("%d%d%d",&n,&k,&q) ;
    for( int i = 0 ; i < n ; i++ ) {
      scanf("%d",&t);
      for( int j = 0 ; j< t ; j++ ) {
        scanf("%d",&tmp) ;
        isRival[i+1][tmp] = 1;
      }
    }

    cout << "Case " << caseno++ << ":\n" ;

    while( q -- ) {
      long long tmp ;
      scanf("%lld",&tmp ) ;
      long long lim ;
      if( k )lim= tmp/(long long)k ;
      else lim = n-1 ;
      if( lim >= n )lim = n-1 ;
      cout << rec( 0 , lim , 0|(1<<0) ) << "\n" ;
    }

  }

  return 0 ;
}

/*

1
2 10 2
1 2
0
10
5

Case 1:
2
1
*/

