#include<bits/stdc++.h>
using namespace std;
string s ;
long long mod = 1000000007 ;
long long dp[1001][1001] ;
int vis[1001][1001] ;
int gc ;

long long rec( int idx , int emptyForD ){
  if( idx == s.size() ){
    return emptyForD==0 ;
  }
  if( vis[idx][emptyForD] == gc ){
    return dp[idx][emptyForD] ;
  }
  vis[idx][emptyForD] = gc ;
  long long ret = 0 ;
  if( s[idx] == 'E' ) ret = rec( idx+1 , emptyForD ) ;
  else if( s[idx] == 'U' ) {
    ret += rec( idx+1 , emptyForD+1 ) ;
    ret %= mod ;
    if( emptyForD )ret += ((long long)emptyForD*rec( idx+1 , emptyForD-1+1 ))%mod ;
    ret %= mod ;
  }else if( s[idx] == 'D' ){
    if( emptyForD )ret += emptyForD*rec( idx+1 , emptyForD-1+1 ) ;
    ret %= mod ;
    if( emptyForD )ret += ((emptyForD*emptyForD)%mod)*rec( idx+1 , emptyForD-1 ) ;
    ret %= mod ;
  }
  return dp[idx][emptyForD] =ret ;
}

int main(){
  ios_base::sync_with_stdio(0) ;
  cin.tie(0) ;
  int cases , caseno =1 ;
  cin >> cases ;
  while( cases -- ){
    cin >> s ;
    gc++ ;
    cout << "Case " << caseno++ << ": " << rec( 0 , 0 ) << "\n" ;
  }
  return 0;
}
/*
  emptyForD = number of empty space for D.
  U - > previously down;
          so 1. now we can create a new empty space for a D to take this position.
                  --> creating an empty space means also this amount of U must be placed later
                      or a D must take this position.
          or 2. we have still emptyForD number of U to be downed in our hand. Also now, current
                U must be downed and we can place U number of upper unused sign here to place.
                now using one U we have emptyForD-1 number of U to be downed. but current positioned U
                must be downed. so we have emptyForD-1+1 number of U to be downed for next state.
  D - > previously up;
          so 1. This D must be go up. We have emptyForD number of empty space for this D to go.
          or 2. a D may go up and a U may do down simultaniously. This could be possible
                emptyForD*emptyForD times. For this one empty place reduced and emptyForD becomes emptyForD-1.
*/

