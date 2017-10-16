#include<bits/stdc++.h>
using namespace std ;
#define x first
#define y second
#define rep(i,n) for( int i = 0 ;i < n ; i++ )
struct state {
    int x1,x2,x3,y1,y2,y3,w ;
    state() {
        w=0;
    }
    state( pair<int,int>a,pair<int,int>b,pair<int,int>c,int _w) {
        x1 = a.first;
        y1 = a.second;
        x2 = b.first;
        y2 = b.second;
        x3 = c.first;
        y3 = c.second;
        w = _w ;
    }
};

int R;
char grid[11][11] ;
bool vis[11][11][11][11][11][11] ;
int dirR[] = {0,0,1,-1};
int dirC[] = {1,-1,0,0};
pair<int,int> A , B , C ;

bool testBarrier(int x , int y) {
    return grid[x][y] != '#' ;
}
bool testArea(int x , int y) {
    return !( x >= 0 && y >= 0 && x < R && y < R ) ;
}
pair<int,int>getPoint( int x , int jumpX , int y , int jumpY , state tmp ) {
    if( testArea(x+jumpX , y+jumpY) )return {x,y} ;
    if( testBarrier(x+jumpX,y+jumpY) )return {x+jumpX,y+jumpY} ;
    return {x,y};
}
bool Equal( pair<int,int> a , pair<int,int> b ) {
    return ( a.x == b.x && a.y == b.y ) ;
}
int bfs(state st) {

    memset( vis , 0 , sizeof vis ) ;
    queue<state>Q ;
    Q.push( st ) ;
    vis[st.x1][st.y1][st.x2][st.y2][st.x3][st.y3] = 1;
    while( !Q.empty() ) {
        state u = Q.front() ;
        Q.pop() ;

        if( grid[u.x1][u.y1] == 'X' && grid[u.x2][u.y2] == 'X' && grid[u.x3][u.y3] == 'X' ) {
            return u.w ;
        }

        for( int i = 0 ; i <4 ; i++ ) {
            A = getPoint(u.x1,dirR[i],u.y1,dirC[i],u) ;
            B = getPoint(u.x2,dirR[i],u.y2,dirC[i],u) ;
            C = getPoint(u.x3,dirR[i],u.y3,dirC[i],u) ;
            if( Equal( A,B )  ) {
                A = {u.x1,u.y1} ;
                B = {u.x2,u.y2} ;
            }
            if( Equal( A,C ) ) {
                A = {u.x1,u.y1} ;
                C = {u.x3,u.y3} ;
            }
            if(Equal( B,C )) {
                B = {u.x2,u.y2} ;
                C = {u.x3,u.y3} ;
            }
            if( Equal( A,B )  ) {
                A = {u.x1,u.y1} ;
                B = {u.x2,u.y2} ;
            }
            if( Equal( A,C ) ) {
                A = {u.x1,u.y1} ;
                C = {u.x3,u.y3} ;
            }
            if(Equal( B,C )) {
                B = {u.x2,u.y2} ;
                C = {u.x3,u.y3} ;
            }
            if( Equal( A,B )  ) {
                A = {u.x1,u.y1} ;
                B = {u.x2,u.y2} ;
            }
            if( Equal( A,C ) ) {
                A = {u.x1,u.y1} ;
                C = {u.x3,u.y3} ;
            }
            if(Equal( B,C )) {
                B = {u.x2,u.y2} ;
                C = {u.x3,u.y3} ;
            }
            if( vis[A.x][A.y][B.x][B.y][C.x][C.y] == 0 ) {
               vis[A.x][A.y][B.x][B.y][C.x][C.y] = 1 ;
                Q.push(state(A,B,C,u.w+1));
            }
        }

    }

    return -1 ;
}

int main() {

    int cases , caseno = 1 ;
    scanf("%d", &cases ) ;

    while( cases -- ) {
        scanf("%d",&R) ;
        int idx = 0 ;
        state st ;
        for( int i = 0 ; i  < R ; i++ ) {
            scanf(" %s",grid[i]) ;
            for( int j = 0 ; j < R ; j++ ) {
                if( grid[i][j] == 'A' ) {
                    st.x1 = i;
                    st.y1 = j ;
                } else if( grid[i][j] == 'B' ) {
                    st.x2 = i;
                    st.y2 = j ;
                } else if( grid[i][j] == 'C' ) {
                    st.x3 = i;
                    st.y3 = j ;
                }
            }
        }
        int ans = bfs(st) ;
        cout << "Case " << caseno++ << ": " ;
        if( ans == -1 )cout << "trapped\n" ;
        else cout << ans << "\n" ;
    }
}
