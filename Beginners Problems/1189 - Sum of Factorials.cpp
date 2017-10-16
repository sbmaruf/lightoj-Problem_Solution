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

int main()
{
    int cases,caseno=1;
    SI(cases);
    i64 arr[100];
    i64 n=1;
    arr[0]=1;
    arr[1]=1;
    arr[2]=2;
    int i;
    for( i=3;arr[i-1]<1000000000000000001;i++){
            arr[i] = arr[i-1]*i ;
    }
   // for(int i=0;i<10;i++)cout<<arr[i]<<endl;
    while(cases--){
        int flag=0;
        i64 num;
        SLLD(num);

        printf("Case %d: ",caseno++);
        if(num==0){
            printf("impossible\n");
            continue;
        }
        VI ans;
        ans.pb(-1);
        for(int i=0;;i++){
            if(num==2){
                ans.pb(1);ans.pb(0);break;
            }
            if(num==0)break;
            if(arr[i]>num){
                ans.pb(i-1);
                if(*(ans.end()-1)==*(ans.end()-2)){flag=1; break;}
                num=num-arr[i-1];
                i=-1;
            }

        }
        if(flag)printf("impossible\n");
        else {
            int flag=0;
            for(vector<int>::iterator it=ans.end()-1;it>ans.begin();it--){
                if(flag)printf("+");
                flag=1;
                cout<<*it<<"!";

            }
            cout<<endl;
        }
    }

    return 0;
}
