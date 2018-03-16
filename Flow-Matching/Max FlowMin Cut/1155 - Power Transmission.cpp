#include<bits/stdc++.h>
using namespace std;
int n,m,u,v,w,b,d,cap[300][300],pr[300];
vector<int>g[300];
bool vis[300];
inline int ns(int a){return (a+102);}
int bfs(){
    memset(vis,0,sizeof(vis));
    memset(pr,-1,sizeof(pr));
    vis[0]=1;
    queue<pair<int,int> >q;
    q.push(make_pair(0,1<<30));
    while(!q.empty()){
        pair<int,int>src=q.front();
        q.pop();
        for(int i=0;i<g[src.first].size();i++){
            if(!vis[g[src.first][i]] && cap[src.first][g[src.first][i]]>0){
                vis[g[src.first][i]]=1;
                pr[g[src.first][i]]=src.first;
                if(g[src.first][i]==280){
                    return min(src.second,cap[src.first][g[src.first][i]]);
                }
                q.push(make_pair(g[src.first][i],min(src.second,cap[src.first][g[src.first][i]])));
            }
        }
    }
    return -1;
}
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        memset(cap,0,sizeof(cap));
        for(int i=0;i<300;i++)g[i].clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&w);
            g[i].push_back(ns(i));
            g[ns(i)].push_back(i);
            cap[i][ns(i)]=w;
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[ns(u)].push_back(v);
            g[v].push_back(ns(u));
            cap[ns(u)][v]=w;
        }
        scanf("%d%d",&b,&d);
        for(int i=0;i<b;i++){
            scanf("%d",&u);
            g[0].push_back(u);
            cap[0][u]=1<<30;
        }
        for(int i=0;i<d;i++){
            scanf("%d",&u);
            g[ns(u)].push_back(280);
            cap[ns(u)][280]=1<<30;
        }
        int ans=0;
        while(true){
            int x=bfs();
            if(x==-1)break;
            ans+=x;
            int y=280;
            while(pr[y]!=-1){
                cap[y][pr[y]]+=x;
                cap[pr[y]][y]-=x;
                y=pr[y];
            }
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

