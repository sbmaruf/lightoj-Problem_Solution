
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
typedef struct stu{
string s;
int product;
}S;
bool comp(S i,S j){
    return i.product<j.product;
}
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
   int cases,casesno=1;
   cin>>cases;
    while(cases--)
    {
        int line;
        cin>>line;
        vector< S > v;
        for(int i=0;i<line;i++)
        {
            int h,w,l;
            string s;
            cin>>s;
            cin>>h>>w>>l;
            S temp;
            temp.s=s;
            temp.product=h*w*l;
            v.push_back(temp);
        }
        sort(v.begin(),v.end(),comp);
        printf("Case %d: ",casesno++);
        if(v[0].product<v[v.size()-1].product)cout<<v[v.size()-1].s<<" took chocolate from "<<v[0].s<<endl;
        else printf("no thief\n");
    }
    return 0;
}
