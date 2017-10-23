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

int main() {

    int cases , caseno =1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases -- ) {
        int n ;
        //scanf("%d",&n) ;
        n = readInt() ;
        int ans = n ;
        int p , base;
        //scanf("%d",&base) ;
        base = readInt() ;
        for( int i = 1 ; i < n ; i ++ ) {
            //scanf("%d",&p) ;
            p = readInt() ;
            if( p <= base ) {
                base++ ;
                ans -- ;
            }
        }
        cout << "Case " << caseno ++ << ": " << ans << "\n" ;
    }
    return 0 ;
}

