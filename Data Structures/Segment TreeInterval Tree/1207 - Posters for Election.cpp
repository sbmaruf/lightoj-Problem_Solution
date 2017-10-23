#include<bits/stdc++.h>
using namespace std ;
int tree[4*200000+1],MP[4*200000+1] ;
int n  , ans ;

void update( int node , int st , int en ,int i , int j , int &mark ) {

    if( st >j || en < i )return ;
    if( st == en ) {
        tree[node] = mark ;
        return ;
    }
    if( st >= i && en <= j ) {
        tree[node] = mark ;
        return ;
    }
    if( tree[node] != 0 ) {
        tree[(node<<1)] = tree[node] ;
        tree[(node<<1)+1] = tree[node] ;
        tree[node] = 0 ;
    }
    update( (node<<1) , st , ((st+en)>>1) , i , j , mark ) ;
    update( (node<<1)+1 , ((st+en)>>1)+1 , en , i , j , mark ) ;
}

void query(int node , int st , int en ) {
    if( st == en ) {
        if( MP[tree[node]] == 0 && tree[node] ) {
            MP[tree[node]] = 1 ;
            ans++ ;
        }
        return ;
    }
    if( tree[node] != 0 ) {
        tree[(node<<1)] = tree[node] ;
        tree[(node<<1)+1] = tree[node] ;
        tree[node] = 0 ;
    }
    query( (node<<1) , st , ((st+en)>>1) ) ;
    query( (node<<1)+1 , ((st+en)>>1)+1 , en ) ;
}

int main() {
    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        memset(tree,0,sizeof tree) ;
        memset(MP,0,sizeof MP) ;
        scanf("%d",&n) ;
        int l ,r ;
        for( int i = 1 ; i <= n ; i++ ) {
            scanf("%d%d",&l,&r) ;
            update(1,1,(n<<1),l , r , i ) ;
        }
        ans = 0 ;
        query(1,1,(n<<1)) ;
        cout << "Case "<< caseno++ << ": " << ans << "\n" ;
    }
    return 0 ;
}

