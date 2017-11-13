#include<bits/stdc++.h>
using namespace std ;
int start , en , maxOne , idealNum , k , gc;
string s , idealSNum ;
pair<long long,long long> dp[31][2][31][31][3][7] ;
int vis[31][2][31][31][3][7] ;
pair<int,long long> rec( int idx , int perm , int diff , int nOne , int three , int seven ) {
  if( idx == s.size() ) {
    return make_pair(three == 0 && seven != 0,0) ;
  }
  if( vis[idx][perm][diff][nOne][three][seven] == gc ) {
    return dp[idx] [perm][diff][nOne][three][seven] ;
  }
  vis[idx][perm][diff][nOne][three][seven] = gc ;
  int lim = perm ? 1 : s[idx]-'0' ;
  int new_perm , new_diff , new_nOne ;
  int revpos = s.size()-1-idx ;
  pair<int,long long> ret = make_pair(0,0); ;
  for( int i = 0 ; i <= lim ; i++ ) {
    new_perm = bool( perm || (i<(s[idx]-'0')) );
    new_diff = diff + (i != (idealSNum[idx]-'0')) ;
    new_nOne = nOne + i ;
    if( new_diff > k || new_nOne > maxOne ) continue ;
    pair<long long,long long>tmp = rec( idx + 1 , new_perm , new_diff , new_nOne , (three+(1<<revpos)*i)%3 , (seven+(1<<revpos)*i)%7 ) ;
    ret.first += tmp.first ;
    ret.second += tmp.second + ((long long)tmp.first)*(1LL<<revpos)*(long long)i ;
  }
  return dp[idx][perm][diff][nOne][three][seven] = ret ;
}
string calc(int p) {
  if( p == 0 ) return "0" ;
  string s = "" ;
  while( p > 0 ) {
    s += (p%2+'0') ;
    p/=2 ;
  }
  reverse(s.begin(),s.end()) ;
  return s ;
}
int main() {
  ios_base::sync_with_stdio(0) ;
  cin.tie(0) ;
  int cases , caseno = 1  ;
  cin >> cases ;
  while( cases -- ) {
    cin >> start >> en >> maxOne >> idealNum >> k ;
    string tmp = calc(idealNum) ;
    start -- ;
    pair<int,long long> ans1 , ans2 ;
    if( en <= 0 ) ans1 = make_pair(0,0);
    else {
      s = calc(en) ;
      reverse(s.begin(),s.end()) ;
      idealSNum = tmp ;
      reverse(idealSNum.begin(),idealSNum.end() ) ;
      while( idealSNum.size() != s.size() ){
        if( idealSNum.size() > s.size() )s+= "0" ;
        else idealSNum += "0" ;
      }
      reverse(idealSNum.begin(),idealSNum.end() ) ;
      reverse(s.begin(),s.end()) ;
      //cout << s << " " << idealSNum << "\n" ;
      gc++ ;
      ans1 = rec(0,0,0,0,0,0) ;
    }
    if( start <= 0 ){
      ans2 = make_pair(0,0); ;
    } else {
      s = calc(start) ;
      reverse(s.begin(),s.end()) ;
      idealSNum = tmp ;
      reverse(idealSNum.begin(),idealSNum.end() ) ;
      while( idealSNum.size() != s.size() ){
        if( idealSNum.size() > s.size() )s+= "0" ;
        else idealSNum += "0" ;
      }
      reverse(idealSNum.begin(),idealSNum.end() ) ;
      reverse(s.begin(),s.end()) ;
      gc++ ;
      //cout << s << " " << idealSNum << "\n" ;
      ans2 = rec(0,0,0,0,0,0) ;
    }
    cout << "Case " << caseno++ << ": " << ans1.second-ans2.second << "\n" ;
  }
  return 0 ;

}

