#include<bits/stdc++.h>
#define i64 long long
#define MOD 1
using namespace std ;
unsigned int nCr[50+1][50+1] ;
long long n ;
int k , lim ;
template<int N> class Matrix {
public:
    unsigned int  arr[N][N];
    Matrix() {
        for( int i = 0 ; i < N ; i ++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                arr[i][j] = 0 ;
            }
        }
    }
    Matrix<N> operator *(const Matrix<N> &in) {
        Matrix<N> ret ;
        for( int i = 0 ; i <= lim+1 ; i++ ) {
            for( int j = 0 ; j <= lim+1 ; j++ )
                for( int k = 0 ; k <= lim+1 ; k++ ) {
                    ret.arr[i][j]+=(arr[i][k])*(in.arr[k][j]) ;
                }
        }
        return ret ;
    }
    Matrix<N> operator ^(long long int POW ) {
        Matrix<N> ret ;
        for( int i = 0 ; i < N ; i++ ) {
            ret.arr[i][i] = 1 ;
        }
        Matrix<N> ME = *this ;
        while( POW ) {
            if( POW&1 ) {
                ret = ret * ME ;
            }
            ME = ME * ME ;
            POW >>= 1 ;
        }
        return ret ;
    }
};

void calc()
{

    for( int i = 0 ; i < 51 ; i++ ) nCr[i][0] = 1  ;
    for( int i = 1 ; i < 51 ; i++ ) {
        nCr[i][1] = i ;
        for( int j = 2 ; j <= i ; j++ ) {
            nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j] ;
        }
    }

}


int main()
{

    calc();

    int cases , caseno = 1;
    scanf("%d",&cases );

    while( cases -- ) {


        scanf("%lld%d",&n,&k) ;

        Matrix<52> X ;
        lim = k ;
        //////////////////////////////////init///////////////////
        X.arr[0][0] = 1;
        for( int i = 1 ; i <= (k+1) ; i++ ) {
            X.arr[0][i] = nCr[k][i-1];
        }
        for( int i = 1 ; i <= (k+1) ; i++ ) {
            for( int j = i ; j <= (k+1); j++ ) {
                X.arr[i][j] = nCr[k-i+1][j-i];
            }
        }
        ////////////////////////////////Solve////////////////////////
        X=X^(n-1);
        unsigned int ans = 0 ;
        for( int i = 0 ; i <= (k+1) ; i++ ) {
            ans += X.arr[0][i] ;
        }
        cout << "Case " << caseno++ << ": " << ans << "\n" ;

    }




}

