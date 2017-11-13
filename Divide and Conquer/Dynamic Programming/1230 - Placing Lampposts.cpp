#include<bits/stdc++.h>
#define x first
#define y second

using namespace std ;

vector<int>G[1001] ;
pair<int,int>dp[1001][2] ;
bool vis[1001] ;
int node , edge ;

pair<int,int> rec( int node , int f , int parent)
{
    vis[node] = true ;
    pair<int,int>& ret = dp[node][f];
    if( ret.first != -1 ) {
        return ret ;
    }
    ret.first = ret.second = 0 ;
    for( int j = 0 ; j < G[node].size() ; j++ ) {

        int v = G[node][j] ;

        if( v == parent ) {
            continue ;
        } else {
            if( f ) {

                pair<int,int> d1 = rec( v , 0 , node ) ;
                pair<int,int> d2 = rec( v , 1 , node ) ;

                if( d1.first == ( 1 + d2.first ) && ( d1.second > ( 1+d2.second )) ) {
                    ret.first += d1.first ;
                    ret.second += d1.second ;
                } else if( d1.first < ( 1 + d2.first ) ) {
                    ret.first += d1.first ;
                    ret.second += d1.second ;
                } else {
                    ret.first+= 1 + d2.first ;
                    ret.second+= 1 + d2.second ;
                }
            } else {
                pair<int,int>d=rec( v , 1 , node );
                ret.first += (1 + d.first) ;
                ret.second += d.second ;
            }
        }

    }
    return ret ;


}


int main()
{

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        scanf("%d%d",&node,&edge) ;
        for( int i = 0 ; i < edge ; i++ ) {
            int u , v ;
            scanf("%d%d",&u,&v) ;
            G[u].push_back(v) ;
            G[v].push_back(u) ;
        }
        memset(vis,0,sizeof(vis));
        memset(dp,-1,sizeof dp );
        pair<int,int> ans = make_pair( 0 , 0 ) ;
        for( int i = 0 ; i < node ; i++ ) {
            if( vis[i] == 0 ) {

                pair<int,int> d1 = rec( i , 0 , -1 ) ;
                pair<int,int> d2 = rec( i , 1 , -1 ) ;

                if( d1.first == ( 1 + d2.first ) && ( d1.second > d2.second ) ) {
                    ans.first += d1.first ;
                    ans.second += d1.second ;
                } else if( d1.first < ( 1 + d2.first ) ) {
                    ans.first += d1.first;
                    ans.second += d1.second ;
                } else {
                    ans.first += 1 + d2.first ;
                    ans.second +=  d2.second ;
                }

            }
        }
        cout << "Case " << caseno++  <<  ": " << ans.first << " " << ans.second << " " << edge - ans.second <<"\n";
        for( int i = 0 ; i <= node ; i ++ )G[i].clear() ;
   }





}

