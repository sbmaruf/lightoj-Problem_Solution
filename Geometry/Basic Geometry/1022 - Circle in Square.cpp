#include<stdio.h>
#include<math.h>
#define pie 2*acos(0.0)
int main()
{
    int cases,caseno=1;
    scanf("%d",&cases);
    while(cases--)
    {
        double num;
        scanf("%lf",&num);
        printf("Case %d: %.2lf\n",caseno++,double((num+num)*(num+num)-(pie)*num*num));
    }
    return 0;
}


