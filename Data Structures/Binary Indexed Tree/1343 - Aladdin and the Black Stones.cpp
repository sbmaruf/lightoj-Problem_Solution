#include<bits/stdc++.h>
using namespace std;
const long long mod=1LL<<32;
struct node{
    int ii,jj;
    long long vv;
    node(){}
    node(int _ii,int _jj,long long int _vv){ii=_ii,jj=_jj,vv=_vv;}
    bool operator<(const node&p)const{
        if(vv==p.vv){
            if( ii == p.ii )return jj<p.jj ;
            return ii<p.ii ;
        }else return vv<p.vv ;
    }
};
int n;
long long w[502];
long long tree[505][505];
void update(int ii,int jj,long long vv){
    while(ii<=n){
        int yy=jj;
        while(yy<=n){
            tree[ii][yy]+=vv;
            tree[ii][yy]%=mod;
            yy+=((yy)&(-yy));
        }
        ii+=((ii)&(-ii));
    }
    return;
}
long long read(int ii,int jj){
    long long ret=0;
    while(ii>0){
        int yy=jj;
        while(yy>0){
            ret+=tree[ii][yy];
            ret%=mod;
            yy-=((yy)&(-yy));
        }
        ii-=((ii)&(-ii));
    }
    return ret;
}
long long query(int ii,int jj){
    long long ret=(read(jj,jj-1)-read(ii,jj-1));
    ret=((ret%mod)+mod)%mod;
    return ret;
}
vector<node>v;
int main(){
    int t;
    scanf("%d",&t);
    for(int z=1;z<=t;z++){
        scanf("%d",&n);
        v.clear();
        memset(tree,0,sizeof(tree));
        for(int i=0;i<n;i++){
            scanf("%lld",&w[i]);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back(node(i+1,j+1,w[i]+w[j]));
            }
        }
        sort(v.begin(),v.end());
        long long ans=0;
        for(int i=0;i<v.size();i++){
            long long x=1+query(v[i].ii,v[i].jj);
            x%=mod;
            update(v[i].ii,v[i].jj,x);
            ans+=x;
            ans%=mod;
        }
        cout<<"Case "<<z<<": "<<ans<<"\n";
    }
    return 0;
}

