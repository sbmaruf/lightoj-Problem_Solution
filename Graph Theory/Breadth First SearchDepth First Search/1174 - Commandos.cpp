#include<bits/stdc++.h>
using namespace std ;
#define inf 1000000000
int N , st ,en , Q ;
int dist[101][101];

int main()
{

    int cases , caseno= 1 ;
    scanf("%d",&cases );

    while( cases-- ) {

        scanf("%d%d",&N,&Q) ;
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0; j < N ; j++ ) {
                dist[i][j] = inf;
            }
        }

        for( int i = 0 ; i < Q ; i++ ) {
            int a , b ;
            scanf("%d%d",&a,&b) ;
            dist[a][b] = dist[b][a] = 1 ;
        }

        for( int k = 0 ; k < N ; k++ ) {
            for( int i = 0 ; i < N ; i ++ ) {
                for( int j = 0 ; j < N ; j ++ ) {
                    dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        for( int i = 0 ;i <N ; i++ ){
            dist[i][i]=0;
        }
        scanf("%d%d",&st,&en) ;
        long long ans = -1 ;
        for(int i=0; i<N; i++) {
            if(dist[st][i]+dist[i][en]>ans) {
                ans=dist[st][i]+dist[i][en];
            }
        }
        cout << "Case "<<caseno++ <<": "<<ans << "\n" ;
    }


    return 0 ;

}
