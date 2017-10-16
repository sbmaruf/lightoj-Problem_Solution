
#include<bits/stdc++.h>
using namespace std ;
int R[] = { 2, 2, -1, -1, -2, -2, 1 , 1 };
int C[] = { 1, -1, 2, -2, 1, -1, 2 , -2 };
char G[11][11] ;
int dist[11][11] ;
int ansdist[11][11] ;
int vis[11][11] ;
int state[11][11] ;
int cstate[11][11] ;
int cnt = 0 ;
int m , n ;

struct data {
    int i , j ;
    data() {}
    data( int _i , int _j ) {
        i = _i , j = _j ;
    }
};
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

int bfs( int i , int j ) {

    queue<data>Q;
    int mostjump = G[i][j]-'0';
    Q.push( data( i , j ) ) ;
    vis[i][j] = 1 ;
    cstate[i][j] += 1 ;
    while( !Q.empty() ) {

        int srcR = Q.front().i ;
        int srcC = Q.front().j ;

        Q.pop() ;

        for( int i = 0 ; i < 8 ; i++ ) {

            int destR = srcR+R[i] ;
            int destC = srcC+C[i] ;

            if( destR >= 0 && destR <m && destC >= 0 && destC < n && vis[destR][destC] == 0 ) {

                vis[destR][destC] = 1 ;

                state[destR][destC] = state[srcR][srcC] + 1;
                state[destR][destC] %= mostjump;

                cstate[destR][destC]++ ;

                if( state[srcR][srcC] == 0 ) {
                    dist[destR][destC] = dist[srcR][srcC]+1 ;
                    ansdist[destR][destC] += dist[destR][destC] ;
                } else {
                    dist[destR][destC] = dist[srcR][srcC] ;
                    ansdist[destR][destC] += dist[destR][destC] ;
                }

                Q.push( data(destR,destC) ) ;
            }
        }
    }
    return 0 ;
}
int init() {
    for( int i =0 ; i <11 ; i++ ) {
        for( int j = 0 ; j < 11 ; j++ ) {
            vis[i][j] = 0 ;
            state[i][j] = 0 ;
            dist[i][j] = 0 ;
        }
    }
}
int main() {

    int cases , caseno = 1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases -- ) {


        //scanf("%d%d",&m,&n) ;
        m = readInt() ;
        n = readInt() ;
        for( int i = 0 ; i < m ; i++ )scanf("%s",G[i] ) ;

        for( int i =0 ; i <11 ; i++ ) {
            for( int j = 0 ; j < 11 ; j++ ) {
                cstate[i][j] = 0 ;
                ansdist[i][j] = 0 ;
            }
        }

        cnt = 0 ;
        for( int i = 0 ; i < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( G[i][j] != '.' ) {
                    init() ;
                    bfs( i , j );
                    cnt++ ;
                }
            }
        }
        int ans = 1e9 ;
        for( int i = 0 ; i  < m ; i++ ) {
            for( int j = 0 ; j < n ; j++ ) {
                if( cstate[i][j] == cnt) {
                    ans = min ( ans , ansdist[i][j] ) ;
                }
            }
        }
        cout << "Case " << caseno++ << ": " << (( ans == 1e9 )?-1:ans) <<"\n" ;

    }
    return 0 ;
}

/*
4
3 2
..
2.
..
3 3
1.1
...
..1
10 10
..........
.2....2...
......2...
1.........
...2.1....
...1......
..........
.......21.
..........
..........
1 4
1..1
*/
