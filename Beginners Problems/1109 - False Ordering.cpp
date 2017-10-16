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

using namespace std;


#define zero(arr) memset(arr,0,sizeof(arr));

#define VFor(t,v,c)  for(t::const_iterator it=c.begin(); it != c.end(); ++it)

#define VI vector<int>

#define VVI vector< VI >

#define VIit VI:iterator

#define pb(a) push_back(a)




#define N 1000
struct primefactor
{
    int index;
    int Size;
};
primefactor pf[1001];
bool comp(primefactor i,primefactor j)
{
    if(i.Size==j.Size)
    {
        return i.index>j.index;
    }
    else return i.Size<j.Size;
}
bool status[N];
VI prime;
void SOE()
{
    int sqrtN=sqrt(N);
    for(int i=3; i<=sqrtN; i=i+2)
    {
        if(status[i]==0)
        {
            for(int j=i*i; j<N; j+=i+i)
            {
                status[j]=1;
            }
        }
    }
    prime.pb(2);
    for(int i=3; i<N; i=i+2)if(status[i]==0)prime.pb(i);
}

void primefactorize(int n)
{
    int temp=n;
    int sqrtN=sqrt(n);
    int cnt;
    int res=1;
    for(int i=0; prime[i]<=sqrtN; i++)
    {
        cnt=1;
        if(!(n%prime[i]))
        {
            while(!(n%prime[i]))n/=prime[i],cnt++;
            sqrtN=sqrt(n);
        }
        res*=cnt;
    }
    if(n>1)res=res<<1;
    pf[temp].Size=res;
}

int main()
{
    SOE();
    for(int i=3; i<1001; i++)
    {
        pf[i].index=i;
        pf[i].Size=1;
    }
    pf[1].index=1;
    pf[2].index=2;
    pf[2].Size=2;
    for(int i=3; i<1001; i++)primefactorize(i);
    sort(pf+2,pf+1001,comp);
    int cases,caseno=1;
    cin>>cases;
    while(cases--)
    {
        int num;
        cin>>num;
        printf("Case %d: %d\n",caseno++,pf[num].index);
    }
    return 0;



}
