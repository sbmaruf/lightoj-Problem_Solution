#include<bits/stdc++.h>
#define MOD 1000000007

using namespace std ;
typedef long long i64 ;

vector<int>G[1000+1] ;
long long dp[1001];
long long nCr[1001][1001];
bool Vis[1001] ;
int nChild[1001] ;
int n ;
void precalc() {
    for(int i = 1 ; i <= 1000 ; i++) {
        nCr[i][0]=1;
        nCr[i][1]=i;
        for(int j = 2 ; j <= i ; j++ ) {
            nCr[i][j] = ( nCr[i-1][j-1] + nCr[i-1][j] ) % MOD;
        }
    }
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


int FindNumberofChild( int par ) {
    int l = G[par].size() ;
    if( l == 0 ) {
        return nChild[par] = 1  ;
    }
    long long ret = 0 ;
    for( int i = 0 ; i < l ; i++ ) {
        int child = G[par][i] ;
        ret += FindNumberofChild(child) ;
    }
    nChild[par] = ret+1 ;
    return nChild[par] ; ;
}

long long rec( int par ) {

    int l = G[par].size() ;
    if( l == 0 )return dp[par]=1 ;
    if( dp[par] != -1 ) return dp[par] ;
    long long ret = 1 ;
    int totchild = nChild[par]-1 ;
    for( int i = 0 ; i < l ; i++ ) {
        int child = G[par][i] ;
        ret *= (((nCr[totchild][nChild[child]])*rec( child ))%MOD) ;
        ret = ret % MOD ;
        totchild -= nChild[child] ;
    }
    return dp[par] = ret%MOD ;

}

long long solve( int root ) {
    FindNumberofChild( root ) ;
    //    for( int i = 0 ; i< 10 ; i++ )cout << nChild[i] << " " ;
    //    cout << endl ;
    memset( dp , -1 , sizeof dp ) ;
    return rec( root )%MOD ;
}

int main() {

    precalc() ;
    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        //scanf("%d",&n) ;
        n = readInt() ;
        int m = -1 ;
        for( int i = 1 ; i < n ; i++ ) {
            int a , b ;
            //scanf("%d%d",&a,&b) ;
            a = readInt() ;
            b = readInt() ;
            G[a].push_back( b ) ;
            Vis[b] = 1 ;
        }
        int root ;
        for( int i = 1 ; i <= n ; i++ ) {
            if( Vis[i] == 0 ) {
                root = i ;
            }
        }
        cout << "Case " << caseno++ << ": " << solve( root ) << "\n" ;
        memset( Vis , 0 , sizeof Vis ) ;
        for( int i = 0 ; i <= 1000 ; i++ )G[i].clear() ;
    }
    return 0 ;
}

