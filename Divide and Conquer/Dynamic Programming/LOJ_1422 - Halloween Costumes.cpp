#include<bits/stdc++.h>
using namespace std ;
int arr[100+5] , dp[105][105] ;
int n ;
 
int rec( int st ,  int en ) {
 
  if( en <= st )
    return 0 ;
 
  if( dp[st][en] != -1 )
    return dp[st][en] ;
 
  int ret = 1+rec( st+1 , en ) ;
  ret = min(ret , 1+rec( st , en-1 )) ;
  for( int i = st + 1 ; i <=en ;  i++ ) {
    if( arr[st]==arr[i] )
      ret = min( ret , 1+rec(st+1,i-1)+rec(i,en) ) ;
  }
 
  return dp[st][en] = ret ;
 
}
 
int main() {
 
  ios_base::sync_with_stdio(0);
  cin.tie(NULL) ;
 
  int cases , caseno =1 ;
  cin >> cases ;
  while( cases -- ) {
    cin >> n ;
    int cnt = 0 ;
    for( int i = 0 ; i < n ; i++ ) {
      cin >> arr[i] ;
      if( i > 0 && arr[i-1] == arr[i] )i--,n--;
    }
    memset( dp , -1 , sizeof dp ) ;
    //cout <<  n << " " << endl ;
    cout << "Case " << caseno++ << ": " << rec( 0 , n-1)+1 << '\n' ;
  }
 
  return 0 ;
 
}
 
 
/*
 
2
4
1 2 1 2
7
1 2 1 1 3 2 1
 
*/
