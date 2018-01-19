#include<bits/stdc++.h>
#define i64 long long
using namespace std ;

const int MOD = 10007 ;
int n ;

template<int N> class Matrix
{
public:
    int  arr[N][N];
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
                    ret.arr[i][j]+=(((arr[i][k])*(in.arr[k][j]))%MOD) ;
                    ret.arr[i][j]%=MOD ;
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



void init( Matrix<4>& X , Matrix<4>& Y )
{

    X.arr[0][0] = X.arr[0][1] = X.arr[0][2] = X.arr[0][3] = 1 ;
    X.arr[1][0] = 1 ;
    X.arr[2][1] = X.arr[2][3] = 1 ;
    X.arr[3][1] = X.arr[3][2] = 1 ;


}

int solve(Matrix<4>& X,Matrix<4>& Y)
{
    Matrix<4> ANS = (X^(n-1)) ;
    return (ANS.arr[0][0]%MOD+ANS.arr[0][1]%MOD)%MOD ;

}
int main()
{

    int cases , caseno = 1;
    scanf("%d",&cases );

    while( cases -- ) {

        scanf("%d",&n) ;
        Matrix<4> X , Y ;
        init( X , Y ) ;
        int ans = solve(X,Y) ;

        cout << "Case " << caseno++ << ": " << ans << "\n" ;

    }

}

