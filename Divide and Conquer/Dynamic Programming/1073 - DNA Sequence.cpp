#include<bits/stdc++.h>
using namespace std ;
string s[15] , currStr ;
char str[101] ;
int cost[15][15] , n , caseno = 1 , unq = 1 ;
int dp[(1<<15)+1][15] , c[15];
int vis[(1<<15)+1][15] ;
int _next[201] ;

void failure(string s) {
  int q = 0 ;
  _next[q] = 0 ;
  for( int i = 1 ; i < (int)s.size() ; i++ ) {
    while( q > 0 && s[i] != s[q] )q = _next[q-1] ;
    if( s[i] == s[q] )q++ ;
    _next[i] = q ;
  }
}

bool kmp( string T , string P ) {
  failure(P) ;
  int q = 0 ;
  for( int i = 0 ; i < T.size() ; i++ ){
    while( q > 0 && P[q] != T[i] )q=_next[q-1] ;
    if( P[q] == T[i] )q++ ;
    if( q == P.size() ){
      return true ;
    }
  }
  return false ;
}
int calc( string s1 , string s2 ) {
  if( s2.size() <= s1.size() ) {
    if( kmp(s1,s2) )return -1 ;
  }
  failure(s2+"$"+s1) ;
  return _next[s2.size()+s1.size()+1-1] ;
}

int rec( int mask , int last ) {
  if( mask == ((1<<n)-1) )return 0 ;
  if( vis[mask][last] == unq ) return dp[mask][last] ;
  vis[mask][last] = unq ;
  int ret = 1<<28 ;
  int currCost , _last ;
  for( int i = 0 ; i < n ; i++ ) {
    if( !(mask&(1<<i)) ) {
      if( cost[last][i] == -1 )currCost = 0 ;
      else currCost = c[i]-cost[last][i] ;
      if( cost[last][i] == -1 )_last = last ;
      else _last = i ;
      ret = min( ret , rec( mask|(1<<i) , _last )+currCost ) ;
    }
  }
  return dp[mask][last] = ret ;
}
void pathPrint( int mask , int last , int ans ) {
  if( ans == 0 ) return ;
  int currCost = 0 , _last , __last , sub ;
  string lastStr = currStr ;
  string currMx = "Z" , tmp;
  int pos = 0 ;
  for( int i = 0 ; i < n ; i++ ) {
    if( (mask&(1<<i))==0 ) {
      if( cost[last][i] == -1 )currCost = 0 , __last = last ;
      else currCost = c[i]-cost[last][i] , __last = i ;
      int laterCost = rec( mask|(1<<i) , __last ) ;
      if( laterCost+currCost == ans ) {
        string tmp = lastStr ;
        if( cost[last][i] != -1 ){
          tmp += string(s[i].begin()+cost[last][i],s[i].end()) ;
          __last = i ;
        }else {
          __last = last ;
        }
        if( tmp < currMx ){
          currMx = tmp ;
          pos = i ;
          _last = __last ;
          sub = currCost ;
        }
      }
    }
  }
  //cerr << currStr << endl ;
  if( _last == pos )currStr+=string(s[pos].begin()+cost[last][pos],s[pos].end());
  pathPrint(mask|(1<<pos),_last,ans-sub) ;
  return ;
}

int main() {
  //cout << bool(string("CAGCGATAGGTGT") < string("CAGCGATGGTGTA")) << "\n" ;
  //cout << string("CAGCGATAGGTGT").size() << " " string("CAGCGATGGTGTA").size() << "\n" ;
  int cases , caseno = 1 ;
  scanf("%d",&cases ) ;
  while( cases -- ) {
    scanf("%d",&n) ;
    for( int i = 0 ; i < n ; i++ ) {
      scanf("%s",str) ;
      s[i] = str ;
      c[i] = s[i].size() ;
      //cerr << s[i] << "|" ;
    }//cerr << "\n" ;

    for( int i = 0 ; i < n ; i++ ) {
      for( int j = 0 ; j < n ; j++ ) {
        if( i == j )continue ;
        cost[i][j] = calc(s[i],s[j]) ;
      }
    }
    int mnSize = 1<<28 ;
    pair<int,int> idx ;
    int initCost = 0 , last ;
    for( int i = 0 ; i < n ; i++ ) {
      for( int j = 0 ; j < n ; j++ ) {
        if( i ==  j ) continue ;
        if( cost[i][j] == -1 )initCost = c[i] , last = i ;
        else initCost = c[i]+c[j]-cost[i][j] , last = j ;
        int tmp = rec((1<<i)|(1<<j),last)+initCost ;
        if( tmp < mnSize ){
          mnSize = tmp ;
          idx = make_pair(i,j) ;
        }
      }
    }

    string ansString = "" ;
    ansString = char(221) ;
    for( int i = 0 ; i < n ; i++ ) {
      for( int j = 0 ; j < n ; j++ ) {
        if( i == j ) continue ;
        if( cost[i][j] == -1 )initCost = c[i],last=i ;
        else initCost = c[i]+c[j]-cost[i][j],last=j ;
        int ans = rec((1<<i)|(1<<j),last)+initCost ;
        if( ans == mnSize ) {
          currStr = "" ;
          if( cost[i][j] == -1 ){
            currStr = s[i] ;
            last = i ;
          }
          else {
            currStr = s[i]+string( s[j].begin()+cost[i][j] , s[j].end() ) ;
            last = j ;
          }
          //cerr << " ---> current str " << currStr << " " << i << " " << j << "\n" ;
          pathPrint( (1<<i)|(1<<j) , last , ans-(initCost) ) ;
          if( currStr < ansString ) {
            ansString = currStr ;
          }
        }
      }
    }
    cout << "Case " << caseno++ << ": " << ansString << "\n" ;
    unq++ ;
  }
  return 0 ;
}
