#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
#define zero(arr) memset(arr,0,sizeof(arr));
#define pb(a) push_back(a)
#define SI(a) scanf("%d",&a)
#define SU(a) scanf("%u",&a)
#define SHD(a) scanf("%hd",&a)
#define SHU(a) scanf("%hu",&a)
#define SLLD(a) scanf("%lld",&a)
#define SLLU(a) scanf("%llu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)

using namespace std;

vector<int> G[20001];
int visited[20001];
vector<int> nodelist;
bool nodework[20001];
bool anscount[20001];

int bfs(int source){

    queue<int>Q;
    Q.push(source);
    int temp=1,cnt1,cnt2=0;
    cnt1=cnt2=0;
    while(!Q.empty()){
        int u=Q.front();
        if(!anscount[u]){
            anscount[u]=1;
            cnt1++;
            for(int k=0;k<G[u].size();k++){
                if(anscount[G[u][k]]==0){
                    cnt2++;
                    anscount[G[u][k]]=1;
                }
            }
        }
        for(int i=0;i<G[u].size();i++){
            int v=G[u][i];
            if(!visited[v]){
                visited[v]=1;
                Q.push(v);
            }
        }
        Q.pop();
    }
    return max(cnt1,cnt2);

}

int main()
{
    int cases,caseno=1;
    cin>>cases;
    while(cases--)
    {
        for(int i=0;i<20001;i++)G[i].clear();
        zero(visited);
        nodelist.clear();
        zero(nodework);
        zero(anscount);
        int line;
        cin>>line;
        while(line--)
        {
            int u,v;
            cin>>u>>v;
            G[u].pb(v);
            G[v].pb(u);
            if(!nodework[u])
            {
                nodework[u]=1;
                nodelist.pb(u);
            }
            if(!nodework[v])
            {
                nodework[v]=1;
                nodelist.pb(v);
            }
        }
        int ans=0;
        zero(visited);
        for(int i=0; i<nodelist.size(); i++)
        {
            if(!visited[nodelist[i]])ans+=bfs(nodelist[i]);
        }
        printf("Case %d: %d\n",caseno++,ans);
    }
    return 0;
}
