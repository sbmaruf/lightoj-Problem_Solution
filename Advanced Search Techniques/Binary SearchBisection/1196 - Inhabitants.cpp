#include<bits/stdc++.h>
#define x first
#define y second
using namespace std ;
pair<double,double> P[100000+5] ;
int n ;
inline double isLeft( pair<double,double> a , pair<double,double> b , pair<double,double> c ) {
    //does point b is left or right to ac segment
    return (a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y));
}

inline bool check( double x, double y ) {
    int lo = 1 , hi = n-1 ;  ;
    int mid  ;
    pair<double,double>sample = make_pair(x,y) ;
    while( hi-lo >= 2 ) {
        mid = (lo+hi)>>1 ;
        if( isLeft( P[0], P[mid] , sample ) >= 0 )lo = mid ;
        else hi = mid ;
    }
    double a = isLeft(P[0], P[lo], sample) ;
    if(isLeft(P[0], P[lo], sample) < 0) return 0;
    if(isLeft(P[lo], P[hi], sample) < 0) return 0;
    if(isLeft(P[hi], P[0], sample) < 0) return 0;
    return 1 ;
}
int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;
    while( cases -- ) {
        scanf("%d",&n) ;
        for( int i = 0; i < n ; i++ ) {
            scanf("%lf%lf",&P[i].first ,&P[i].second ) ;
        }
        int query ;
        scanf("%d",&query) ;
        cout << "Case " << caseno++ << ":\n" ;
        while( query -- ) {
            double x , y ;
            scanf("%lf%lf",&x,&y) ;
            if( check( x , y ) ) {
                cout << "y\n" ;
            } else cout << "n\n" ;
        }
    }
    return 0 ;
}
