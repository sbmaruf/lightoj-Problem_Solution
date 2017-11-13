#include<stdio.h>
#include<string.h>
char s[19] ;
int dp[18][18][2][2][2] ;
// forward idx , backword idx , leading zero , left side value insert permission  , right side value insert permission

long long  rec( int fidx , int bidx , bool lzero ,bool lperm , bool rperm ) {

    if( fidx > bidx   ) {
        if( lperm ) return true ;
        else return !lperm && !rperm ;
    }
    if( dp[fidx][bidx][lzero][lperm][rperm] != -1 ) return dp[fidx][bidx][lzero][lperm][rperm] ;
    int ret = 0 ;
    int lim ;
    if( lperm )lim = 9 ;
    else lim = s[fidx]-'0' ;
    int nlzero , nlperm , nrperm  , nfidx , nbidx , nok  ;
    for( int i = 0 ; i <= lim ; i++ ) {
        nlzero = (i==0)&&(lzero) ;
        nlperm = (i < lim)||lperm ;
        nrperm = (i>s[bidx]-'0')||(rperm&&(i==s[bidx]-'0')) ;
        if( !nlzero )nbidx = bidx-1 ;
        else nbidx = bidx ;
        nfidx = fidx+1 ;
        ret += rec( nfidx , nbidx , nlzero , nlperm , nrperm ) ;
    }
    return dp[fidx][bidx][lzero][lperm][rperm]  = ret ;
}

int main() {

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while(cases -- ) {

        long long a , b ;
        scanf("%lld%lld" ,&a,&b ) ;
        if(a>b)a^=b^=a^=b ;
        a-- ;
        sprintf(s,"%lld",b);
        memset( dp , -1 , sizeof dp ) ;
        long long ans = rec( 0 , strlen(s)-1 , 1 , 0 , 0 ) ;
        sprintf(s,"%lld",a);
        memset( dp , -1 , sizeof dp ) ;
        ans -= rec( 0 , strlen(s)-1 , 1 , 0 , 0 ) ;
       printf("Case %d: %lld\n",caseno++ ,ans) ;
    }

}

