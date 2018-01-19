#include<cstdio>
using namespace std ;
int a , b , n , c ;


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
            for( int j = 0 ; j < N ; j++ ) {
                for( int k = 0 ; k < N ; k++ ) {
                    ret.arr[i][j] += (arr[i][k] ) * ( in.arr[k][j] ) ;
                    ret.arr[i][j] %= 10007 ;
                }
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

void init( Matrix<4>& X ,  Matrix<4>& Y ) {

    // X^(n-1) * Y = ANS

    //given ...
//    Y.arr[0][0] = 0 ;
//    Y.arr[1][0] = 0 ;
//    Y.arr[2][0] = 0 ;
    Y.arr[3][0] = c ;

    //Solving the recursive function ...
    X.arr[0][0] = a ; /*X.arr[0][1] = 0*/ ;
    X.arr[0][2] = b  ;
    X.arr[0][3] = 1 ;
    X.arr[1][0] = 1 ;/* X.arr[1][1] = 0 ; X.arr[1][2] = 0  ; X.arr[1][3] = 0 */;
    /*X.arr[2][0] = 0 ;*/ X.arr[2][1] = 1 ; /*X.arr[2][2] = 0  ; X.arr[2][3] = 0 */;
    /* X.arr[3][0] = 0 ; X.arr[3][1] = 0 ; X.arr[3][2] = 0  ;*/ X.arr[3][3] = 1 ;

}

int solve( Matrix<4>& X ,  Matrix<4>& Y ) {
    Matrix<4> ANS ;
    X = X^(n-2) ;
    ANS = X * Y ;
    return ANS.arr[0][0] ;
}

int main() {


    int cases , caseno = 1;
    scanf("%d", &cases) ;

    while( cases -- ) {

        scanf("%d%d%d%d",&n,&a,&b,&c) ;

        if( n <= 2 ) {
            printf("Case %d: 0\n",caseno++ );
            continue ;
        }
        
        Matrix<4> X , Y ;

        init( X , Y );
        int ans =  solve( X , Y ) ;

        printf("Case %d: %d\n",caseno++,ans );

    }


    return 0 ;

}

