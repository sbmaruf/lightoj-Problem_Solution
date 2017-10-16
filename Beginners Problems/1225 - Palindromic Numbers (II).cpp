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

char s[12];
int main()
{
    int n,caseno=1;
    scanf("%d",&n);
    getchar();
    while(n--)
    {

        int i;
        scanf("%s",s);
        int l=strlen(s);
        if(l==1)printf("Case %d: Yes\n",caseno++);
        else
        {
            for(int i=0,j=l-1;i<j;i++,j--){
                if(s[i]!=s[j]){
                        printf("Case %d: No\n",caseno++);
                        goto down;
                }
            }
            printf("Case %d: Yes\n",caseno++);
            down:;
        }
    }
    return 0;
}
