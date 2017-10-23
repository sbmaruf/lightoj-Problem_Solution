#include<bits/stdc++.h>
using namespace std;
#define NODES 50000+1
#define EDGES 100000+1
#define LGNODES 20
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


int N , M , u , v , w , q ;
struct node {
  int u , w ;
  node() {}
  node(int _u , int _w ) {
    u = _u , w = _w ;
  }
};
struct edges {
  int u , v , w ;
  edges() {}
  edges( int _u , int _v , int _w ) {
    u = _u , v = _v , w = _w ;
  }
  bool operator < ( const edges & r ) const {
    return w < r.w ;
  }
};
vector<node>G[NODES] ;
edges arr[EDGES] ;
int par[NODES] , _rank[NODES] ;

int findParent( int p ) {
  return (par[p]==p)?p:par[p]=findParent(par[p]) ;
}

void mergeNode( int l , int r ) {
  if( _rank[l] > _rank[r] )par[r] = l ;
  else par[l] = r ;
  if(_rank[l]==_rank[r]) _rank[r]++;
}

void biuldTree() {

  sort( arr , arr + M ) ;
  for( int i = 0 ; i <= N ; i++ ) {
    par[i] = i , _rank[i] = 0 ;
  }
  int treeEdges = N-1 , u , v ;
  for( int i = 0 ; i < M && treeEdges ; i++ ) {
    u = findParent( arr[i].u ) ;
    v = findParent( arr[i].v ) ;
    if( u != v ) {
      mergeNode( u , v ) ;
      //par[u] = par[v] ;
      G[arr[i].u].push_back(node(arr[i].v,arr[i].w)) ;
      G[arr[i].v].push_back(node(arr[i].u,arr[i].w)) ;
      treeEdges -- ;
    }
  }

}
int MX[NODES][LGNODES] , ST[NODES][LGNODES] ;
int L[NODES] ;
void dfs(int u , int bc , int level , int mx ) {
  MX[u][0] = mx , ST[u][0]=bc , L[u] = level;
  for( int i = (int)G[u].size()-1 ; i >= 0 ; i-- ) {
    int v = G[u][i].u ;
    if( v == bc ) continue ;
    dfs( v , u , level+1 , G[u][i].w ) ;
  }
}
void preProcessLCA() {
  memset( ST , -1 , sizeof ST ) ;
  memset( MX , 0 , sizeof MX ) ;
  dfs(1,-1,0,0) ;
  for( int j = 1 ; (1<<j) <= N ; j++ ) {
    for( int i = 1 ; i <= N ; i++ ) {
      if( ST[i][j - 1] != -1 ) {
        MX[i][j] = max( MX[i][j - 1] , MX[ST[i][j - 1]][j - 1] ) ;
        ST[i][j] = ST[ST[i][j - 1]][j - 1] ;
      }
    }
  }
}

int queryLCA(int s , int t) {
  if( L[s] < L[t] ) swap( s , t ) ;
  int ret = -1 ;
  for( int i = 19 ; i >= 0 ; i-- ) {
    if( (L[s] - (1<<i)) >= L[t] ) {
      ret = max( ret , MX[s][i] ) ;
      s = ST[s][i] ;
    }
  }

  if( s == t ) return ret ;
  for( int i = 19 ; i >= 0 ; i-- ) {
    if( ST[s][i] != -1 ) {
      if( ST[s][i] != ST[t][i] ) {
        ret = max( ret , MX[s][i] );
        s = ST[s][i] ;
        ret = max( ret , MX[t][i] );
        t = ST[t][i] ;
      }
    }
  }
  ret = max( ret , MX[s][0] ) ;
  ret = max( ret , MX[t][0] ) ;
  return ret ;
}

int main() {

  Input read;
  read.grabBuffer() ;

  int cases , caseno = 1 ;
  cases = read.Int() ;
  while( cases -- ) {
    N = read.Int() ;
    M = read.Int() ;
    for( int i = 0 ; i < NODES ; i++ ) {
      G[i].clear() ;
    }
    for( int i = 0 ; i < M ; i++ ) {
      u = read.Int() ;
      v = read.Int() ;
      w = read.Int() ;
      arr[i] = edges(u,v,w) ;
    }

    biuldTree() ; // kruskal.
    preProcessLCA() ;

    q = read.Int() ;
    cout << "Case " << caseno++ << ":\n" ;
    while( q -- ) {
      int s , t ;
      s = read.Int() ;
      t = read.Int() ;
      cout << queryLCA(s,t) << "\n" ;
    }
  }
  return 0;
}

