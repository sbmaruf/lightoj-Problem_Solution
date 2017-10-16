#include<bits/stdc++.h>
using namespace std ;

bool ok( int mid,int Q ){
    int cnt = 0 ;
    while( mid ){
        cnt += mid/5 ;
        mid /= 5 ;
    }
    return cnt<Q ;
}
bool Ok( int mid,int Q ){
    int cnt = 0 ;
    while( mid ){
        cnt += mid/5 ;
        mid /= 5 ;
    }
    return cnt==Q ;
}
int bin(int Q){

    int lo = 0 ;
    int hi = 1000000000 ;

    while( hi - lo >= 3 ){

        int mid = (hi + lo)>>1 ;
        if(ok(mid,Q)){
            lo = mid+1;
        }else {
            hi = mid ;
        }

    }

    for( int i = lo ; i<= hi ; i++ ){
        if( Ok(i,Q) )return i ;
    }
    return -1 ;

}

int main() {

    int cases , caseno=1 ;
    scanf("%d",&cases) ;

    while( cases -- ){

        int Q ;
        scanf("%d",&Q) ;

        int ans = bin(Q) ;

        if( ans == -1 )printf("Case %d: impossible\n",caseno++ ) ;
        else printf("Case %d: %d\n",caseno++ , ans ) ;

    }

    return 0 ;
}


