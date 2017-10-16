#include<bits/stdc++.h>
using namespace std ;
int M , N ;
char G[51][51];
bool MARK[26] ;
bool vis[51][51] ;
queue<pair<int,int> > Q ;
int dirR[]= {0,0,1,-1};
int dirC[]= {1,-1,0,0};

void build( char ch ) {
    for( int i = 0 ; i < M ; i++ ) {
        if( G[i][0] != ch ) {
            vis[i][0] = 1 ;
            Q.push( {i,0}) ;
        }
        if( G[i][N-1] != ch ) {
            vis[i][N-1] = 1 ;
            Q.push( {i,N-1}) ;
        }
    }
    for( int i = 0 ; i < N ; i++ ) {
        if( G[0][i] != ch ) {
            vis[0][i] = 1 ;
            Q.push( {0,i}) ;
        }
        if( G[M-1][i] != ch ) {
            vis[M-1][i] = 1 ;
            Q.push( {M-1,i}) ;
        }
    }
}

void print() {
    for( int i = 0 ; i < M ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            cout << vis[i][j] ;
        }
        cout << "\n" ;
    }
}
void bfs( int x , int y ) {
    memset( vis , 0 , sizeof vis ) ;
    build(G[x][y]);
    MARK[G[x][y]-'A'] = 1 ;
    //print();
    while( !Q.empty() ) {
        pair<int ,int > p = Q.front() ;
        Q.pop();
        for( int i = 0 ; i < 4 ; i++ ) {
            int R = p.first+dirR[i];
            int C = p.second+dirC[i];
            if( R>=0 && C>= 0 && R < M && C < N ) {
                if( vis[R][C] == 0 && G[R][C] != G[x][y] ) {
                    //print();
                    vis[R][C] = 1 ;
                    Q.push( {R,C}) ;
                }
            }
        }
    }
}

void update(int x , int y ) {
    for( int i = 0 ; i < M ; i++ ) {
        for( int j = 0 ; j < N ; j++ ) {
            if( vis[i][j] == 0 ) {
                G[i][j] = G[x][y] ;
            }
        }
    }
}
int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {

        memset( MARK , 0 ,sizeof MARK ) ;
        scanf("%d%d",&M,&N) ;
        for( int i = 0 ; i < M ; i++ ) {
            scanf("%s",G[i] ) ;
        }
        for( int i = 0 ; i < M ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                if( G[i][j] >= 'A' && G[i][j] <= 'Z') {
                    if( MARK[G[i][j]-'A'] == 0 ) {
                        bfs(i,j);
                        update(i,j);
                    }
                }
            }
        }
        cout << "Case " << caseno ++ << ":\n" ;
        for( int i = 0 ; i < M ; i++ ) {
            cout << G[i] << "\n" ;
        }
    }
    return 0 ;

}
