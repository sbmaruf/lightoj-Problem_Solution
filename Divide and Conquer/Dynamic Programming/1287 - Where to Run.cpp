#include<bits/stdc++.h>
using namespace std ;
int n , m , u , v , w ;
double dp[15][1<<15]  ;
vector<pair<int,int> >g[105] ;
double rec( int node , int mask ){

  if( dp[node][mask] > -1.0+1e-9 ){
    return dp[node][mask] ;
  }
  int cnt = 0 ;
  double ret = 0 ;
  for( int i = 0; i < (int)g[node].size() ; i++ ){
    int v = g[node][i].first ;
    int w = g[node][i].second ;
    if( (mask&(1<<v)) == 0 ){
      double temp = rec( v , mask|(1<<v) )  ;
      if( temp > -100.00+1e-9  ){
        ret += w + temp ;
        cnt ++ ;
      }
    }
  }
  if( cnt == 0 ){
    if( mask == ((1<<n)-1) )return 0.0 ;
    else return -123456789.0 ;
  }else {
    //E = (1/(cnt+1)*( 5+E ) [if stay for five minute] + (1/(cnt+1)*sum) [if do not stay for five minute] ;
    ret += 5 ;
    cnt ++ ;
    ret /= (double)cnt ;
    ret /= (1-(1/(double)cnt)) ;
  }
  return dp[node][mask] = ret ;
}

int main(){

  ios_base::sync_with_stdio(0);
  cin.tie(NULL) ;

  int cases , caseno = 1 ;
  scanf("%d",&cases ) ;

  while( cases -- ){

    scanf("%d%d",&n,&m) ;
    for( int i =0 ; i < m ; i++ ){
      scanf("%d%d%d",&u,&v,&w) ;
      g[u].push_back(make_pair(v,w)) ;
      g[v].push_back(make_pair(u,w)) ;
    }
    memset( dp , -1 , sizeof dp ) ;
    cout << "Case " << caseno++ << ": " ;
    double ans = rec( 0 , 0|(1<<0) ) ;
    if( ans+1e-9 < 0 )ans = 0 ;
    cout << fixed << setprecision(7) << ans << "\n" ;
    for( int i =0 ; i <= n ; i++ ){
      g[i].clear() ;
    }
  }
  return 0 ;
}

