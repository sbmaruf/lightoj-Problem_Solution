#include<bits/stdc++.h>
using namespace std ;

int edges , vertices , busyness[200+1] , U[1000000+1] , V[1000000+1] , C[1000000+1] , D[200+1] ;
vector<int>G[200+1] ;
bool vis[200+1] ;

void bfs(){
    queue<int>Q ;
    Q.push(1) ;
    memset( vis , 0 , sizeof vis ) ;
    vis[1] = 1 ;
    while(!Q.empty()){
        int src = Q.front() ;
        Q.pop();
        int l = G[src].size() ;
        for( int i = 0 ;i < l ; i++ ){
            int v = G[src][i] ;
            if( vis[v] == 0 ){
                vis[v] = 1 ;
                Q.push(v) ;
            }
        }
    }
    return ;
}
inline int readInt()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }

    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
int main() {

    int cases , caseno =1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases -- ) {

        //scanf("%d",&vertices) ;
        vertices = readInt() ;
        for( int i = 1; i <= vertices ; i++ ) {
            //scanf("%d",&busyness[i]) ;
            busyness[i] = readInt() ;
            D[i] = 1 << 30 ;
        }
        scanf("%d",&edges) ;
        for( int i = 1 ; i <= edges ; i++ ) {
            //scanf("%d%d",&U[i],&V[i]) ;
            U[i] = readInt() ;
            V[i] = readInt() ;
            G[U[i]].push_back( V[i] ) ;
            C[i] = (busyness[V[i]] - busyness[U[i]])*(busyness[V[i]] - busyness[U[i]])*(busyness[V[i]] - busyness[U[i]]) ;
        }
        bool neg = 0 ;
        D[1] = 0 ;
        for( int j = 1 ; j <= vertices ; j++ ) {
            bool f = 0 ;
            for( int i = 1 ; i <= edges ; i++ ) {
                int u = U[i] ;
                int v = V[i] ;
                if( D[u]+C[i] < D[v] ) {
                    f = 1 ;
                    if( j == vertices ){
                        D[v] = 0 ;
                    }else D[v] = D[u]+C[i];
                }
            }
            if( !f )break ;
        }

        int q ;
        scanf("%d",&q) ;
        cout << "Case " << caseno++ << ":\n" ;
        bfs() ;
        while( q -- ){
            int a ;
            scanf("%d",&a) ;

            if( !vis[a] || D[a]<3 || D[a] == (1<<30) ){
                cout << "?\n" ;
            }else {
                cout << D[a] << "\n" ;
            }
        }
        for( int i = 0; i < 201 ; i++ )G[i].clear() ;
    }


    return 0;
}
