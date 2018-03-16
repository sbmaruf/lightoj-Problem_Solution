#include<bits/stdc++.h>
using namespace std ;
int m , n , w ;
#define MAX 204
vector<int>G[MAX] ;
int par[MAX] ;
int cost[MAX][MAX] ;

void insert( int u , int v , int w ) {
    G[u].push_back( v ) ;
    G[v].push_back( u ) ;
    cost[u][v] = w ;
}

int run( int source , int sink ) {
    memset( par  , -1 , sizeof par ) ;
    queue<pair<int,int> >Q ;
    Q.push( {source,(1<<30)} );
    while( !Q.empty() ){
        pair<int,int> p = Q.front() ;
        Q.pop() ;
        int u = p.first ;
        int mn = p.second ;
        for( int i = 0 ; i < G[u].size() ; i++ ){
            int v = G[u][i] ;
            if( cost[u][v] > 0 && par[v] == -1 ){
                par[v] = u ;
                mn = min( mn , cost[u][v] ) ;
                if( v == sink ) return mn ;
                Q.push({v,mn}) ;
            }
        }
    }
    return 0 ;
}

int main(){

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ){

        scanf("%d%d",&m,&n) ;

        memset( cost , 0 , sizeof cost ) ;
        int source = 0 ;
        int sink = 203 ;
        int sum = 0 ;
        for( int i = 0; i < MAX ;i++ )G[i].clear() ;

        for(int i = 0 ; i < m ; i++ ){
            scanf("%d",&w) ;
            insert( source , i+1 , w ) ;
            sum += w ;
        }

        for( int j = 0 ; j < n ; j++ ){
            scanf("%d",&w) ;
            insert( j+101 , sink , w ) ;
        }

        for( int i = 0 ; i < m ; i++ ){
            int p ;
            scanf("%d",&p) ;
            for( int j = 0 ;j < p ; j++ ){
                scanf("%d",&w) ;
                insert(i+1,w+100,1<<30) ;
            }
        }

        int local_ans = 0 ;
        int global_ans = 0 ;
        while( local_ans = run(source,sink) ){
            global_ans += local_ans ;
            for( int i = sink ; i != source ; i = par[i] ) {
                cost[par[i]][i] -= local_ans ;
                cost[i][par[i]] += local_ans ;
            }
        }
        cout << "Case " << caseno++ << ": " << sum - global_ans <<"\n" ;
    }
    return 0 ;

}

