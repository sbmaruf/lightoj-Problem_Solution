#include<bits/stdc++.h>
#define i64 long long
using namespace std ;

char str[11] ;
i64 dp[11][83][83][2] ;
int l , k ;
i64 rec( int idx , int sum , int mod , int perm ){

    if( idx == l ){
        return (i64)((sum%k)==0 && mod == 0) ;
    }
    i64& ret = dp[idx][sum][mod][perm] ;
    if(  ret != -1 ) return ret ;
    ret = 0 ;
    int lim = (perm)?9:str[idx]-'0' ;
    for( int i = 0 ; i <= lim ; i++ ){
        ret += rec( idx+1 , (sum+i)%k , (mod*10+(i))%k , (i<(str[idx]-'0')) || perm ) ;
    }
    return ret ;

}

int main(){

    int cases , caseno = 1;
    scanf("%d",&cases );

    while( cases -- ){

        long long int a , b ;

        scanf("%lld%lld%d",&a,&b,&k) ;
        if( k > 81 ){
            cout << "Case " << caseno++ << ": 0\n" ;
        }else {
            a-- ;
            sprintf( str , "%lld" , b ) ;
            l =strlen( str ) ;
            memset( dp , -1 , sizeof dp ) ;
            i64 ans = rec( 0 , 0 , 0 ,0 ) ;

           // cout << ans << " " ;

            sprintf( str , "%lld" , a ) ;
            l =strlen( str ) ;
            memset( dp , -1 , sizeof dp ) ;
            i64 ans1 = rec( 0 , 0 , 0 , 0) ;

            //cout << ans1 << endl ;

            cout << "Case " << caseno++ << ": " << ans - ans1 << "\n" ;
        }


    }




}

