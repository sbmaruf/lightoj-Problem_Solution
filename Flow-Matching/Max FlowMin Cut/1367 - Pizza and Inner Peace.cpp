#include<bits/stdc++.h>
using namespace std ;
#define MAX 205
int N, M, ans[MAX] ;

struct edge {
  int v,ri,idx ;
  long long cap,low ;
  edge() {}
  edge(int _v,long long _cap,long long _low,int _ri,int _idx) {
    v=_v,cap=_cap,low=_low,ri=_ri,idx=_idx;
  }
};
vector<edge>g[MAX];
int source,sink,level[MAX],extraCap[MAX] ;
void addEdge(int u,int v,long long cap,long long low,int idx) {
  g[u].push_back(edge(v,cap,low,g[v].size(),idx));
  g[v].push_back(edge(u,0,0,g[u].size()-1,-1));
  return;
}
bool bfs() {
  memset(level,-1,sizeof(level));
  level[source]=0;
  queue<int>q;
  q.push(source);
  while(!q.empty()) {
    int s=q.front();
    q.pop();
    for(int i=0; i<(int)g[s].size(); i++) {
      if(level[g[s][i].v]==-1 && g[s][i].cap>0) {
        level[g[s][i].v]=level[s]+1;
        q.push(g[s][i].v);
      }
    }
  }
  return (level[sink]!=-1);
}
long long dfs(int src,long long minCap) {
  if(src==sink)return minCap;
  long long x=0,y=0;
  for(int i=0; i<(int)g[src].size(); i++) {
    if(g[src][i].cap<=0 || level[g[src][i].v]!=level[src]+1)continue;
    y=dfs(g[src][i].v,min(minCap-x,g[src][i].cap));
    x+=y;
    g[src][i].cap-=y;
    g[g[src][i].v][g[src][i].ri].cap+=y;
    if(x==minCap)break;
  }
  if(x==0)level[src]=0;
  return x;
}
long long dinic() {
  long long ret = 0 ;
  while( bfs() ) {
    ret += dfs(source,1LL<<60) ;
  }
  return ret;
}
int main() {
  int cases, caseno = 1 ;
  scanf("%d",&cases ) ;
  while( cases -- ) {
    scanf("%d%d",&N,&M) ;
    memset(extraCap,0,sizeof extraCap) ;
    source = 0, sink = N+1 ;
    for( int i = 0 ; i < M ; i++ ) {
      int u, v, Lk, Ck ;
      scanf("%d%d%d%d",&u,&v,&Lk,&Ck) ;
      addEdge(u,v,Ck-Lk,Lk,i) ;
      extraCap[v]+=Lk ;
      extraCap[u]-=Lk ;
    }
    long long flow_output = 0 ;
    for( int i = 1 ; i <= N ; i++ ) {
      if( extraCap[i] > 0 ) {
        flow_output += extraCap[i] ;
        addEdge(source,i,extraCap[i],0,1<<30) ;
      } else {
        addEdge( i, sink, -extraCap[i], 0, 1<<30 ) ;
      }
    }
    addEdge( N, 1, 1LL<<60, 0, 1<<30 ) ;
    long long _flow = dinic() ;
    if( flow_output != _flow ) {
      cout << "Case " << caseno++ << ": no\n" ;
      for( int i = source ; i <= sink ; i++ )g[i].clear() ;
      continue ;
    }
    cout << "Case " << caseno++ << ": yes\n" ;
    long long ans[M] ;
    for( int i = 1 ; i <= N ; i++ ) {
      for( int j = 0 ; j < g[i].size() ; j++ ) {
        if( g[i][j].idx >= 0 && g[i][j].idx < M ) {
          ans[g[i][j].idx] =  g[i][j].low + g[ g[i][j].v ][ g[i][j].ri ].cap ;
        }
      }
    }
    for( int i = 0 ; i < M ; i++ ) {
      cout << ans[i] << "\n" ;
    }
    for( int i = source ; i <= sink ; i++ )g[i].clear() ;
  }
  return 0;
}

