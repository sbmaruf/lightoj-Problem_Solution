#include <bits/stdc++.h>
using namespace std;
#define MOD  100000007
int coin[51] ;
int amount[51] ;
int n , k ;
int dp[1000+5][51] ;
long long int rec( int tot , int idx ){

    if( idx > n-1 ){
        return tot == 0 ;
    }
    if( tot<0 )return 0 ;
    if( tot == 0 )return 1 ;

    if( dp[tot][idx] != -1 )return dp[tot][idx] ;

    long long int ret = 0 ;

    for( int i = 0 ; i <= amount[idx] ; i++ ){
        if( tot - i*coin[idx] >= 0 )ret += rec( tot-i*coin[idx] , idx+1 )%MOD ;
        else break ;
    }
    return dp[tot][idx] = ret%MOD ;
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
    int cases ,caseno = 1 ;
    //scanf("%d",&cases ) ;
    cases = readInt();
    while( cases -- ){
       //scanf("%d%d",&n,&k);
       n = readInt() ;
       k = readInt() ;
       for( int i = 0 ; i < k+1 ; i++ ){
            for( int j = 0 ; j < n+1 ; j++ ){
                dp[i][j] = -1 ;
            }
       }
       for( int i = 0 ; i < n ; i++ ){
            //scanf("%d",&coin[i] ) ;
            coin[i] = readInt() ;
       }
       for( int i = 0 ; i < n ; i++ ){
            //scanf("%d",&amount[i] ) ;
            amount[i] = readInt() ;
       }
       printf("Case %d: %lld\n",caseno++ ,rec(k,0));
    }

    return 0;
}

