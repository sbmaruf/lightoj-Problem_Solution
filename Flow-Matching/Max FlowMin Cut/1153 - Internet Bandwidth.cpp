#include<bits/stdc++.h>
using namespace std ;

int vis[101][101];
int C[101][101];
vector<int>G[101] ;
int P[101];
int  M ;

int Back_Track(int src,int sink) {

    int parent = P[sink] ;
    M = min( M , C[parent][sink] );

    if( parent == src ){
        C[parent][sink] -= M ;
        C[sink][parent] += M ;
        return M ;
    }

    int ret = Back_Track( src , parent ) ;

    C[parent][sink] -= ret ;
    C[sink][parent] += ret ;

    return M ;
}

int Find_Aug_Path(int src, int sink) {

    queue<int>Q ;
    Q.push( src ) ;
    P[src] = src ;
    while( !Q.empty() ) {
        int nSrc = Q.front() ;
        Q.pop() ;
        int l = G[nSrc].size() ;
        for( int i = 0 ; i < l ; i++ ) {
            int v = G[nSrc][i] ;
            if( P[v] == 0 && C[nSrc][v] > 0 ) {
                P[v] = nSrc ;
                Q.push( v ) ;
                if( v == sink ) {
                    M = 1 << 30 ;
                    return Back_Track(src,sink) ;
                }
            }

        }
    }
    return 0 ;

}

int Edmonds_Karp(int src,int sink) {
    int ans = 0 ;
    memset( P , 0 , sizeof P ) ;
    int tmp = Find_Aug_Path( src , sink ) ;
    ans += tmp ;
    while( tmp ) {
        memset( P , 0 , sizeof P ) ;
        tmp = Find_Aug_Path( src , sink ) ;
        ans += tmp ;
    }
    return ans ;
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

    int cases , caseno = 1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;

    while( cases -- ) {
        int n , src , sink , c  ;
        for( int i = 0 ; i < 101 ; i++ )G[i].clear() ;
        memset( vis , 0 , sizeof vis ) ;
        memset( C , 0 , sizeof C ) ;

       // scanf("%d%d%d%d",&n,&src,&sink,&c) ;
        n = readInt() ;
        src = readInt() ;
        sink = readInt() ;
        c = readInt() ;
        for( int i = 0 ; i < c ; i++ ) {
            int u ,v , w ;
            //scanf("%d%d%d",&u,&v,&w) ;
            u = readInt() ;
            v = readInt() ;
            w = readInt() ;
            if( vis[u][v] == 0 ) {
                G[u].push_back( v );
                G[v].push_back( u );
                vis[u][v] = 1  ;
            }
            C[u][v] += w ;
            C[v][u] += w ;
        }
        cout << "Case " << caseno++ << ": " <<  Edmonds_Karp(src,sink) << "\n" ;

    }

    return 0 ;
}

