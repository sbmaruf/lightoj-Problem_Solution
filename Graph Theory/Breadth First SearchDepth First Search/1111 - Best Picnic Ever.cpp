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

vector<int>G[1000+10];
bool visited[1000+10];
int ans[1000+10];
int ppl[100+10];
int road[10000+10];
int k,cnt;
void bfs(int src)
{
    queue<int >q;
    q.push(src);
    visited[src]=1;
    ans[src]++;
    if(ans[src]==k)cnt++;
    while(!q.empty()) {
        int temp=q.front();
        q.pop();
        for(int i=0; i<G[temp].size(); i++) {
            int dest = G[temp][i] ;
            if(!visited[dest]) {
                q.push(dest);
                visited[dest]=1;
                ans[dest]++;
                if(ans[dest]==k)cnt++;
            }
        }
    }
}
int main()
{
    int t,n,m;
    cin>>t;
    for(int l=1; l<=t; l++) {
        cnt=0;
        cin>>k>>n>>m;
        for(int i=0; i<=n; i++)ans[i]=0;
        for(int i=1; i<=k; i++)cin>>ppl[i];
        for(int i=0; i<m; i++) {
            int u,v;
            cin>>u>>v;
            G[u].pb(v);
        }
        for(int i=1; i<=k; i++) {
            for(int j=1; j<=n; j++)visited[j]=0;
            bfs(ppl[i]);
        }
        printf("Case %d: %d\n",l,cnt);
        for(int i=0; i<=n; i++)G[i].clear();
    }
    return 0 ;
}
