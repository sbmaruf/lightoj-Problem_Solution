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
    cin>>cases;
    while(cases--)
    {

        int num,iterate;
        cin>>num>>iterate;
        printf("Case %d:\n",caseno++);
        char s[26];
        int i;
        for( i=0; i<num; i++)
        {
            s[i]=i+65;
        }
        s[i]='\0';
        //cout<<s<<endl;
        int cnt=0;
        do
        {
            //cout << myints[0] << ' ' << myints[1] << ' ' << myints[2] << '\n';
            printf("%s\n",s);
            cnt++;
            if(cnt==iterate)break;
        }
        while ( next_permutation(s,s+num) );
    }
    return 0;
}

