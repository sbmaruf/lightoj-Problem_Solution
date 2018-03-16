#include<bits/stdc++.h>
using namespace std ;

struct Node {
    int nd , w , idx ;
    Node() {}
    Node(int _nd , int _w , int _idx ) {
        nd = _nd ;
        w = _w ;
        idx = _idx ;
    }
};

char s[102][102] ;
vector<Node> G[20100] ;
int parent[20100] ;
int IDX[20100] ;

void insert( int u , int v , int w ) {
    G[u].push_back( Node( v , w , G[v].size() ) ) ;
    G[v].push_back( Node( u , 0 , G[u].size()-1 ) ) ;
}

int run(int source , int sink ) {

    memset(parent,-1,sizeof parent ) ;
    queue< pair<int,int> >Q;
    int mn = INT_MAX ;
    Q.push( {source,mn} ) ;

    while( !Q.empty() ) {
        pair<int,int> p = Q.front() ;
        Q.pop() ;
        int u = p.first ;
        int mn = p.second ;
        for(int i = 0 ; i < G[u].size() ; i++ ) {
            int v = G[u][i].nd ;
            if( parent[v] == -1 && G[u][i].w > 0 ) {
                parent[v] = u ;
                IDX[v] = i ;
                mn = min( mn , G[u][i].w ) ;
                if( v == sink )return mn  ;
                Q.push( {v,mn}) ;
            }
        }
    }
    return 0 ;
}



int main() {

    //freopen("in.txt" , "r" , stdin ) ;

    int cases,caseno=1  ;
    scanf("%d",&cases ) ;

    while(cases -- ) {

        int N , M ;
        scanf("%d%d",&M,&N) ;

        int node[103][103] ;
        int extranode[103][103] ;
        int newNode = 1 ;

        int source  = 0 ;
        int sink = 20050 ;

        int flow_output = 0 ;
        for( int i= 0 ; i < M ; i++ ) {
            scanf(" %s",s[i]);
        }

        for( int i = 0 ; i < M ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                node[i][j] = newNode;
                extranode[i][j] = N*M+newNode ;
                newNode++ ;
            }
        }

        for( int i = 0 ; i < M ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                insert( node[i][j] , extranode[i][j] , 1 );
                if( i == 0 || j == 0 || j == N-1 || i == M-1 )
                    insert(extranode[i][j],sink,1<<30);
                if( s[i][j] == '*' )
                    insert(source,node[i][j],1<<30),flow_output++;

                int R = i-1 ;
                int C = j ;
                if( R >= 0 && C >= 0 && C <= N-1 && R <= M-1 ) {
                    insert( extranode[i][j] , node[R][C] , 1 <<30 ) ;
                }

                R = i ;
                C = j+1 ;
                if( R >= 0 && C >= 0 && C <= N-1 && R <= M-1 ) {
                    insert( extranode[i][j] , node[R][C] , 1 <<30 ) ;
                }
                R = i+1 ;
                C = j ;
                if( R >= 0 && C >= 0 && C <= N-1 && R <= M-1 ) {
                    insert( extranode[i][j] , node[R][C] , 1 <<30 ) ;
                }

                R = i ;
                C = j-1 ;
                if( R >= 0 && C >= 0 && C <= N-1 && R <= M-1 ) {
                    insert( extranode[i][j] , node[R][C] , 1 <<30 ) ;
                }
            }
        }


        int local_output = 0 , global_output = 0 ;
        while( local_output = run(source,sink) ) {
            global_output += local_output ;
            for( int i = sink ; i!=source ; i = parent[i] ) {
                G[parent[i]][IDX[i]].w -= local_output ;
                G[i][ G[parent[i]][IDX[i]].idx ].w += local_output ;
            }
        }
        //cout << global_output << " " << flow_output << endl ;
        if( global_output == flow_output )cout << "Case " << caseno++ << ": " << "yes\n" ;
        else cout << "Case " << caseno++ << ": " << "no\n" ;


        for( int i = 0 ; i < 20100 ; i++ )G[i].clear() ;
    }

}

