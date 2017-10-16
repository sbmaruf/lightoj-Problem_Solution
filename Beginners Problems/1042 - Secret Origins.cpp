
    //bismillahirrahmanirrahim

#include <bits/stdc++.h>

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

#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)

#define rep_1(i,n) for(int i=1;i<n;i++)

#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)



#define VI vector<int>

#define VVI vector< VI >

#define VIit VI::iterator



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

#define swp(type, a, b) {type x=a; a=b; b=x;}

#define read freopen("in.txt","r",stdin)

#define write freopen("out.txt","w",stdout)

#define pi acos(-1.0)

#define eps 1e-9



#define check(num,pos) num&(1<<pos)

#define set(num,pos) num|=(1<<pos)

#define clear(num,pos) num&=~(1<<pos)

#define toggle(num,pops) num^=(1<<pos)



using namespace std;



//int dirR8[]= {0,-1,-1,-1,0,1,1,1};

//int dirC8[]= {1,1,0,-1,-1,-1,0,1};

//int dirR4[]= {0,-1,0,1};

//int dirC4[]= {1,0,-1,0};

//int dirR[]={-2,-1, 1, 2, 2,1,-1,-2};

//int dirC[]={-1,-2,-2,-1, 1,2, 2, 1};


int main()
{
    //read;
    int cases,caseno=1;
    SI(cases);
    while(cases--){
        int n;
        SI(n);
        bool flag=true;
        int pos;
        int cnt=0;
        for(int i=30;i>=0;i--){
            if(check(n,i)){
                flag=false;
                cnt++;
            }
        }
        //cout<<" "<<cnt<<" "<<pos<<" "<<endl;
        if(cnt==1){
                printf("Case %d: %d\n",caseno++,n<<1);
                continue;
        }
        int act=0;
        for(int i=0;i<31;i++){
            if((n&(1<<i)) && !(n&(1<<(i+1)))){
                act=1;
            }
            if((n&(1<<i)) && !(n&(1<<(i+1)))){
                set(n,i+1);
                clear(n,i);
                pos=i;
                break;
            }
        }
        if(!act){
            printf("Case %d: %d\n",caseno++,n);
        }
        else {
                cnt=0;
            rep(i,pos+1){
                if(check(n,i))cnt++;
                clear(n,i);
            }

            rep(i,cnt){
                set(n,i);
            }
            printf("Case %d: %d\n",caseno++,n);
        }
    }
    return 0;
}
