#include<bits/stdc++.h>
using namespace std ;
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
struct NODE{
    int MIN , MAX , val ;
    NODE(){}
    NODE( int mi , int ma , int v ) {
        MIN = mi ;
        MAX = ma ;
        val = v ;
    }
};
int arr[100000+1] ;
NODE tree[4*100000+1] ;
int n , d ;

void build( int node ,int st , int en ){

    if( st == en ){
        tree[node].val = arr[st] ;
        tree[node].MIN = arr[st] ;
        tree[node].MAX = arr[st] ;
        return ;
    }
    build( (node<<1) , st , ((st+en)>>1) ) ;
    build( ((node<<1)+1) , (((st+en)>>1)+1) , en ) ;

    tree[node].MIN = min( tree[(node<<1)].MIN , tree[((node<<1)+1)].MIN ) ;
    tree[node].MAX = max( tree[(node<<1)].MAX , tree[((node<<1)+1)].MAX ) ;
    tree[node].val = tree[node].MAX - tree[node].MIN ;

}

int max_query( int node , int st , int en , int i , int j ){
    if( st > j || en < i )return -1 ;
    if( st >= i && en <= j ){
        return tree[node].MAX ;
    }
    int a = max_query( (node<<1) , st , ((st+en)>> 1) , i , j ) ;
    int b = max_query( ((node<<1)+1) , (((st+en)>>1)+1) , en , i , j ) ;
    return max( a , b ) ;
}

int min_query( int node , int st , int en , int i , int j ){
    if( st > j || en < i )return 1000000000 ;
    if( st >= i && en <= j ){
        return tree[node].MIN ;
    }
    int a = min_query( (node<<1) , st , ((st+en)>> 1) , i , j ) ;
    int b = min_query( ((node<<1)+1) , (((st+en)>>1)+1) , en , i , j ) ;
    return min( a , b ) ;
}
int main() {

    int cases , caseno = 1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases -- ) {

        //scanf("%d%d",&n,&d) ;
        n = readInt() ;
        d = readInt() ;
        for( int i =  1 ; i <= n ; i++ ) {
            //scanf("%d",&arr[i] ) ;
            arr[i] = readInt() ;
        }
        build( 1 , 1 , n ) ;
        int ans = -1000000000 ;
        for( int i = 1 ; i <= (n-d+1) ; i++ ){
            ans = max(ans , max_query( 1 , 1 , n , i , i+d-1 )-min_query( 1 , 1 , n , i , i+d-1 )) ;
        }
        cout << "Case " << caseno++ << ": " << ans << "\n" ;

    }


    return 0 ;
}

