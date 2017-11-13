#include<bits/stdc++.h>
using namespace std ;
int arr[100000+5] , I[100000+5] , L[100000+5] ;

int bin_search(int lo , int hi , int val ) {
  int mid;
  while( lo<=hi ) {
    mid = ( lo + hi ) / 2;
    if( I[mid] > val )lo = mid+1 ;
    else hi = mid-1 ;
  }
  return lo ;
}
inline int readInt() {
  int ip = getchar_unlocked(), ret = 0, flag = 1;
  for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
    if(ip == 45) {
      flag = -1;
      ip = getchar_unlocked();
      break;
    }
  }
  for(; ip > 47 && ip < 58; ip = getchar_unlocked())
    ret = ret * 10 + ip - 48 ;
  return flag * ret;
}

int LisNlogK(int n) {
  int i;
  I[0] = (1<<30);
  for( i = 1 ; i <= n; i++ )
    I[i] = -(1<<30);
  int LisLength = 0;
  for( i = n-1; i >= 0 ; i-- ) {
    int pos = bin_search(0,LisLength,arr[i]) ;
    LisLength = max( LisLength , pos );
    I[pos] = arr[i];
    L[i] = pos ;
  }
  return LisLength;
}
int main() {
  //freopen("in.txt","r",stdin) ;
  int cases , caseno = 1 ;
  //cin >> cases ;
  cases = readInt() ;
  while( cases -- ) {
    int n , q ;
    //cin >> n >> q ;
    n = readInt() ;
    q = readInt() ;
    for( int i = 0 ; i < n ; i++ ) {
      //cin >> arr[i] ;
      arr[i] = readInt() ;
    }
    int lisLen = LisNlogK(n) ;
    cout << "Case " << caseno++ << ":\n" ;
    while( q -- ) {
      int tmp ;
//      cin >> tmp ;
      tmp = readInt() ;
      if( tmp > lisLen )cout << "Impossible\n" ;
      else {
        int bc ;
        for( int i = 0 ; i < n ; i++ ) {
          if( L[i]>= tmp ) {
            bc = arr[i] ;
            cout << arr[i] ;
            tmp -- ;
            for( int j = i+1 ; j < n && tmp > 0 ; j++ ) {
              if( arr[j] > bc && L[j] >= tmp ) {
                cout << " " << arr[j] ;
                bc = arr[j] ;
                tmp -- ;
              }
            }
            cout << "\n" ;
            break ;
          }
        }
      }
    }
  }
  return 0 ;
}

/*
8
10 11
8 1 9 8 3 4 6 1 5 2
3 2 4 3 2 1
*/

