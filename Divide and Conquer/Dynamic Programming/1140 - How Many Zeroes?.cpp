#include<bits/stdc++.h>
#define i64 long long
using namespace std ;

int l ;
pair<i64,i64> dp[22][2][2] ;
bool vis[22][2][2] ;
char str[22] ;

pair<i64,i64> rec( int idx , bool perm , int lead ){



    if( idx == l && lead ) return make_pair(1,1) ;
    else if( idx == l ) return make_pair(1,0);

    if( vis[idx][perm][lead] ) return dp[idx][perm][lead] ;
    vis[idx][perm][lead] = true ;

    pair<i64,i64> ret = make_pair(0,0);
    pair<i64,i64> tmp ;
    int lim = (perm==0)?(str[idx]-'0'):9;

    for( int i = 0 ; i <= lim ; i++ ){

        tmp = rec( idx+1 , (i<(str[idx]-'0')) || perm , ( !i && lead ) ) ;
        ret.first += tmp.first ;
        ret.second += tmp.second ;
        if( !i && !lead ) ret.second += tmp.first ;

    }

    return dp[idx][perm][lead] = ret ;

}

int main(){

    //freopen("1.txt" , "r" , stdin ) ;

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    getchar() ;

    while(cases -- ){

        long long n1 , n2 ;
        scanf("%lld%lld",&n1,&n2) ;
        n1-- ;

        sprintf(str,"%lld",n2 ) ;
        l = strlen( str );
        memset( vis , 0 , sizeof vis ) ;
        pair<i64,i64> ans = rec( 0 , 0 , 1 ) ;

        sprintf(str,"%lld",n1 ) ;
        l = strlen( str );
        memset( vis , 0 , sizeof vis ) ;
        pair<i64,i64> ans1 = rec( 0 , 0 , 1 ) ;

        cout <<"Case " << caseno++ << ": " << ans.second - ans1.second << "\n" ;


    }



}

