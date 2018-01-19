#include<bits/stdc++.h>
using namespace std ;
class matrix {
public:
    vector<vector<int> >arr;
    matrix() {}
    matrix(int N) {
        vector<int>y;
        for( int i = 0 ; i < N ; i ++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                y.push_back(0);
            }
            arr.push_back(y);
        }
    }
    matrix operator *(const matrix &in) {
        matrix ret ;
        int N=this->arr.size();
        ret=matrix(N);
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ )
                for( int k = 0 ; k < N ; k++ ) {
                    ret.arr[i][j]+=(arr[i][k])*(in.arr[k][j]) ;
                    ret.arr[i][j]%=10 ;
                }
        }
        return ret ;
    }
    matrix operator ^( long long int POW) {
        matrix ret;
        int N=this->arr.size();
        ret=matrix(N);
        for( int i = 0 ; i < N ; i++ ) {
            ret.arr[i][i] = 1 ;
        }
        matrix ME = *this ;
        while( POW ) {
            if( POW&1 ) {
                ret = ret * ME ;
            }
            ME = ME * ME ;
            POW >>= 1 ;
        }
        return ret ;
    }
    matrix operator +(const matrix &x) {
        matrix ret;
        int N=this->arr.size();
        ret=matrix(N);
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                ret.arr[i][j]=(arr[i][j]+x.arr[i][j])%10;
            }
        }
        return ret;
    }
};
int N , k ;
matrix I  ;
matrix rec( matrix A , int n ) {
    matrix ret = matrix(N) ;
    matrix tmp = matrix(N) ;
    matrix p = matrix(N) ;
    matrix q = matrix(N) ;
    matrix t = matrix(N) ;
    if(n == 0 )return I ;
    if( n == 1 )return A ;
    ret = A^(n/2);
    tmp = ret + I ;
    q = rec( A , n/2 ) ;;
    p = tmp * q ;
    if( n & 1 ) {
        t = A^n ;
        return p +t ;
    }
    return p ;
}
int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        scanf("%d%d",&N,&k) ;
        matrix in = matrix(N) ;
        for( int i = 0 ; i < N ; i++ ) {
            for(int j = 0 ; j< N ; j++ ) {
                scanf("%d",&in.arr[i][j]) ;
            }
        }
        cout << "Case " << caseno ++ << ":\n" ;
        I = matrix(N) ;
        for( int i = 0 ; i < N ; i++ )I.arr[i][i]=1 ;
        in = rec( in , k ) ;
        for( int i = 0 ; i < N ; i++ ) {
            for( int j = 0 ; j < N ; j++ ) {
                cout << in.arr[i][j] ;
            }
            cout << "\n" ;
        }
    }
    return 0 ;

}
/*

(1)=A;
f(2) = A + A^2 = A( I + A)
f(3) = A+A^2 +A^3=A(I+A)+A^3
f(3) = A+A^2 +A^3=A(I+A)+A^3
so
if n=even
f(n)=f(n/2)(I+A(n/2)
sry
f(4) = A+A^2+A^3+A^4=A(I+A)+A^3(I+A)=(I+A)(A+A^3)=A(I+A)(I+A^2)
so if n=even
f(n)=f(n/2)(I+A(n/2)
if n==odd
f(n)=( f(n/2)(I+A(n/2) )  + A^n

*/

