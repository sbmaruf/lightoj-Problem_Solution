#include<bits/stdc++.h>
using namespace std ;

char str[502][1002];
int visited[502][1002] ;

int dirR[] = { 1 , 0 , -1 , 0 } ;
int dirC[] = { 0 , 1 , 0 , -1 } ;
int r , c , query ;

int bfs(int a , int b , int f ) {
    queue<int> Q ;
    Q.push( a ) ;
    Q.push( b ) ;
    visited[a][b] = f ;
    int cnt = 0 ;

    while( !Q.empty() ) {

        int i = Q.front() ;
        Q.pop() ;
        int j = Q.front() ;
        Q.pop() ;


        for( int k = 0 ; k < 4 ; k++ ) {
            int R = i + dirR[k] ;
            int C = j + dirC[k] ;
            if( R < r && C < c && R>= 0 && C >= 0 ) {
                if( str[R][C] == '.' && visited[R][C] == (( f==-1 )?0:-1) ) {
                    visited[R][C] = f ;
                    Q.push( R ) ;
                    Q.push( C ) ;
                } else if( str[R][C] == 'C' && visited[R][C] == (( f==-1 )?0:-1) ) {
                    cnt++ ;
                    visited[R][C] = f ;
                    Q.push(R) ;
                    Q.push(C) ;
                }
            }
        }

    }
    return cnt ;
}


int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases) ;

    while( cases--) {

        scanf("%d%d%d",&r,&c,&query) ;

        printf("Case %d:\n",caseno++ ) ;

        for( int i = 0 ; i <= r ; i++ ) {
            for( int j = 0 ; j <= c ; j++ ) {
                visited[i][j] = 0 ;
            }
        }
        for( int i = 0 ; i < r ; i++ ) {
            scanf("%s",str[i] ) ;
        }

        for( int i = 0 ; i < r ; i++ ) {
            for( int j = 0 ; j < c; j ++ ) {
                if( visited[i][j] == 0 && str[i][j] == '.') {
                    int p = bfs(i,j, -1 ) ;
                    bfs( i , j , p ) ;
//                    cout << p << endl ;
//                    for( int i = 0 ; i <= r ; i++ ) {
//                        for( int j = 0 ; j <= c ; j++ ) {
//                            printf("%d",visited[i][j]) ;
//                        }printf("\n");
//                    }
                }
            }
        }

        for( int i = 0 ; i < query ; i++ ) {
            int a , b  ;
            scanf("%d%d",&a,&b) ;
            printf("%d\n",visited[a-1][b-1]) ;
        }


    }
    return  0 ;

}
