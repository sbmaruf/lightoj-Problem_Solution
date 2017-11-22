#include<bits/stdc++.h>
#define i64 long long
#define MOD 1000007
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

int main(){

    //freopen("1.txt" , "r" , stdin ) ;

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while(cases -- ){

        long long K , C , N , tmp ;
        scanf( "%lld%lld%lld%lld" , &K , &C , &N , &tmp );
        long long arr[N] ;
        arr[0] = tmp ;
        for( int i = 1 ; i < N ; i++ ){
            arr[i]=( K*arr[i-1] + C ) % MOD;
        }
        sort( arr , arr+N ) ;
        long long ans = 0 ;
        for( int i = 0 , q = -(N-1) ; i < N ; i++ , q+=2 ){
            ans += (arr[i]*q) ;
        }
        cout << "Case " << caseno++ << ": " << ans << "\n" ;

    }



}

