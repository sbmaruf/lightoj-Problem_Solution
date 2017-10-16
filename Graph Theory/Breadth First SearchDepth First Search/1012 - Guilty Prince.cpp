
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
#define vector<int> VI
#define vector< VI > VVI
#define VI:iterator VIit
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
#define MAX 21
using namespace std;

queue<int>Q;
int visited[MAX][MAX];
char MAP[MAX][MAX];
int cnt=0;int W,H;
int dirR[] = {-1, 1, 0, 0};
int dirC[] = {0, 0, -1, 1};

void bfs(){

    zero(visited);
    while(!Q.empty()){
    int i=Q.front();
    Q.pop();
    int j=Q.front();
    Q.pop();

    for(int  k=0;k<4;k++){
        int p=i+dirR[k];
        int q=j+dirC[k];
        if( (p>=0 && p<H) && (q>=0 && q<W) && (MAP[p][q]=='.') ){
            if(visited[p][q]==0){
            visited[p][q]=1;
            Q.push(p);
            Q.push(q);
            cnt++;
            }
        }
    }


    }
}
int main()
{
    int cases,caseno=1;
    cin>>cases;
    while(cases--){
        cin>>W>>H;
        cnt=0;
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                cin>>MAP[i][j];
                if(MAP[i][j]=='@'){
                        Q.push(i);
                        Q.push(j);
                }
            }
        }
        cnt=0;
        bfs();
        printf("Case %d: %d\n",caseno++,cnt+1);
    }
    return 0;
}
