#include<stdio.h>

int main()
{
    int num;
    int cases,caseno=0;
    scanf("%d",&cases);

    while(cases--)
    {
        scanf("%d",&num);
        int arr[num+1];
        int i,j;
        for(i=1; i<=num; i++)
        {
            scanf("%d",&arr[i]);
        }
        int cnt=0;
        for( i=1; i<=num; i++)
        {
            if(arr[i]!=i)
            {
                for(j=i; j<=num; j++)
                {
                    if(arr[j]==i)
                    {
                        arr[i]^=arr[j]^=arr[i]^=arr[j];
                        cnt++;
                        break;
                    }
                }
            }

        }
        printf("Case %d: %d\n",++caseno,cnt);
    }
    return 0;
}

