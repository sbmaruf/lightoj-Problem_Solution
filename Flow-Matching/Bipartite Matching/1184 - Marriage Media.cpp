#include<bits/stdc++.h>
using namespace std ;

struct node {
    int h , a , d ;
    node() {}
    node( int _h , int _a , int _d ) {
        h = _h ;
        a = _a ;
        d = _d ;
    }
};
node M[51] ;
node N[51] ;
vector<int>G[105] ;
int cost[105][105] ;
int par[105] ;

void insert( int u , int v , int w ) {
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    cost[u][v] = 1 ;
}

int run( int source , int sink ){
    queue<pair<int,int> > Q ;
    Q.push( { source , 1 << 30 } ) ;
    memset( par , -1 , sizeof( par ) ) ;
    while( !Q.empty() ) {
        int u = Q.front().first ;
        int mn = Q.front().second ;
        Q.pop() ;
        for( int i = 0 ; i < G[u].size() ; i++ ){
            int v = G[u][i] ;
            if( par[v] == -1 && cost[u][v] > 0 ){
                par[v] = u ;
                mn = min( mn , cost[u][v] ) ;
                if( v == sink ) return mn ;
                Q.push( {v,mn} ) ;
            }
        }
    }
    return 0 ;
}

int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        for( int i =0 ; i < 105 ; i++ ) G[i].clear() ;
        memset( cost , 0 , sizeof cost ) ;
        int m , n ;
        scanf("%d%d",&m,&n) ;
        int source = 0 ;
        int sink = 104 ;
        for( int i = 0 ; i < m ; i++ ) {
            int a , b , c ;
            scanf("%d%d%d",&a,&b,&c) ;
            M[i] = node( a , b , c ) ;
            insert( source , i+1 , 1 ) ;
        }
        for( int i =0 ; i < n ; i++ ) {
            int a , b , c ;
            scanf("%d%d%d",&a,&b,&c) ;
            N[i] = node( a , b , c ) ;
            insert( i+50+1 , sink , 1 );
        }
        for( int i = 0; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( abs( M[i].h-N[j].h )<=12 && abs( M[i].a-N[j].a )<=5 && ( M[i].d == N[j].d ) ) {
                    insert( i+1 , 50+j+1 , 1 ) ;
                }
            }
        }
        int global_ans = 0 ;
        while( run(source , sink ) ) {
            global_ans ++ ;
            for( int i = sink ; i != source ; i = par[i] ) {
                cost[par[i]][i] -= 1 ;
                cost[i][par[i]] += 1 ;
            }
        }
        cout << "Case " << caseno++ <<  ": " << global_ans << "\n" ;

    }
    return 0 ;
}

