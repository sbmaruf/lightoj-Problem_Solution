#include<bits/stdc++.h>
using namespace std ;
string s ;
int arr[2000+2][2000+2] , n , m ;
int Set[2000+2]  ;
int idx = 0 , frnt ;
int val , len ;
int histogram( int arr[] , int n ) {
  int ret = -(1LL<<60) ;
  idx = 0 ;
  int i = 0 ;
  while( i < n ) {
    while( (idx == 0 || arr[Set[idx-1]]<= arr[i] ) && i < n ) {
      Set[idx++]=i++ ;
    }
    while( idx > 0 && (i<n?arr[i]<arr[Set[idx-1]]:1) ) {
      frnt = Set[idx-1] ;
      idx--;
      val = arr[frnt] ;
      len = idx==0?i:i-Set[idx-1]-1 ;
      if( len*val > ret ) ret = len*val ;
    }
  }
  return ret ;
}

int main() {

  ios_base::sync_with_stdio(0);
  cin.tie() ;
  int cases , caseno = 1 ;
  cin >> cases ;
  while( cases -- ) {
    cin >> m >> n  ;
    int ans = -1 ;
    for( int i = 0; i < m ; i++ ){
      cin >> s ;
      for( int j = 0 ; j < n ; j++ ){
        arr[i][j] = !(s[j]-'0') ;
        if( i ){
          if( arr[i-1][j] && arr[i][j] ){
            arr[i][j] += arr[i-1][j] ;
          }
        }
      }
      ans = max( ans , histogram(arr[i],n) ) ;
    }
    cout << "Case " << caseno++ << ": " << ans << "\n" ;
  }

  return 0 ;
}

