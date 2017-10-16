
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

    char str[1000000];
    int num;
    int cases;
    scanf("%d",&cases);
    int i=1;
    while(i<=cases)
    {

        scanf("%s",str);
        scanf("%d",&num);
        num=abs(num);
        if(str[0]=='-' || str[0]=='+')
        {
            long long int rem=0;
            for(int i=1; str[i]; i++)
            {
                rem=rem*10+(str[i]-48);
                rem=rem%num;
            }
            (rem==0)?printf("Case %d: divisible\n",i++):printf("Case %d: not divisible\n",i++);
        }
        else
        {

           long long int rem=0;
            for(int i=0; str[i]; i++)
            {
                rem=rem*10+(str[i]-48);
                rem=rem%num;
            }
            (rem==0)?printf("Case %d: divisible\n",i++):printf("Case %d: not divisible\n",i++);
        }
    }
    return 0;
}
