
#include<bits/stdc++.h>
using namespace std ;
#define MAX 20000+5
struct Input {
#define maxBufSize (1 << 23)
#define maxStrSize (1 << 23)
  int bufSize, bufEnd, bufPos;
  char buffer[maxBufSize];
  void grabBuffer() {
    bufSize = (maxBufSize);
    bufPos = 0;
    bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
    buffer[bufEnd] = '\0';
  }
  bool bufEof() {
    return bufPos == bufEnd;
  }
  int getChar() {
    return buffer[bufPos++];
  }
  void skipWS() {
    while ((buffer[bufPos] == '\n' ||
            buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
      bufPos++;
  }
  int rUint() {
    int n = 0, x;
    skipWS();
    for (int x = getChar(); x <= '9' && x >= '0'; x = getChar())
      n = (n << 3) + (n << 1) + (x - '0');
    return n;
  }
  int Int() {
    int sign = 0, n = 0, x;
    skipWS();
    if (buffer[bufPos] == '-')
      sign = 1, getChar();
    for (x = getChar(); x <= '9' && x >= '0'; x = getChar())
      n = (n << 3) + (n << 1) + (x - '0');
    return sign == 0? n: -n;
  }
  inline bool isWhiteSpace(char x) {
    return x == ' ' || x == '\n' || x == '\t';
  }
  string rStr() {
    char result[maxStrSize];
    skipWS();
    int idx = 0, x;
    for (x = getChar(); !isWhiteSpace(x); x = getChar())
      result[idx++] = x;
    result[idx] = '\0';
    return result;
  }
  char rChar() {
    skipWS();
    return getChar();
  }
};
struct edge {
  int u , v ;
  edge() {}
  edge( int _u , int _v ) {
    u = _u , v = _v ;
  }
  bool operator != ( const edge & a )const {
    return !(u==a.u && v==a.v) ;
  }
};
struct _pair {
  int first , second ;
  _pair() {}
  _pair( int _first , int _second ) {
    first = _first , second = _second ;
  }
};

vector<_pair>g[MAX] ;
int _time , low[MAX] , disc[MAX] , vis[MAX] , comp[MAX] , deg[MAX] , isBridge[MAX] ;
edge arr[MAX] ;
void dfs(int u , int bc =-1 ) {
  vis[u] = 1 ;
  low[u] = disc[u] = ++_time ;
  for( int i = 0  ; i < (int)g[u].size() ; i++ ) {
    int v = g[u][i].first;
    if( v == bc ) continue ;
    if( vis[v] )low[u] = min( low[u] , disc[v] ) ;
    else {
      dfs(v,u) ;
      low[u] = min( low[u] , low[v] ) ;
      if( low[v] > disc[u] ) {
        isBridge[g[u][i].second]=1;
      }
    }
  }
}
void calcBridge() {
  memset(vis,0,sizeof vis) ;
  memset(isBridge,0,sizeof isBridge) ;
  _time = 0 ;
  dfs(0,-1) ;
}

void rec( int u , int bc , int noComp ) {
  vis[u] = 1 ;
  comp[u] = noComp ;
  for( int i = 0 ; i < (int)g[u].size() ; i++ ) {
    int v = g[u][i].first ;
    if( vis[v] == 0 && isBridge[g[u][i].second] == 0 ) {
      rec( v , u , noComp ) ;
    }
  }
}

int solve(int n,int m) {
  calcBridge();
  int noComp = 0 ;
  memset(vis,0,sizeof vis) ;
  for( int i =  0 ; i < n ; i++ ) {
    if( vis[i] == 0 ) {
      rec(i,-1,++noComp) ;
    }
  }
  memset( deg , 0 , sizeof deg ) ;
//cout << noComp << "\n" ;
//  for( int i = 0 ; i < 4 ; i++ ){
//    cout << comp[i] << " ";
//  }cout << endl ;
  for( int i = 0  ; i < m ; i++ ) {
    if( isBridge[i] ) {
//      cout << arr[i].u <<" " << arr[i].v <<  "\n" ;
//      cout << comp[arr[i].u] <<" " <<comp[arr[i].v] <<  "\n" ;
      deg[comp[arr[i].u]]++ ;
      deg[comp[arr[i].v]]++ ;
    }
  }
  long long ret = 0 ;
  for( int i = 1  ; i <= noComp ; i++ ) {
    //cout << deg[i] << " "<< endl ;
    ret += deg[i] == 1 ;
  }
  return (ret+1)/2LL ;
}

int main() {

  Input read;
  read.grabBuffer() ;

  int cases , caseno = 1 ;
  //cin >> cases ;
  cases = read.Int() ;
  while( cases -- ) {
    int n , m , u , v ;
    //cin >> n >> m ;
    n = read.Int() ;
    m = read.Int() ;
    for( int i =  0 ; i < m ; i++ ) {
      //cin >> u >> v ;
      u = read.Int() ;
      v = read.Int() ;
      g[u].push_back(_pair(v,i)) ;
      g[v].push_back(_pair(u,i)) ;
      arr[i]=edge(u,v) ;
    }
    cout << "Case " << caseno++ << ": " << solve(n,m) << "\n" ;
    for( int i = 0 ; i < MAX ; i++ ) {
      g[i].clear() ;
    }
  }

  return 0 ;
}
/*
1
6 7
1 0
1 3
3 4
0 2
4 5
4 1
3 0
Case 1: 1
*/
