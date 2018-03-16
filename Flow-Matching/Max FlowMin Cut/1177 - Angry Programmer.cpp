#include<bits/stdc++.h>
using namespace std ;
#define MAX  (2*55)
vector<int>G[MAX] ;
int par[MAX] , arr[MAX] ;
int cost[MAX][MAX] ;
int source ,sink  ;
#define insert(u,v,w) G[u].push_back(v) ;G[v].push_back(u) ;cost[u][v] = w;
int run(){
    memset( par , -1 , sizeof par ) ;
    queue<pair<int,int> > Q;
    Q.push({source,(1<<30)});
    while( !Q.empty() ){
        int u = Q.front().first ;
        int mn = Q.front().second ;
        Q.pop();
        for( int i = 0 ;i < G[u].size() ; i++ ){
            int v = G[u][i] ;
            if( cost[u][v] > 0 && par[v] == -1 ) {
                par[v] = u ;
                mn = min( mn , cost[u][v] ) ;
                if( v == sink ) return mn ;
                Q.push( {v,mn} ) ;
            }
        }
    }
    return 0 ;
}
int main(){
    int cases , caseno = 1  ;
    scanf("%d",&cases ) ;

    while( cases -- ){

        for( int i = 0 ; i < MAX ; i++ )G[i].clear() ;
        memset(cost,0,sizeof cost) ;

        int M , W ;
        scanf("%d%d",&M,&W) ;
        insert(1,51,1<<30) ;
        for( int i = 0; i < M-2 ; i++ ){
            int a ;
            scanf("%d",&a) ;
            insert(i+1+1,50+i+1+1,a) ;
        }
        for( int i = 0 ; i < W ; i++ ){
            int a, b , c ;
            scanf("%d%d%d",&a,&b,&c) ;
            insert(a+50,b,c) ;
            insert(b+50,a,c) ;
        }
        source = 1 ;
        sink = M ;
        int local_ans = 0 ;
        int global_ans = 0 ;
        while( local_ans = run() ){
            global_ans += local_ans ;
            for( int i = sink ; i!= source ; i=par[i] ){
                cost[par[i]][i] -= local_ans ;
                cost[i][par[i]] += local_ans ;
            }
        }
        cout << "Case " << caseno++ << ": " << global_ans << "\n" ;
    }
}

