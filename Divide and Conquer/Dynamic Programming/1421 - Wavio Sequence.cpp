#include<bits/stdc++.h>
using namespace std ;
#define read freopen( "1.txt" , "r" , stdin )
int n ;
int Sequence1[100000+1];
int Sequence2[100000+1];
int L1[100000+1] ;
int L2[100000+1] ;
int I1[100000+1] ;
int I2[100000+1] ;
const int inf = 2000000000;

int LisNlogK()
{
    int i;
    I1[0] = -inf;
    for( i = 1; i <= n; i++ )
        I1[i] = inf;
    int LisLength = 0;
    for( i = 0; i < n; i++ ) {
        int low, high, mid;
        low = 0;
        high = LisLength;
        while( low <= high ) {
            mid = ( low + high ) / 2;
            if( I1[mid] < Sequence1[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        I1[low] = Sequence1[i];
        if( LisLength < low )
            LisLength = low;
        L1[i] = LisLength ;
    }
    return LisLength;
}
int LdsNlogK()
{
    int i;
    I2[0] = -inf;
    for( i = 1; i <= n; i++ )
        I2[i] = inf;
    int LisLength = 0;
    for( i = 0; i < n; i++ ) {
        int low, high, mid;
        low = 0;
        high = LisLength;
        while( low <= high ) {
            mid = ( low + high ) / 2;
            if( I2[mid] < Sequence2[i] )
                low = mid + 1;
            else
                high = mid - 1;
        }
        I2[low] = Sequence2[i];
        if( LisLength < low )
            LisLength = low;
        L2[i] = LisLength ;
    }
    return LisLength;
}


int main()
{

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {

        scanf("%d",&n) ;

        for( int i = 0 ; i < n; i++ ) {
            scanf("%d",&Sequence1[i]);
            Sequence2[n-i-1] = Sequence1[i] ;
        }
        LisNlogK();
        LdsNlogK();

        int m = 0 ;
        for( int i = 0 ; i < n ; i++ ) {
            //cout << L1[i] << " " << L2[i] << endl ;
            m = max( m ,min(L1[i],L2[n-i-1]) ) ;
        }
        cout << "Case " << caseno++ << ": " << 2*m-1 <<"\n" ;

    }
    return 0 ;
}

