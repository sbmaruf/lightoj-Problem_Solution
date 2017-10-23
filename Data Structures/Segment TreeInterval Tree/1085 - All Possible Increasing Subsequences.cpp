#include<bits/stdc++.h>
using namespace std ;
struct NODE {
    int val , idx ;
    NODE() {}
    NODE( int i , int v ) {
        val = i ;
        idx = v ;
    }
};
int n ;
int tree[100000+1] ;
void update ( int idx , int val ) {

    while( idx <= n ) {
        tree[idx] += val ;
        tree[idx] %=1000000007 ;
        idx += ( idx & -idx );
    }

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
long long query( int idx ) {

    long long sum = 0 ;
    while( idx > 0 ) {
        sum += tree[idx] ;
        sum %= 1000000007 ;
        idx -= ( idx & -idx ) ;
    }
    return sum ;

}
bool comp( NODE a , NODE b ) {
    if( a.val == b.val )return a.idx > b.idx ;
    return a.val < b.val ;
}


int main() {

    int cases , caseno = 1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases -- ) {

        memset( tree , 0 , sizeof tree ) ;

        //scanf("%d",&n) ;
        n = readInt() ;
        NODE arr[n] ;
        int tmp ;
        for( int i = 0 ; i < n ; i ++ ) {
            //scanf("%d",&tmp) ;
            tmp =readInt() ;
            arr[i+1] = NODE( tmp , i+1 ) ;
        }
        sort( arr+1 , arr + n+1,comp );
        long long ans = 0 ;
        for( int i = 1 ; i <= n ; i++ ) {
            long long a = query( arr[i].idx-1 ) ;
            a = a%1000000007 ;
            update( arr[i].idx , a+1 ) ;
        }
        cout << "Case " << caseno++ << ": " << query( n )%1000000007 << "\n" ;
    }



    return 0 ;
}

