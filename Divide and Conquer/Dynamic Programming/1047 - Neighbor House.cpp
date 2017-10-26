
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
#define pii        pair<int,int>
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
#define pi         acos(-1.0)
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
int N;
int arr[20][3];
i64 dp[20][3];

i64 rec(int i,int j,int flag){

    if(i==N)return 0;
    else if(j==flag)return 10000000001;
    else if(dp[i][j]!=-1)return dp[i][j];
    else {
        return dp[i][j] = min(min(rec(i+1,0,j)+arr[i][j],rec(i+1,1,j)+arr[i][j]),rec(i+1,2,j)+arr[i][j]);
    }

}

int main()
{
    //read;
    //137 96
    int cases,caseno=1;
    SI(cases);
    while(cases--){
        SI(N);
        mem(dp,-1);
        rep(i,N)rep(j,3)SI(arr[i][j]);
        i64 ret=rec(0,0,-1);
        i64 ret1=rec(0,1,-1);
        i64 ret2=rec(0,2,-1);
        printf("Case %d: %lld\n",caseno++,min(min(ret,ret1),ret2));
    }

    return 0;
}

