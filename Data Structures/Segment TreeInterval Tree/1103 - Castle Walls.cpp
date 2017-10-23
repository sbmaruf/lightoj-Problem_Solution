#include<bits/stdc++.h>
using namespace std ;
struct data {
    int x , y ;
    char ch ;
    data() {}
    data(int _x , int _y , char c ) {
        x = _x ,y = _y ,ch = c ;
    }
    bool operator < ( const data& a )const {
        if( x == a.x )return y < a.y ;
        return x < a.x ;
    }
};
int treeBlue[200000+1] ;
int treeRed[200000+1] ;
int n , m , t ;
void updateBlue( int idx ) {
    while( idx <= t ) {
        treeBlue[idx] += 1 ;
        idx += ( idx & (-idx) ) ;
    }
}
void updateRed( int idx ) {
    while( idx <= t ) {
        treeRed[idx] += 1 ;
        idx += ( idx & (-idx) ) ;
    }
}
int queryBlue( int idx ) {
    int ret = 0 ;
    while( idx > 0 ) {
        ret += treeBlue[idx] ;
        idx -= ( idx & (-idx) ) ;
    }
    return ret ;
}
int queryRed( int idx ) {
    int ret = 0 ;
    while( idx > 0 ) {
        ret += treeRed[idx] ;
        idx -= ( idx & (-idx) ) ;
    }
    return ret ;
}
data arr[200000+1] ;
int main() {
    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        scanf("%d%d",&n,&m) ;
        t = n+m ;
        int a , b ;
        int idx = 0 ;
        memset( treeRed , 0 , sizeof treeRed ) ;
        memset( treeBlue , 0 , sizeof treeBlue ) ;
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%d%d",&a,&b) ;
            arr[idx++] = data(a,b,'B') ;
        }
        for( int i = 0 ; i < m ; i++ ) {
            scanf("%d%d",&a,&b) ;
            arr[idx++] = data(a,b,'R') ;
        }
        sort( arr , arr + idx ) ;
        long long ans = 0 ;
        int p = 0 ;
        for( int i = 0 ; i < idx ; i++ ) {
            p = 0 ;
            if( arr[i].ch == 'B' ) {
                p += queryRed(idx)-queryRed(arr[i].y-1) ;
                ans += p ;
                updateBlue(arr[i].y);
            } else {
                p += queryBlue(idx)-queryBlue(arr[i].y-1) ;
                ans += p ;
                updateRed(arr[i].y);
            }

        }
        cout << "Case " << caseno++ << ": " << ans << "\n" ;

    }
    return 0 ;
}

