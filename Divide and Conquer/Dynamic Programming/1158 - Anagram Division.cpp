#include<bits/stdc++.h>
using namespace std ;
#define read freopen( "1.txt" , "r" , stdin )

long long dp[1<<10][1001] ;
int arr[12];
int tmp , l , k ;
char s[14] ;
long long rec( register int mask , register int mod  )
{

    if( mask == ( (1<<l)-1 ) ) {
        return mod == 0 ;
    }
    if( dp[mask][mod] != -1 )return dp[mask][mod] ;
    long long  ret = 0 ;
    for( int i = 0 ; i  < l ; i++ ) {
        if((mask&(1<<i))==0 ) {
            ret+=rec( mask|(1<<i) , (mod*10+s[i]-48)%k ) ;
        }
    }
    return dp[mask][mod] = ret ;

}


int main()
{

    int f[11] ;
    f[0]=1;
    f[1]=1;
    for( int i = 2 ; i <= 10 ; i++ )f[i] = f[i-1]*i ;

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        getchar();
        scanf("%s%d",s,&k) ;
        l= strlen(s) ;

        memset(arr,0,sizeof(arr));

        for(int i=0; i<l; i++) {
            arr[s[i]-48]++;
        }

        memset( dp , -1 , sizeof( dp ) ) ;
        long long ans = rec(0,0) ;
        for(int i=0; i<10; i++) {
            ans/=f[arr[i]];
        }
        cout << "Case "<<caseno++ << ": " << ans << "\n" ;

    }

    return 0 ;
}

