#include<bits/stdc++.h>
using namespace std ;
#define MAX 10000+5

struct Pair{
  long long x,  y ;
  Pair(){}
  bool operator < ( const Pair &a ) const {
    return x < a.x ;
  }
};

Pair soldier[MAX] ;
Pair sniper_range[MAX] ;
long long k ,N , S , D ;

bool ok( long long mid ) {

  for( int i = 0 ; i < N ; i++ ) {
    long long ver = soldier[i].y-k+mid ;
    if( ver > D ) return 0 ;
    long long hor = (long long)sqrt(D*D - ver*ver) ;
    sniper_range[i].y = soldier[i].x-hor ;
    sniper_range[i].x = soldier[i].x+hor ;
  }

  sort( sniper_range , sniper_range + N ) ;

  int bc = 0 , fr = 1 ;
  int tot_sniper = 0 ;
  while( bc < N ) {
    tot_sniper ++ ;
    if( tot_sniper > S ) return 0 ;
    while( sniper_range[bc].x >= sniper_range[fr].y && fr < N )fr++ ;
    bc = fr;
    fr++ ;
  }
  if( tot_sniper > S ) return 0 ;
  return 1 ;
}

inline long long read() {
  long long ip = getchar_unlocked() , ret = 0 , flag = 1 ;
  for( ; ip < 48 || ip > 57 ; ip = getchar_unlocked() ) {
    if( ip == 45 ) {
      flag = -1 ;
      ip = getchar_unlocked() ;
      break ;
    }
  }
  for( ; ip > 47 && ip < 58 ; ip = getchar_unlocked() ) {
    ret = ret * 10 + ip -48 ;
  }
  return flag * ret ;
}

int main() {

  ios_base::sync_with_stdio(0) ;
  cin.tie() ;

  int cases , caseno =1 ;
  //cin >> cases ;
  cases = read() ;
  while( cases -- ) {

    //cin >> k >> N >> S >> D ;
    k = read() ; N = read() ; S = read() , D = read() ;
    for( int i = 0 ; i < N ; i++ ) {
      // cin >> soldier[i].x >> soldier[i].y ;
      soldier[i].x = read() , soldier[i].y = read() ;
    }

    long long lo = 0 , hi = D , mid ;
    while( hi-lo >= 3 ) {
      mid = (hi+lo)/2 ;
      if( ok(mid) ) lo = mid ;
      else hi = mid ;
    }
    bool f = 0 ;
    for( long long i = hi ; i >= lo ; i-- ) {
      if( ok( i ) ) {
        cout << "Case " << caseno++ << ": " << i << "\n" ;
        f =1 ;
        break ;
      }
    }
    if( !f )cout << "Case " << caseno++ << ": " << "impossible\n" ;

  }

  return 0 ;
}

