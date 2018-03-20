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
    int cases,caseno=1;
    cin>>cases;
    while(cases--)
    {

        int N;
        cin>>N;

        int myteam[N],oppon[N];

        for(int i=0; i<N; i++)cin>>myteam[i];
        for(int i=0; i<N; i++)cin>>oppon[i];

        sort(myteam,myteam+N);
        sort(oppon,oppon+N);
        int cnt=0;
        int i,j;
        int flag=0;
        for(i=0; i<N; i++)
        {
            for( j=N-1; j>=0; j--)
            {
                if(myteam[i]>oppon[j])
                {
                    oppon[j]=1000000;
                    myteam[i]=-1;
                    cnt=cnt+2;
                    break;
                }
                //else if(myteam[i]==oppon[j]){oppon[j]=1000000;cnt++;}
            }
        }
        for(i=0; i<N; i++)
        {
            for( j=N-1; j>=0; j--)
            {
                if(myteam[i]==oppon[j] && myteam[i]!=-1)
                {
                    oppon[j]=1000000;
                    myteam[i]=-1;
                    cnt=cnt+1;
                    break;
                }
                //else if(myteam[i]==oppon[j]){oppon[j]=1000000;cnt++;}
            }
        }
        printf("Case %d: %d\n",caseno++,cnt);
    }

    return 0;
}

