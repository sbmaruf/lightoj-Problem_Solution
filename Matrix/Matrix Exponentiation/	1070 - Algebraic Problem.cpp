#include<bits/stdc++.h>
#define i64 long long
#define MOD 1
using namespace std ;
unsigned long long p , q , n ;

template<int N> class Matrix
{
public:
    unsigned long long arr[N][N];
    Matrix() {
        for( int i = 0 ; i < N ; i ++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                arr[i][j] = 0 ;
            }
        }
    }
    Matrix<N> operator *(const Matrix<N> &in) {
        Matrix<N> ret ;
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ )
                for( int k = 0 ; k < N ; k++ ) {
                    ret.arr[i][j]+=(((arr[i][k])*(in.arr[k][j]))) ;
                }
        }
        return ret ;
    }
    Matrix<N> operator ^( int POW ) {
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



void init( Matrix<2>& X , Matrix<2>& Y )
{

    //X^(n-1) * Y = ANS ;

    //given ;
    Y.arr[0][0] = p ;
    Y.arr[1][0] = 2 ;

    // MATRIX X
    X.arr[0][0] = p ;
    X.arr[0][1] = -q ;
    X.arr[1][0] = 1 ;

}
unsigned long long solve(Matrix<2>& X,Matrix<2>& Y)
{

    X = X^(n-1) ;
    Matrix<2>ANS = X * Y ;
    return ANS.arr[0][0] ;
}
int main()
{

    int cases , caseno = 1;
    scanf("%d",&cases );

    while( cases -- ) {


        scanf("%llu%llu%llu",&p,&q,&n) ;
        unsigned long long int ans ;
        if( n == 0 ) {
            ans = 2 ;
        } else if( n == 1 ) {
            ans = p ;
        } else {
            Matrix<2> X , Y ;
            init( X , Y );
            ans = solve( X , Y ) ;
        }
        cout << "Case " << caseno++ << ": " << ans << "\n" ;
    }




}

