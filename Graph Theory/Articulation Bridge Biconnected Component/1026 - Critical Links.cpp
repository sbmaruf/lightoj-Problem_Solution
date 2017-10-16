#include<bits/stdc++.h>
using namespace std ;
#define rep(i,n) for( int i = 0 ;i < n ; i++ )
int n , m , u , v , c;
vector<int>G[10000+1] ;
bool vis[10000+1];
int dis[10000+1] , low[10000+1],par[10000+1] ;
vector<pair<int,int> > V ;
void dfs( int u , int time ){
    vis[u] = 1 ;
    int child = 0 ;
    dis[u] = low[u] = time ;
    rep( i , G[u].size() ){
        int v = G[u][i] ;
        if( !vis[v] ){
            child++ ;
            par[v] = u ;
            dfs(v,time+1) ;
            low[u] = min(low[u],low[v]) ;
            if( low[v] > dis[u] )V.push_back({min(u,v),max(u,v)});

        }else if( v!= par[u] ){
            low[u] = min(low[u],dis[v]) ;
        }
    }
}

void solve(){
    V.clear() ;
    rep(i,n+1){
        vis[i] = 0 ;
        par[i] = i ;
        dis[i] = -1 ;
        low[i] = -1 ;
    }
    for( int i = 1 ; i <= n ; i++ ){
        if( vis[i] == 0 ){
            dfs( i , 0 );
        }
    }
}
bool comp(pair<int,int> a , pair<int,int> b ){
    if( a.first == b.first )return a.second < b.second ;
    return a.first < b.first ;
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

    int cases , caseno =1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;
    while( cases -- ){
        //scanf("%d",&n) ;
        n = readInt() ;
        string s ;
        char ch ;
        rep( i , n ){
            //scanf("%d",&u) ;
            u = readInt() ;
            scanf("%c",&ch) ;
            c = readInt() ;
            scanf("%c",&ch) ;
            rep( i , c ){
                //scanf("%d",&v) ;
                v = readInt() ;
                G[u].push_back(v);
            }
        }
        solve() ;
        cout << "Case "<< caseno++ << ":\n" ;
        cout << V.size() << " critical links\n" ;
        sort( V.begin() , V.end() , comp ) ;
        for( int i = 0 ;i < V.size() ; i++ )
            cout << V[i].first << " - " << V[i].second << "\n" ;
        for( int i = 0 ;i <=n;i++ )G[i].clear() ;
    }
}

