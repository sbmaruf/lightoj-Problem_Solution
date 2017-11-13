#include<bits/stdc++.h>
using namespace std ;
int val[14][14] , sum[(1<<14)+1] ;
int dp[(1<<14)+1] , vis[(1<<14)+1];
int n , cases , caseno = 1 ;
int rec( int mask ) {
  if( mask == 0 ) return 0 ;
  if( vis[mask] == caseno ) return dp[mask] ;
  vis[mask] = caseno ;
  int ret = 1<<30 ;
  for( int i = mask ; i > 0 ; i = (i-1)&mask ) {
    ret = min( ret , rec(mask^i)+sum[i] ) ;
  }
  return dp[mask] = ret ;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> cases ;
  while( cases -- ) {
    cin >> n ;
    for( int i = 0 ; i < n ; i ++ ) {
      for( int j = 0 ; j < n ; j++ ) {
        cin >> val[i][j] ;
      }
    }
    for( int i = 1 ; i < (1<<n) ; i++ ) {
      sum[i] = 0 ;
      for( int j = 0 ; j < n ; j++ ) {
        if( i&(1<<j) ) {
          for( int k = j+1 ; k < n ; k++ ) {
            if( i&(1<<k) ) {
              sum[i] += val[j][k]+val[k][j] ;
            }
          }
        }
      }
    }
    cout << "Case " << caseno << ": " << rec( (1<<n)-1 ) << "\n" ;
    caseno++ ;
  }
  return 0 ;
}

