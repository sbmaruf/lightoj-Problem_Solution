#include<bits/stdc++.h>
#define MAX 101
using namespace std ;
int n , m ;
pair<int,int> arr[MAX] ;
bool dp[MAX][MAX][MAX] ;
int vis[MAX][MAX][MAX] ;
int hi,lo,mid,gc;

bool rec( int pos , int ntsk1 , int ntsk2 ) {
  if( ntsk1 == 0 && ntsk2 == 0 )return 1 ;
  if( pos == n ) return 0 ;
  if( vis[pos][ntsk1][ntsk2] == gc ) {
    return dp[pos][ntsk1][ntsk2] ;
  }
  vis[pos][ntsk1][ntsk2] = gc ;
  bool ret = 0 ;
  for( int i = 0 ; i <= ntsk1 && i*arr[pos].first <= mid ; i++ ) {
    int tsk2rem = (mid - (i*arr[pos].first))/arr[pos].second  ;
    tsk2rem = min( ntsk2 , tsk2rem ) ;
    ret |= rec(pos+1,ntsk1-i,ntsk2-tsk2rem) ;
    if( ret ) break ;
  }
  return dp[pos][ntsk1][ntsk2] = ret ;
}

bool ok() {
  gc++ ;
  return rec(0,m,m) ;
}

int main() {
  ios_base::sync_with_stdio(0) ;
  cin.tie(0) ;
  int cases , caseno = 1;
  cin >> cases ;
  while( cases -- ) {
    cin >> n >> m ;
    for( int i = 0 ; i < n ; i++ ) {
      cin >> arr[i].first >> arr[i].second ;
    }
    lo = 0 , hi = 50000 ;
    while( hi-lo >= 4 ) {
      mid = (lo+hi)/2 ;
      if( ok() ) {
        hi = mid ;
      } else lo = mid ;
    }
    mid = lo ;
    while(mid<=hi) {
      if( ok() ) {
        cout << "Case " << caseno++ << ": " << mid << "\n" ;
        break ;
      }
      mid++;
    }
  }

  return 0 ;
}

