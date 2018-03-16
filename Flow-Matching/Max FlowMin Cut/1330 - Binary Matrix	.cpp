#include<bits/stdc++.h>
using namespace std;
#define MAX 103
vector<int>G[MAX] ;
int source = 0 , sink = MAX-1;
int cost[MAX][MAX] ;
int par[MAX] ;

bool run() {
    memset( par , -1 , sizeof par ) ;
    queue<int>Q ;
    Q.push( source ) ;
    par[source] = source ;
    while( !Q.empty() ) {
        int u = Q.front() ;
        Q.pop() ;
        for(int i = G[u].size()-1 ; i >= 0 ; i-- ) {
            int v = G[u][i] ;
            if( par[v] == -1 && cost[u][v] > 0 ) {
                par[v]=u ;
                if( v == sink )return 1 ;
                Q.push(v) ;
            }
        }
    }
    return 0 ;
}

void insert(int u,int v,int w) {
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    cost[u][v] = w ;
}

int main() {
    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        for( int i = 0 ; i < MAX ; i++ )G[i].clear() ;
        memset( cost , 0 , sizeof cost ) ;

        int m , n ,s1=0,s2=0;
        scanf("%d%d",&m,&n);
        for( int i = 1 ; i <= m ; i++ ) {
            int p ;
            scanf("%d",&p) ;
            insert( source , i , p ) ;
            s1+=p;
        }
        for( int i = 1 ; i <= n ; i++ ) {
            int p ;
            scanf("%d",&p) ;
            s2+=p;
            insert( i+50 , sink , p ) ;
            for(int j = 1 ; j <= m ; j++ ) {
                insert( j , i+50 , 1 ) ;
            }
        }
        if( s1 != s2 ) {
            cout << "Case " << caseno++ << ": impossible\n" ;
        } else {
            int local_ans = 0 , global_ans = 0 ;
            while( local_ans = run() ) {
                global_ans += local_ans ;
                for( int i = sink ; i!= source ; i = par[i] ) {
                    cost[par[i]][i] -= local_ans ;
                    cost[i][par[i]] += local_ans ;
                }
            }
            if( global_ans != s1 )cout << "Case " << caseno++ << ": impossible\n" ;
            else {
                cout << "Case " << caseno++ <<":\n" ;
                for( int i = 1 ; i <= m ; i++ ) {
                    for( int j = 1 ; j <= n ; j++ ) {
/*
                        cout << endl << endl ;
                        for( int i = 1 ;i <= m ; i++ ){
                            cout << cost[source][i] << endl ;
                        }cout << endl << endl ;

                        cout << endl << endl ;
                        for( int i = 1 ; i <= m ; i++ ){
                            for( int j = 1 ; j <= n ; j++ ){
                                cout << cost[i][j+50] << endl ;
                            }
                        }cout <<endl << endl ;

                        cout << endl << endl ;
                        for( int i = 1 ;i <= n ; i++ ){
                            cout << cost[i+50][sink] << endl ;
                        }cout << endl << endl ;
*/

                        if( cost[i][j+50] == 1 )cout << 0 ;
                        else {
                            cost[source][i] = 1 ;
                            cost[j+50][sink] = 1 ;
                            int local_ans = 0 ;
                            local_ans = run() ;
                            if( local_ans ) {
                                cout << 0;
                                for( int i = sink ; i!= source; i = par[i] ) {
                                    cost[par[i]][i] -= local_ans ;
                                    cost[i][par[i]] += local_ans ;
                                }
                            } else cout << 1 , cost[source][i] -- ,cost[j+50][sink] -- ;
                        }
                        cost[i][j+50] =0 ,cost[j+50][i] = 1 ;
                    }
                    puts("") ;
                }
            }
        }
    }
    return 0;
}

