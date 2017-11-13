#include<bits/stdc++.h>
using namespace std ; 
int n , k, s ;
long long dp[2][15000+10] , sum[15000+10] ;
const long long mod = 100000007 ; 

long long solve(){
  memset( dp , 0 , sizeof dp ) ;
  int r = 0 ; 
  dp[1-r][0] = 1 ; 
  for( int i = 1 ; i <= n ; i++ ){
    sum[0] = dp[1-r][0] % mod ; 
    for( int j = 1 ; j <= s ; j++ ){   
      sum[j] = ( sum[ j-1 ] + dp[1-r][j] ) % mod ;  
    }
    dp[r][0] = 0 ; 
    for( int j = 1 ; j <= s ; j++ ){
      dp[r][j] = dp[r][j-1]+sum[j-1] ;
      if( j-k-1 >= 0 ){
         dp[r][j] -= sum[j-k-1] ; 
         dp[r][j] -= k*dp[1-r][j-k-1] ;
      }
      dp[r][j] = ( dp[r][j]%mod + mod ) % mod ; 
    }
    r = 1-r ; 
  }
  return dp[1-r][s] ; 
}

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0) ; 
  int cases , caseno = 1 ; 
  cin >> cases ; 
  while( cases -- ){
    cin >> n >> k >> s ; 
    cout << "Case " << caseno++ << ": " << solve() << "\n" ;
  }
  return 0 ; 
}


/*

  Dice I

  dp[i][j] = using i'th coin making sum j  
  dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + dp[i-1][j-3] + ... + dp[i-1][j-k]
  dp[i][j-1] = dp[i-1][j-2] + dp[i-1][j-3] + dp[i-1][j-4]+ ... + dp[i-1][j-k-1] 
--------------------------------------------------------------------------------
(-) dp[i][j] - dp[i][j-1] = dp[i-1][j-1] - dp[i][j-k-1]
 => dp[i][j] = d[i-1][j-1] + dp[i][j-1] - dp[i][j-k-1] 

  Dice II

  dp[i][j] = using i'th coin making sum j 
  dp[i][j] = 1*dp[i-1][j-1] + 2*dp[i-1][j-2] + ... + k*dp[i-1][j-k]
  dp[i][j-1] = 1*dp[i-1][j-2] + 2*dp[i-1][j-3] + ... + k*dp[i-1][j-k-1] 
---------------------------------------------------------------------------------
(-) dp[i][j] - dp[i][j-1] = dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-k] - k*dp[i-1][j-k-1] 
=>  dp[i][j] = dp[i-1][j-1] + dp[i-1][j-2] + ... + dp[i-1][j-k] - k*dp[i-1][j-k-1] + dp[i][j-1] 

 
*/
s
