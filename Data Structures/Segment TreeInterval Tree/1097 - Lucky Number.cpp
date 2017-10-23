#include<bits/stdc++.h>
using namespace std ;
#define MAX 1429435
bool MARK[MAX] ;
int tree[MAX] ;
int ans[100000+5] ;
int idx = 0 ;
void update( int idx , int val ){
    while( idx < MAX ){
        tree[idx]+=val ;
        idx += ( idx & (-idx) ) ;
    }
}
int query( int idx ){
    int sum = 0 ;
    while( idx > 0 ){
        sum += tree[idx] ;
        idx -= (idx & (-idx)) ;
    }
    return sum ;
}
int bin( int tot ){
    int lo = 0 ,hi = MAX , mid ;
    while( hi - lo >= 3) {
        mid = (lo+hi)>>1 ;
        int s = query(mid) ;
        if( s < tot )lo = mid ;
        else hi = mid ;
    }
    for( int i = lo ; i <= hi ; i++ ){
        if( query(i) == tot ){
            MARK[i] = 1 ;
            update(i,-1);
            return i ;
        }
    }
    return -1 ;
}
void precalc(){
    for( int i = 1 ; i < MAX ; i+= 2 )update( i , 1 ) ;
    for( int i = 3 ; i < MAX ; i+= 2 ){
        if( !MARK[i] ){
            int cnt = 0 ;
            for( int j = i ; j < MAX ; j+= i ){
                if( bin(j-cnt) < 0 )break;
                else cnt ++ ;
            }
//            for( int i = 1 ; i < 30 ; i+=2 ){
//                 if( !MARK[i] )cout << i << " " ;
//            } cout << "\n" ;
        }
    }
    for( int i = 1 ;i  < MAX ; i+=2 ){
        if( !MARK[i] )ans[idx++]=i  ;
    }
}

int main(){
    precalc() ;
    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ){
        int n ;
        scanf("%d",&n) ;
        cout << "Case " << caseno++ << ": " << ans[n-1] <<"\n" ;
     }
    return 0 ;
}

