#include<bits/stdc++.h>
using namespace std ;
#define MAX 100001
int N ;
vector<int>G[MAX] ;

pair<int,long long> dfs( int u ) {

    if( G[u].size() == 0 )return {0,0} ;
    pair<int,long long> ret ;
    ret.first = 0 ;
    ret.second = 0 ;
    long long p = 0 ;
    vector<long long>V ;
    for( int i = 0 ; i < G[u].size() ; i++ ) {
        int v = G[u][i] ;
        pair<int,long long> tmp = dfs(v) ;
        ret.first += tmp.first+1 ;
        V.push_back(tmp.first+1) ;
        p += tmp.second ;
    }
    int t = ret.first ;
    for(int i = 0 ; i < V.size()-1 ; i++ ){
        ret.second += ((long long)(t-V[i]))*V[i] ;
        t-=V[i] ;
    }
    ret.second += p ;
    return ret ;
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

int main() {

    long long cases , caseno = 1 ;
    //scanf( "%lld" , &cases ) ;
    cases = readInt() ;
    while( cases -- ) {
        //scanf("%d",&N) ;
        N = readInt() ;
        for( int i = 0 ; i < N-1 ; i++ ) {
            int u , v ;
            //scanf("%d%d",&u,&v) ;
            u = readInt() ;
            v = readInt() ;
            G[u].push_back( v ) ;
        }
        pair<int,long long> ans = dfs( 1 ) ;
        cout << "Case " << caseno++ << ": " << ans.first << " " << ans.second << "\n" ;
        for( int i = 0 ; i < MAX ; i++ )G[i].clear();

    }
    return 0 ;

}


/*

5
2
1 2
3
1 2
1 3
4
1 2
2 4
2 5
4
1 2
2 3
3 4
7
1 2
2 3
2 4
1 5
5 6
5 7
*/
