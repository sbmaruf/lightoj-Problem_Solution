
/*
ID: Ordinary_Sheep
LANG: C++
TASK:
*/
   //bismillahirrahmanirrahim
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define SI(a)      scanf("%d",&a)

int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases -- ){

        int x1, x2 , x3 , y1 , y2 , y3 ;
        SI( x1 ) ; SI( y1 ) ;
        SI( x2 ) ; SI( y2 ) ;
        SI( x3 ) ; SI( y3 ) ;

        printf( "Case %d: %d %d %d\n",caseno++, x3 - x2 + x1 , y3 - y2 + y1 , abs( x1 * ( y2 - y3 ) - y1 * ( x2 - x3 ) + x2*y3 - y2*x3 ) ) ;

    }

    return 0;
}
