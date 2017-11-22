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
#define PI acos(-1)
//define ULLD unsigned __int64 u64
using namespace std;

int main()
{

    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int cases;
    cin>>cases;
    int it=1;
    while(cases--)
    {
        int num;
        cin>>num;
        int arr[num+1];
        int min=-1;
        arr[0]=0;
        for(int i=1; i<(num+1); i++)
        {
            cin>>arr[i];
        }
        int i;
        for( i=0;i<num;i++)
        {
            arr[i]=arr[i+1]-arr[i];
        }
        i--;
       for(; i>=0; i--)
        {
            if(arr[i]>min) min = arr[i];
            else if(arr[i]==min) min++;
        }
      printf("Case %d: %d\n",it++,min);
    }


    return 0;
}

