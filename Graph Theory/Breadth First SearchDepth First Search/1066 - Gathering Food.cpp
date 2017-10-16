/*
ID: Ordinary_Sheep
LANG: C++
TASK:
*/
//bismillahirrahmanirrahim
#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI         vector<int>
#define VVI        vector< VI >
#define VIit       VI::iterator
#define pi        pair<int,int>
#define ui64       unsigned long long int
#define i64        long long int
#define pb(a)      push_back(a)
#define mp         make_pair


#define SI(a)      scanf("%d",&a)
#define SU(a)      scanf("%u",&a)
#define SHD(a)     scanf("%hd",&a)
#define SHU(a)     scanf("%hu",&a)
#define SLLD(a)    scanf("%lld",&a)
#define SLLU(a)    scanf("%llu",&a)
#define SF(a)      scanf("%f",&a)
#define SLF(a)     scanf("%lf",&a)
#define SC(a)      scanf("%c",&a)
#define SS(a)      scanf("%s",a)
#define read       freopen("in.txt","r",stdin)
#define write      freopen("out.txt","w",stdout)
#define PI         acos(-1.0)
#define eps        1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi          first
#define se          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())
char G[11+1][11+1] ;
int visited[11+1][11+1] ;
int dirR[] = {-1, 1, 0, 0};
int dirC[] = {0, 0, -1, 1};
int n ;
int cnt = 0 ;
char ch4bfs ;
pi bfs(int x , int y )
{
    rep(i,n)rep(j,n)visited[i][j] = 0 ;

    queue< pair<int,int> >Q;
    Q.push(mp(x,y));
    visited[x][y] = 1 ;
    while( !Q.empty() ) {
        pi src = Q.front() ;
        Q.pop() ;
        rep( i , 4 ) {
            int R = dirR[i] + src.first ;
            int C = dirC[i] + src.second ;
            if( R>=0 && R<n && C>=0 && C<n&& !visited[R][C] && G[R][C] != '#' ) {
                if( G[R][C]==ch4bfs+1 ){
                    G[x][y] = '.' ;
                    cnt += visited[src.first][src.second] ;
                    return mp(R,C) ;
                } else if( G[R][C] == '.' ) {
                    visited[R][C] += visited[src.first][src.second] + 1 ;
                    Q.push(mp(R,C));
                }
            }
        }
    }

    return mp(-1,-1);

}



int main()
{
    int cases ,casesno=1  ;
    SI( cases ) ;

    while( cases -- ) {
        cin >> n ;
        char ch = 'A' ;
        int x , y ;
        rep( i , n ) {
            rep( j , n ) {
                cin >> G[i][j] ;
                if( G[i][j] == 'A' ) {
                    x = i ;
                    y = j ;
                } else if( G[i][j] >= 'B' && G[i][j] <='Z' ) {
                    ch = max(ch , G[i][j] ) ;
                }
            }
        }
        cnt = 0 ;
        int flag = 1;

        ch4bfs = 'A' ;
        pi ans;
        pi temp ;
        ans.first = x ;
        ans.second = y ;
        while( ch4bfs< ch ) {
            temp = bfs( ans.first,ans.second ) ;
            if( temp.first == - 1) {
                flag = 0 ;
            }else {
                ans = temp ;
            }
            ch4bfs++;
        }

        if( !flag ) {
            printf("Case %d: Impossible\n",casesno++ );
        } else {
            printf("Case %d: %d\n",casesno++,cnt) ;
        }


    }

    return 0;
}
