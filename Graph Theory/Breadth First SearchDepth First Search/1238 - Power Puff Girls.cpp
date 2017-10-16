#include<bits/stdc++.h>
#define inf numeric_limits<int>::max()
using namespace std;
int m,n,hx,hy;
char s[22][22];
int va[22][22],vb[22][22],vc[22][22];
int dirr[]= {-1,0,1,0};
int dirc[]= {0,1,0,-1};
int bfs(int p[][22],int q,int w)
{
    queue<pair<int,int> >x;
    pair<int,int>temp;
    x.push(make_pair(q,w));
    p[q][w]=0;
    while(!x.empty()) {
        temp=x.front();
        x.pop();
        for(int i=0; i<4; i++) {
            int r=temp.first+dirr[i];
            int c=temp.second+dirc[i];
            if(r>=0 && c>=0 && r<m && c<n) {
                if(s[r][c]!='#' && s[r][c]!='m' && (p[temp.first][temp.second]+1)< p[r][c] ) {
                    //cout << r << " " << c << endl ;
                    p[r][c]=(p[temp.first][temp.second]+1);
                    x.push(make_pair(r,c));
                }
            }
        }
    }

    return p[hx][hy];
}
int main()
{
    int t,ax,ay,bx,by,cx,cy;
    scanf("%d",&t);
    for(int i=1; i<=t; i++) {
        cin >> m >> n ;
        for(int j=0; j<m; j++) {
            for(int k=0; k<n; k++) {
                cin>>s[j][k];
                va[j][k]=inf;
                vb[j][k]=inf;
                vc[j][k]=inf;
                if(s[j][k]=='a')ax=j,ay=k;
                else if(s[j][k]=='b')bx=j,by=k;
                else if(s[j][k]=='c')cx=j,cy=k;
                else if(s[j][k]=='h')hx=j,hy=k;
            }
        }
        int d=bfs(va,ax,ay);
        int e=bfs(vb,bx,by);
        int f=bfs(vc,cx,cy);
        printf("Case %d: %d\n",i,max(d,max(e,f)));
    }
    return 0;
}

