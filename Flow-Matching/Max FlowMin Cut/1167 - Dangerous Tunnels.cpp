#include<bits/stdc++.h>
using namespace std ;
#define MAX 205
vector<int>G[MAX] ;
int cost[MAX][MAX] ;
int cap[MAX][MAX] ;
int LIM[MAX][MAX] ;
int par[MAX] ;
int k,source,sink ;
void insert( int u , int v , int w ) {
    G[u].push_back( v ) ;
    G[v].push_back( u ) ;
    cost[u][v] = w ;
}

int run( int source , int sink , int mid ) {

    memset( par , -1 , sizeof par ) ;
    queue< int > Q ;
    Q.push( source ) ;

    while( !Q.empty() ) {
        int u = Q.front() ;
        Q.pop() ;
        for( int i = 0 ; i < G[u].size() ; i++ ) {
            int v = G[u][i] ;
            if( par[v] == -1 && cap[u][v] > 0 && LIM[u][v] <= mid ) {
                par[v] =  u ;
                if( v == sink )return 1  ;
                Q.push( v ) ;
            }
        }
    }
    return 0 ;
}

void pre(int mid ) {
    for(int i = 0 ; i < MAX ; i++ ) {
        for( int j = 0 ; j < MAX ; j++ ) {
            cap[i][j] = cost[i][j] ;
        }
    }
}
bool ok( int mid ) {
    pre(mid) ;
    int tot = 0 ;
    int local_ans = 0 ;
    while( run( source , sink , mid ) ) {
        for( int i = sink ; i != source ; i= par[i] ) {
            cap[par[i]][i] -=  1 ;
            cap[i][par[i]] +=  1 ;
        }
        tot++ ;
        if( tot == k )return true ;
    }
    return false ;
}

int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {
        int n  , t;
        scanf("%d%d",&n,&t) ;
        source = 0 ;
        sink = n+1 ;

        for(int i = 0 ; i <MAX ; i++ )G[i].clear() ;
        memset( cost , 0 , sizeof cost ) ;
        memset( LIM , 0 , sizeof LIM ) ;
        int temp = -1 ;
        insert( 0 , 102 , 1<<30 ) ;
        for( int i = 1 ; i <= n ; i++ )insert(i,102+i,1) ;
        for( int i = 0 ; i  < t ; i++ ) {
            int a , b , w ;
            scanf("%d%d%d",&a,&b,&w) ;
            int u = min( a , b ) ;
            int v = max( a , b ) ;
            temp = max( temp , w ) ;
            insert( 102+u , v , 1 ) ;
            LIM[102+u][v] = w ;
        }
        scanf("%d",&k) ;

        int lo = 0 ;
        int hi = temp ;
        int mid  ;

        while( hi-lo >= 3 ) {
            mid = (lo+hi)/2 ;
            if( ok( mid ) ) hi = mid ;
            else lo = mid  ;
        }
        bool f = 0 ;
        for( int i = lo ; i <= hi ; i++ ) {
            if( ok( i ) ) {
                cout << "Case " << caseno++ << ": " << i << "\n" ;
                f =1 ;
                break ;
            }
        }
        if( !f ) cout << "Case " <<caseno ++ <<  ": no solution\n" ;
    }
    return 0 ;
}

