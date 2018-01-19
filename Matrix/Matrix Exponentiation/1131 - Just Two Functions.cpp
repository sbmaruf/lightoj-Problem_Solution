#include<bits/stdc++.h>
#define i64 long long
using namespace std ;

int a1 , b1 , c1 , a2 , b2 , c2 , f[3] , g[3] ;
int MOD ;

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



void init( Matrix<6>& X , Matrix<6>& Y )
{
    // X^(n-1) * Y = ANS

    //given Y

    Y.arr[0][0] = f[2] ;
    Y.arr[1][0] = f[1] ;
    Y.arr[2][0] = f[0] ;
    Y.arr[3][0] = g[2] ;
    Y.arr[4][0] = g[1] ;
    Y.arr[5][0] = g[0] ;


//    Y = |f(n)   |
//        |f(n-1) |
//        |f(n-2) |
//        |g(n)   |
//        |g(n-1) |
//        |g(n-2) |

    //MATRIX X

    //row0
    X.arr[0][0] = a1 % MOD;
    X.arr[0][1] = b1 % MOD;
    X.arr[0][5] = c1 % MOD;

    //row1
    X.arr[1][0] = 1 ;

    //row2
    X.arr[2][1] = 1 ;

    //row3
    X.arr[3][2] = c2 % MOD;
    X.arr[3][3] = a2 % MOD;
    X.arr[3][4] = b2 % MOD;

    //row4
    X.arr[4][3] = 1 ;

    //row5
    X.arr[5][4] = 1 ;


}
pair<int,int> solve(int n,Matrix<6>& X,Matrix<6>& Y){
    if( n <= 2 ){
        return make_pair(f[n]%MOD,g[n]%MOD) ;
    }else {
        Matrix<6> ANS = (X^(n-2))*Y ;
        return make_pair( ANS.arr[0][0] , ANS.arr[3][0] ) ;
    }
}
int main()
{

    int cases , caseno = 1;
    scanf("%d",&cases );

    while( cases -- ) {

        scanf( "%d%d%d" , &a1 , &b1 , &c1 ) ;
        scanf( "%d%d%d" , &a2 , &b2 , &c2 ) ;
        scanf( "%d%d%d" , &f[0] , &f[1] , &f[2] ) ;
        scanf( "%d%d%d" , &g[0] , &g[1] , &g[2] ) ;
        scanf( "%d" , &MOD ) ;

        Matrix<6> X , Y ;
        init( X , Y ) ;

        int query ;
        scanf( "%d", &query ) ;
        cout << "Case " << caseno++ << ":\n" ;
        while( query -- ){

            int n ;
            scanf( "%d" , &n ) ;
            pair<int,int> ans = solve(n,X,Y) ;

            cout  <<ans.first << " " << ans.second << "\n";


        }

    }




}

