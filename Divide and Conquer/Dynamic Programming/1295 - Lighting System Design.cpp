#include<bits/stdc++.h>
using namespace std ;

struct node{
  int v , k , c , l ;
  node(){}
  node(int _v , int _k, int _c , int _l ){
    v = _v , k = _k , c = _c , l = _l ;
  }
  bool operator < ( const node & a ) const {
    return v > a.v ;
  }
};
node arr[1000+1] ;
int v , k , c , l , n ;
int dp[1000+1] ;

int rec( int idx ){
  if( idx == n )return 0 ;
  if( dp[idx] != - 1 ) return dp[idx] ;
  int ret = 1 << 30 , cost = arr[idx].k ;
  for( int i = idx ; i < n ; i++ ){
    cost += arr[idx].c*arr[i].l ;
    ret = min(ret , rec(i+1)+cost) ;
  }
  return dp[idx] = ret ;
}


int main(){

  int cases , caseno = 1;
  cin >> cases ;
  while( cases -- ){

    cin >> n ;
    for( int i = 0 ; i < n ; i++ ){
      cin >> arr[i].v >> arr[i].k >> arr[i].c >> arr[i].l ;
    }
    sort( arr , arr + n ) ;
    memset( dp , -1 , sizeof dp ) ;
    cout << "Case " << caseno++ << ": " <<  rec( 0 ) << "\n" ;
  }

  return 0 ;
}

