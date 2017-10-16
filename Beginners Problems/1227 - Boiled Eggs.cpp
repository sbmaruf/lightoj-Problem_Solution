
#include<stdio.h>
#include <iostream>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

int main()
{
    int n,p,q,cases,z;
    z=1;
    scanf("%d",&cases);
    while(z<=cases)
    {
        scanf("%d%d%d",&n,&p,&q);
        int arr[n];
        int totw=0,ct=0;

        for(int i=0; i<n  ; i++)
        {
            scanf("%d",&arr[i]);
        }
        for(int i=0; i<min(p,n) ; i++)
        {
            totw+=arr[i];
            if(totw>q)break;
            ct++;
        }
        printf("Case %d: %d\n",z++,ct);
    }
    return 0;
}
