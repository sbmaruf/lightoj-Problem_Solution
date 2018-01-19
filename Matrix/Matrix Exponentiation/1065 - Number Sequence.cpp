#include<bits/stdc++.h>
using namespace std ;
int a , b , n , m ;


template<int N> class Matrix {

public:
    long long  arr[N][N];

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
                    ret.arr[i][j] += (arr[i][k] ) * ( in.arr[k][j] ) ;
                    ret.arr[i][j] %= 10000 ;
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

void init( Matrix<2>& X ,  Matrix<2>& Y ) {

    // X^(n-1) * Y = ANS

    //given ...
    Y.arr[0][0] = b ;
    Y.arr[1][0] = a ;

    //Solving the recursive function ...
    X.arr[0][0] = 1 ;
    X.arr[0][1] = 1 ;
    X.arr[1][0] = 1 ;
    X.arr[1][1] = 0;

}

int solve( Matrix<2>& X ,  Matrix<2>& Y ,int m  ) {
    int temp[] = {-1, 10 , 100 , 1000 , 10000} ;
    Matrix<2> ANS ;
    X = X^(n-1) ;
    ANS = X * Y ;
    return ANS.arr[0][0] % temp[m] ;
}

int main() {


    int cases , caseno = 1;
    scanf("%d", &cases) ;

    while( cases -- ) {

        scanf("%d%d%d%d",&a,&b,&n,&m) ;

        Matrix<2> X , Y ;

        init( X , Y );
        int ans =  solve( X , Y , m ) ;

        printf("Case %d: %d\n",caseno++ , ans ) ;

    }


    return 0 ;

}

