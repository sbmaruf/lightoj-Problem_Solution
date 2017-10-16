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
#define LLU long long unsigned int
#define LLD long long double
#define FOR(i,N) for(int i=0;i<(N);i++)
#define Vec vector<int>
#define Vit vector<int>::iterator

using namespace std;


int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
   int cases,caseno=1;
   scanf("%d",&cases);
   while(cases--){
    int s,e;
    scanf("%d%d",&s,&e);
    int s1=max(e,s)-min(e,s);
    s1=s1*4+3+5;
    s=s*4+3+5;
    printf("Case %d: %d\n",caseno++,s1+s+3);
   }
    return 0;
}
