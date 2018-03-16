#include<bits/stdc++.h>
#define MAX 205
using namespace std ;
int N , D , w ;
char ch ;
vector<int> G[MAX] ;
int cap[MAX][MAX] ;
int cost[MAX][MAX] ;
int par[MAX] ;
int source , sink ;

void insert( int u , int v , int w ) {
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    cap[u][v] = w ;
}


int run( int source , int sink ) {
    memset( par , -1 , sizeof par ) ;
    queue<pair<int,int> >Q ;
    Q.push( {source , 1<<30} );
    while( !Q.empty() ) {
        pair<int,int> p = Q.front() ;
        Q.pop() ;
        int u = p.first ;
        int mn = p.second ;
        for( int i = 0 ; i <G[u].size() ; i++ ) {
            int v= G[u][i] ;
            if( cost[u][v] > 0 && par[v] == -1 ) {
                par[v] = u ;
                mn = min( cost[u][v] , mn ) ;
                if( v == sink )return mn ;
                Q.push( {v,mn} ) ;
            }
        }
    }
    return 0 ;
}

void prep(int mid) {

    for( int i = 0 ; i < MAX ; i++ ) {
        for( int j = 0;  j < MAX ; j++ ) {
            if( cap[i][j] <= mid || cap[i][j] == (1<<30) ) cost[i][j] = cap[i][j] ;
            else cost[i][j] = 0 ;
        }
    }

}
bool ok( int mid ) {
    prep(mid);
    int global_ans = 0 ;
    int local_ans = 0 ;
    while( local_ans = run( source , sink )) {
        global_ans ++ ;
        if( global_ans == 2 ) return true ;
        for( int i = sink ; i!= source ; i=par[i] ) {
            if( par[i] <= 100 && i > 100 ) cost[par[i]][i] -= local_ans ;
            cost[i][par[i]] += local_ans ;
        }
    }
    return false ;
}

int main() {

    int cases , caseno =1  ;
    scanf("%d",&cases ) ;
    while( cases -- ) {

        scanf("%d%d",&N,&D) ;

        source = 0 ;
        sink = 204 ;
        for( int i = 0 ; i < MAX ; i++ )G[i].clear() ;
        memset( cap , 0 , sizeof cap ) ;

        insert( source , sink , D) ;
        int tmp[N+1] ;
        for( int i = 1 ; i <= N ; i++ ) {
            scanf(" %c-%d",&ch,&tmp[i]) ;
            if( ch == 'B' ) {
                insert( i , i+100 , 1<<30 ) ;
            } else {
                insert( i , i+100 , 1 ) ;
            }
            insert( source , i , tmp[i] ) ;
            insert( i+100 , sink , D-tmp[i] ) ;
        }
        for( int i = 1 ; i <= N ; i++ ) {
            for( int j = i+1 ; j <= N ; j++ ) {
                insert( i+100 , j , tmp[j]-tmp[i] ) ;
            }
        }

        int lo = 0 ,hi = D , mid ;
        while( hi-lo >= 4 ) {
            int mid = (hi+lo)/2 ;
            if( ok( mid ) )hi = mid ;
            else lo = mid ;
        }
        bool f = 0 ;
        for( int i = lo ; i <= hi ; i++ ) {
            if( ok(i) ) {
                cout <<"Case " << caseno++ << ": " << i << "\n" ;
                f = 1  ;
                break ;
            }
        }
        if( !f )cout <<"Case " << caseno++ << ": " << D << "\n" ;

    }

    return 0 ;

}

/*

3
1 10
B-5
1 10
S-5
2 10
B-3 S-6

*/

