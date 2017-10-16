#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI vector<int>
#define VVI vector< VI >
#define VIit VI::iterator
#define pi pair<int,int>
#define ui64 unsigned long long int
#define i64 long long int
#define pb(a) push_back(a)
#define mp make_pair


#define SI(a) scanf("%d",&a)
#define Si(a) scanf("%d",&a)
#define SU(a) scanf("%u",&a)
#define SHD(a) scanf("%hd",&a)
#define SHU(a) scanf("%hu",&a)
#define SLLD(a) scanf("%lld",&a)
#define SLLU(a) scanf("%llu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define PI acos(-1.0)
#define eps 1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi first
#define se second
#define bg begin()
#define en end()
#define ALL(x) (x).begin(), (x).end()
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x) (int)(x.size())

int money[1000+10];
vector<int>G[1000+10];
bool visited[1000+10];
int bfs(int a)
{
    queue<int>q;
    q.push(a);
    int sum=money[a],cnt=1;
    visited[a]=1;
    while(!q.empty()) {
        int src=q.front();
        q.pop();
        for(int i=0; i<G[src].size(); i++) {
            int dest = G[src][i];
            if(!visited[dest]) {
                visited[dest]=1;
                sum+=money[dest];
                cnt++;
                q.push(dest);
            }
        }
    }
    if(sum%cnt ==0)return sum/cnt;
    else return -1;
}
int main()
{
    int t,m,n,u,v;
    cin>>t;
    for(int k=1; k<=t; k++) {
        cin>>n>>m;
        mem(visited,0);
        for(int i=1; i<=n; i++) {
            cin>>money[i];
        }
        for(int i=0; i<m; i++) {
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
        }
        bool flag=1;
        int avg=-2,sa;
        for(int i=1; i<=n; i++) {
            if(!visited[i]) {
                sa=bfs(i);
            }
            if(avg==-2)avg=sa;
            else if(sa!=avg || sa==-1) {
                flag=0;
                break;
            }
        }
        if(flag)printf("Case %d: Yes\n",k);
        else printf("Case %d: No\n",k);
        for(int i=0; i<n; i++)
            G[i].clear();
    }
    return 0 ;
}
