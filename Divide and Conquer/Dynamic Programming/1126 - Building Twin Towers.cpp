#include<bits/stdc++.h>
using namespace std ;
int dp[2][500000+7] ,arr[101];
//int rec( int idx , int diff ){
//  if( idx == n && diff == 0 )return 0 ;
//  else if( idx == n ) return -(1<<30) ;
//  if( dp[idx][diff] != -1 )return dp[idx][diff] ;
//  int ret = rec( idx+1, diff );
//  ret = max( ret , rec(idx+1,abs(diff-arr[idx]))+arr[idx] ) ;
//  ret = max( ret , rec(idx+1,abs(diff+arr[idx]))+arr[idx] ) ;
//  return  dp[idx][diff] = ret ;
//}
int main(){

  int cases , caseno = 1;
  cin >> cases ;
  while( cases -- ){
    int n ;
    cin >> n ;
    int sum = 0 , val , curr = 0 , prev = 1 ;
    memset( dp , -1 , sizeof dp ) ;
    dp[prev][0] = 0 ;
    for( int i = 0 ; i < n ; i++ ){
      cin >> val ;
      sum += val ;
      for( int i = 0 ; i <= sum ; i++ )dp[curr][i] = dp[prev][i] ;
      for( int j = 0 ; j <= sum ; j++ ){
        if(dp[prev][j] != -1 ){
          dp[curr][abs(j-val)] = max( dp[curr][abs(j-val)] , dp[prev][j]+val ) ;
          dp[curr][abs(j+val)] = max( dp[curr][abs(j+val)] , dp[prev][j]+val ) ;
        }
      }
      swap(curr,prev) ;
    }
    if( dp[prev][0] == 0 )cout << "Case " << caseno++ << ": impossible\n" ;
    else cout << "Case " << caseno++ << ": " << (dp[prev][0]>>1) << "\n" ;
  }
  return 0 ;
}

