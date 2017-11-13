#include<bits/stdc++.h>
using namespace std ;
int n , m , A[100+5] , C[100+5] , visC[100000+5] , ans ;
bool vis[100000+5] ;
int main(){
  ios_base::sync_with_stdio(0) ;
  cin.tie(0) ;
  int cases , caseno = 1 ;
  cin >> cases ;
  while( cases -- ){
    cin >> n >> m ;
    for( int i = 0 ; i < n ; i++ ){
      cin >> A[i] ;
    }
    for( int i = 0 ; i < n ; i++ ){
      cin >> C[i] ;
    }
    memset( vis , 0 , sizeof  vis ) ;
    vis[0] = 1 ;
    for( int i = 0 ; i < n ; i++ ){
      for( int j = 0 ; j <= m ; j++ ){
        if( vis[j] == 1 ) visC[j] = 0 ;
        else visC[j] = 1<<28 ;
      }
      for( int j = 0 ; j <= m ; j++ ){
        if( vis[j] == 1 && A[i]+j <= m && visC[A[i]+j] > visC[j]+1 && visC[j] < C[i] ){
          vis[j+A[i]] = 1 ;
          visC[A[i]+j] = visC[j]+1 ;
        }
      }
    }
    int ans = 0 ;
    for( int i = 1 ; i <= m ; i++ ){
      ans += vis[i] == 1 ;
    }
    cout << "Case " << caseno++ << ": " << ans << "\n" ;
  }

  return 0 ;
}

