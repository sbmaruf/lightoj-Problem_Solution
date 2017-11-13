#include<bits/stdc++.h>
using namespace std ; 
int n , arr[101] ;
long long dp[50000+10] ; 
int sum = 0 ; 

/*
string print(int p){
  if( p == 0 ) return "00000" ;
  string s = "" ;
  while( p > 0 ){
    s += (p%2+'0') ; 
    p/=2 ; 
  }
  while( s.size() < 5 ) s+="0" ; 
  reverse(s.begin(),s.end()) ; 
  return s ; 
}
*/
int solve(){ 
  memset( dp , 0 , sizeof dp ) ; 
  int tot = sum ; 
  sum/=2  ; 
  sum++ ; 
  dp[0]=1; 
  /*
  for( int i = 0 ; i <= sum; i++ ){
    cout << i << "     " ;
  }cout << "\n";
  */
  for( int i = 0 ; i < n ; i++ ){
    for( int j = sum ; j >= arr[i] ; j-- ){
      dp[j] |= ( dp[ j-arr[i] ]*2 ) ;    
    }
    /*
    for( int i = 0 ; i <= sum ; i++ ){
      cout << print(dp[i]) << " " ;  
    }cout << "\n" ;
    */
  }
  for( int i = sum-1 ; i >= 0 ; i-- ){
    if( (dp[i] & (1LL<<(n/2))) || (dp[i] & (1LL<<((n+1)/2))) ){
      cout << i << " " << tot-i <<"\n" ; 
      return 0 ;   
    }
  }
}
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);  
  int cases , caseno = 1; 
  cin >> cases ; 
  while( cases -- ){
    cin >> n ; 
    sum= 0 ; 
    for( int i = 0 ; i < n ; i++ ){
      cin >> arr[i] ; 
      sum += arr[i] ; 
    }
    cout << "Case " << caseno++ << ": " ;
    solve() ;   
  }
  return 0 ; 
}

/*

1
4
1 2 3 8

__builtin_popcount(dp[i])=how many ways you can make sum i.
dp[i] = contains all the results of "how many weights needed to make sum i". where if each x'th bit is on it represent x'th number of weights needed to make sum i.  
  to make j sum with i'th weight we must have already made (j-arr[i]) weight. 
*/

