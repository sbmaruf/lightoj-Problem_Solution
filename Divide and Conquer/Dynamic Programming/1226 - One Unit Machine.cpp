#include<bits/stdc++.h>
using namespace std ;

#define MOD 1000000007
long long fact[1000000+8] ;
int n , arr[1000000+8] ;

void precalc(){
  fact[0] = 1  ;
  for( long long i = 1 ; i < 1000008 ; i++ ){
    fact[i] = fact[i-1]*i ;
    fact[i] = fact[i]%MOD ;
  }
}

long long _pow( long long b , long long p ){
  if( p == 0 ) return 1LL ;
  else if( p&1 )return (b*_pow( b , p-1 ))%MOD ;
  else {
    long long ret = _pow( b , p>>1 )%MOD;
    return (ret*ret)%MOD ;
  }
}

long long nCr( long long n , long long r ){
  long long neu = fact[n] ;
  long long den = (fact[r]*fact[n-r])%MOD ;
  return (neu*_pow( den , MOD-2 ))%MOD ;
}

int main() {

  ios_base::sync_with_stdio(0) ;
  cin.tie( NULL ) ;

  precalc() ;

  int cases ,caseno =1 ;
  cin >> cases ;
  while( cases -- ){

    cin >> n ;

    int tot = 0 ;
    for( int i = 0 ;i < n ;i++ ){
      cin >> arr[i] ;
      tot += arr[i] ;
    }

    long long ans = 1 , sum = 0 ;
    for( int i = n-1 ; i>= 0 ; i-- ){
      ans *= nCr(tot-sum-1,arr[i]-1) ;
      ans %= MOD ;
      sum += arr[i] ;
    }

    cout << "Case " << caseno++ << ": " << ans << "\n" ;
  }
  return 0 ;
}

