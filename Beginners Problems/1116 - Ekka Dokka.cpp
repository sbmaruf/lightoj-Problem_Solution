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
   while(cases--){
    unsigned long long int num1;
   cin>>num1;
   //int sqrtN=sqrt(num1);
   int flag=0;
 
    int evendiv=1;
   while(num1){
            if(num1%2==0){
                evendiv *= 2;
                num1 = num1/2;
                if(num1%2==1){
                    flag=1;
                    break;
                }
            }
            else{
                    flag=0;
                break;
            }
        }
   if(flag==1)cout<<"Case "<<caseno++<<": "<<num1<<" "<<evendiv<<endl;
   else printf("Case %d: Impossible\n",caseno++);
 
   }
    return 0;
}
 
