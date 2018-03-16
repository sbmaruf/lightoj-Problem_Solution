#include<bits/stdc++.h>
using namespace std ;
vector<int>G[57+1] ;
int cost[57+1][57+1] ;
int par[57+1] ;
bool vis[57+1]  ;
void insert(int u , int v , int w ) {
    G[u].push_back(v) ;
    G[v].push_back(u) ;
    cost[u][v] += w ;
    cost[v][u] = 0 ;
}

int run( int source , int sink ) {

    memset( vis , 0 , sizeof vis  ) ;

    queue< int >Q ;
    Q.push( source ) ;

    while( !Q.empty() ) {

        int u = Q.front() ;
        Q.pop() ;

        for( int i = 0 ; i < G[u].size() ; i++ ) {
            int v =  G[u][i] ;
            if( vis[v] == 0 && cost[u][v] > 0 ) {
                vis[v] = 1 ;
                par[v] = u ;
                if( v == sink )return 1 ;
                Q.push( v ) ;
            }
        }
    }
    return 0 ;
}

int main() {

    int cases , caseno =1  ;
    scanf("%d",&cases ) ;
    string s , s1 ;
    map<string , int>mp ;

    while( cases -- ) {

        int N , M ;
        scanf("%d%d",&N,&M) ;

        memset( cost , 0 , sizeof cost ) ;

        int nodeNum = 51 ;
        int source = 0 ;
        int sink = 57 ;
        mp.clear() ;

        for( int i = 1 ; i <= M ; i++ ) {


            cin >> s >> s1 ;

            if( mp.find(s) == mp.end() ) {
                mp[s] = nodeNum++ ;
                //cout << s << " " << mp[s] << endl ;
            }
            if( mp.find(s1) == mp.end() ) {
                mp[s1] = nodeNum++ ;
                //cout << s1 << " " << mp[s1] << endl ;
            }

            int t1 = mp[s];
            int t2 = mp[s1];

            insert( i , t1 , 1 ) ;
            insert( i , t2 , 1 ) ;
            insert( source , i , 1 ) ;
            if( cost[t1][sink] == 0  ) {
                insert( t1 , sink , N ) ;
            }
            if( cost[t2][sink] == 0  ) {
                insert( t2 , sink , N ) ;
            }


        }

        int local_ans ;
        int global_ans = 0 ;
        while( local_ans = run(source ,sink) ) {
            global_ans ++ ;
            int mn = 1<<30 ;
            for( int i = sink ; i != source ; i = par[i] ) {
                cost[par[i]][i] -= 1 ;
                cost[i][par[i]] += 1 ;
            }
        }

        if( global_ans == M )cout << "Case " << caseno++ << ": " << "YES\n" ;
        else                 cout << "Case " << caseno++ << ": " << "NO\n" ;

        for( int i = 0; i < 201 ; i++ )G[i].clear() ;
    }

    return 0 ;

}

