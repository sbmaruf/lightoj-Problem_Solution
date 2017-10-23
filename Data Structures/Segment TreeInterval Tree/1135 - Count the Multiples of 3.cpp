#include<bits/stdc++.h>
using namespace std ;

int n , q ;

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


struct node {
    int zero ;
    int one ;
    int two ;
    int propagation ;
    node() {} ;
    node( int a , int b , int c ) {
        zero = a ;
        one = b ;
        two = c ;
        propagation = 0 ;
    }
    void rotate() {
        int t = zero ;
        int t1 = one ;
        zero = two ;
        one = t ;
        two = t1 ;
    }
};

node tree[4*100000+1] ;

void init(int nd , int s , int e ) {
    if( s == e ) {
        tree[nd] = node( 1 , 0 , 0 ) ;
        return ;
    }
    init( (nd<<1) , s , ((s+e)>>1) ) ;
    init( ((nd<<1)+1) , (((s+e)>>1)+1) , e ) ;
    tree[nd].zero = tree[(nd<<1)].zero + tree[((nd<<1)+1)].zero ;
    tree[nd].one  = 0 ;
    tree[nd].two = 0 ;
    tree[nd].propagation = 0 ;
}

void update( int nd , int s , int e , int i , int j ) {

    if( s >= i && e <= j ) {
        tree[nd].propagation++ ;
        tree[nd].rotate() ;
        return ;
    }
    if( s>j || e<i )return  ;
    update( (nd << 1) , s , ((s+e) >> 1) , i , j ) ;
    update( ((nd << 1)+1) , (((s+e) >> 1)+1) , e , i , j ) ;

    tree[nd].zero = tree[(nd<<1)].zero + tree[((nd<<1)+1)].zero ;
    tree[nd].one  = tree[(nd<<1)].one  + tree[((nd<<1)+1)].one ;
    tree[nd].two  = tree[(nd<<1)].two  + tree[((nd<<1)+1)].two ;

    if( tree[nd].propagation%3==1 ) {
        tree[nd].rotate() ;
    } else if( tree[nd].propagation%3==2 ) {
        tree[nd].rotate() ;
        tree[nd].rotate() ;
    }
}

int query( int nd , int s , int e , int i , int j , int prop ) {

    if( s >= i && e <= j ) {
        node a = tree[nd] ;
        if( prop % 3 == 1 ){
            a.rotate() ;
        }else if( prop % 3 == 2 ){
            a.rotate() ;
            a.rotate() ;
        }
        return a.zero ;
    }
    if( s>j || e<i )return 0;
    return query( (nd << 1) , s , ((s+e) >> 1) , i , j , prop+tree[nd].propagation ) +
           query( ((nd << 1)+1) , (((s+e) >> 1)+1) , e , i , j , prop+tree[nd].propagation  ) ;

}

int main() {

    int cases , caseno = 1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;

    while( cases -- ) {

        //scanf("%d%d",&n,&q) ;
        n = readInt() ;
        q = readInt() ;
        init(1,1,n) ;
        int t , A , B ;
        cout << "Case " << caseno++ << ":\n" ;
        while( q -- ) {
            //scanf("%d%d%d",&t,&A,&B) ;
            t = readInt() ;
            A = readInt() ;
            B = readInt() ;
            A++ , B++ ;
            if( t == 0 ) {
                update( 1 , 1 , n , A , B ) ;
            } else {
                cout << query( 1 , 1 , n , A , B , 0 ) <<"\n" ;
            }
        }
    }

    return 0 ;
}

