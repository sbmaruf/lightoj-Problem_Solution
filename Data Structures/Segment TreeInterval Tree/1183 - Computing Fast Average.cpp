#include<bits/stdc++.h>
using namespace std ;
struct data {
    long long val ;
    long long prop ;
    data() {
        prop = -1 , val = 0 ;
    }
};
int n , q ;
int arr[100000+1] ;
data tree[4*100000+1] ;
int Gcd (int n1,int n2) {
    int tmp;
    while (n2 != 0) {
        tmp = n1;
        n1 = n2;
        n2 = tmp % n2;
    }
    return n1;
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
void init(int node ,int st , int en ){

    if( st == en ){
        tree[node].val = 0 ;
        tree[node].prop = -1 ;
        return ;
    }

    int l = (node<<1) ;
    int r = l+1 ;
    int mid = ((st+en)>>1) ;

    init( l , st , mid ) ;
    init( r , mid+1 , en ) ;

    tree[node].val = 0 ;
    tree[node].prop = -1 ;

}
void update( int node , int st , int en , int i , int j , int v ) {

    int l = (node<<1) ;
    int r = l+1 ;
    if( tree[node].prop != -1 ) {
        tree[node].val = (en-st+1)*tree[node].prop ;
        if( st != en ) {
            tree[l].prop = tree[node].prop ;
            tree[r].prop = tree[node].prop ;
        }
        tree[node].prop = -1 ;
    }
    if( st > j || en < i ) return  ;
    if( st >= i && en<= j ) {
        tree[node].val = (en-st+1)*v ;
        if( st != en ) {
            tree[l].prop = v ;
            tree[r].prop = v ;
        }
        return ;
    }
    int mid = ((st+en)>>1) ;
    update( l , st , mid , i , j , v ) ;
    update( r , mid+1 , en , i , j , v ) ;
    tree[node].val = tree[l].val + tree[r].val ;
}

long long query( int node ,int st , int en , int i ,int j ) {

    int l = (node<<1) ;
    int r = ((node<<1)+1) ;
    if( tree[node].prop != -1 ) {
        tree[node].val = (en-st+1)*tree[node].prop ;
        if( st != en ) {
            tree[l].prop = tree[node].prop ;
            tree[r].prop = tree[node].prop ;
        }
        tree[node].prop = -1 ;
    }
    if( st > j || en < i ) return 0 ;
    if( st >= i && en <= j ) {
        return tree[node].val ;
    }
    int mid =  ((st+en)>>1) ;
    return query( l , st , mid , i , j )
            + query( r, mid+1 , en , i , j ) ;
}
int main() {

    int cases , caseno = 1  ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases-- ) {
        int t , i , j , v ;
        //scanf("%d%d",&n,&q) ;
        n = readInt() ;
        q = readInt() ;
        cout<< "Case " << caseno++ << ":\n" ;
        init(1,1,n) ;
        while( q -- ) {
            //scanf("%d",&t) ;
            t= readInt() ;
            if( t == 1 ) {
                //scanf("%d%d%d",&i,&j,&v) ;
                i = readInt() ;
                j = readInt() ;
                v = readInt() ;
                update( 1 , 1 , n , i+1 , j+1 , v ) ;
            } else {
                //scanf("%d%d",&i,&j) ;
                i = readInt() ;
                j = readInt() ;
                int ans = query( 1 , 1 , n , i+1 , j+1 ) ;
                int range = j-i+1 ;
                int gcd = Gcd( ans , range ) ;
                range /= gcd ;
                ans /= gcd ;
                if( range != 1 ){
                    cout << ans << "/" << range << "\n" ;
                }else {
                    cout << ans << "\n" ;
                }
            }
        }
    }
    return 0 ;
}

