#include<bits/stdc++.h>
using namespace std ;
int arr[150000+1] ;
int tree[4*150000] ;
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

void init( int node , int b , int e ){

    if( b == e ){
        if( b <= n ){
            tree[node] = 1 ;
        }else {
            tree[node] = 0 ;
        }
        return ;
    }
    init( node<<1 , b , (b+e)>>1 );
    init( (node<<1)+1 , ((b+e)>>1) + 1 , e );
    tree[node] = tree[node<<1] + tree[(node<<1)+1] ;
}

void update( int node , int b , int e , int i , int val ){

    if( i > e || i < b ) return ;
    if( b >= i && e <= i ){
        tree[node] = val ;
        return ;
    }
    update( node<<1 , b , (b+e)>>1 , i ,val ) ;
    update( (node<<1)+1 , ((b+e)>>1) + 1 , e , i , val ) ;
    tree[node] = tree[node<<1] + tree[(node<<1)+1] ;
}
int query( int node , int b , int e , int i , int j ){

    if( i > e || j < b ) return 0 ;
    if( b >= i && e <= j ){
        return tree[node] ;
    }
    return query( node<<1 , b , (b+e)>>1 , i , j ) + query( (node<<1)+1 , ((b+e)>>1) + 1 , e , i , j ) ;
}

int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        //scanf("%d%d",&n,&q) ;
        n = readInt() ;
        q = readInt() ;
        for( int i = 1 ; i <= n ; i++ ) {
            //scanf("%d",&arr[i]) ;
            arr[i] = readInt() ;
        }
        cout << "Case " << caseno ++ << ":\n" ;

        init( 1 , 1 , n+q ) ;
        int newadd = n+1 ;
        char s[3] ;
        int a ;
        int qw = q ;
        while( qw-- ) {
            scanf("%s",s) ;
            a = readInt() ;
            if( s[0] == 'c' ) {
                int lo = 1 ;
                int hi = n+q ;
                int mid ;
                int pos ;
                int change ;
                while( (hi-lo)>4 ){
                    mid = (lo+hi) >> 1 ;
                    pos = query( 1 , 1 , n+q , 1 , mid ) ;
                    if( pos >= a ){
                        hi = mid ;
                    }else{
                        lo = mid ;
                    }
                }
                bool f = 0 ;
                for( int i = lo ; i<= hi ; i++ ){
                    pos = query( 1 , 1 , n+q , 1 , i ) ;
                    if( pos == a ){
                        cout << arr[i] <<"\n" ;
                        f = 1 ;
                        change = i ;
                        break ;
                    }
                }
                if( !f ){
                    cout << "none\n" ;
                }else {
                    update( 1 , 1 , n+q , change , 0 ) ;
                }
            } else {
                arr[newadd] = a ;
                update( 1 , 1 , n+q , newadd++ , 1 ) ;
            }
        }
        //memset( tree , 0 , sizeof(tree) ) ;
    }


    return 0 ;
}

