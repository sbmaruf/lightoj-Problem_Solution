#include<bits/stdc++.h>
using namespace std ;
int arr[500+1][500+1] ;
int ST[500+1][500+1][9+1]  ;
int Log( int n )
{
    int cnt = 0 ;
    int p = 1 ;
    while( p<=n ) {
        p <<= 1 ;
        cnt ++ ;
    }
    return cnt-1 ;
}
int POW( int n )
{
    int ret = 1 ;
    while( n ) {
        n-- ;
        ret <<= 1 ;
    }
    return ret ;
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

int main()
{

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        int n , query ;
        //scanf("%d%d" , &n , &query ) ;
        n = readInt() ;
        query = readInt() ;
        cout << "Case " << caseno ++ << ":\n" ;

        for( int i = 1 ; i <= n ; i++ ) {
            for( int j = 1 ; j <= n ; j++ ) {
                //scanf("%d",&arr[i][j] ) ;
                arr[i][j] = readInt() ;
                ST[i][j][0] = arr[i][j] ;
            }
        }
        int Loglim = Log( n ) ;
        int Pow = 1 ;
        for( int i = 1 ; i<= Loglim ; i++ ) {
            Pow <<= 1 ;
            for( int j = 1 ; (j+(1<<i)-1) <= n ; j++ ) {
                for( int k = 1 ; (k+(1<<i)-1) <= n ; k++ ) {
                    int mid = Pow>>1 ;
                    int temp = ST[j][k][i-1] ;
                    temp = max( temp , ST[j][k+mid][i-1] ) ;
                    temp = max( temp , ST[j+mid][k][i-1] ) ;
                    temp = max( temp , ST[j+mid][k+mid][i-1] ) ;
                    ST[j][k][i] = temp ;
                }
            }
        }
        while( query-- ) {
            int st , en , s;
            //scanf( "%d%d%d" , &st , &en , &s ) ;
            st = readInt() ;
            en = readInt() ;
            s = readInt() ;
            int lowest = Log(s) ;
            int lim = POW(lowest) ;
            int tmp = ST[st][en][lowest] ;
            if( s != ( 1 << lowest ) ) {
                int right = (en+s-1)-lim+1 ;
                tmp = max( tmp , ST[st][right][lowest] ) ;
                int down = (st+s-1)-lim+1 ;
                tmp = max( tmp , ST[down][en][lowest] ) ;
                tmp = max( tmp , ST[down][right][lowest] ) ;
            }
            cout << tmp << "\n" ;
        }
    }





}

