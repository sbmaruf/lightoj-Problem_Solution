#include<bits/stdc++.h>
#define pi acos(-1.0)

using namespace std ;

struct Point {
	long long x, y;
	bool operator <(const Point &p) const {
		return x < p.x || (x == p.x && y < p.y);
	}
};
int n ;
double d ;
vector<Point> arr ;

long long cross(const Point &O, const Point &A, const Point &B)
{
	return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convex_hull(vector<Point> P)
{
	int n = P.size(), k = 0;
	vector<Point> H(2*n);

	sort(P.begin(), P.end());

	for (int i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	H.resize(k);
	return H;
}
double dist( Point a , Point b ) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)) ;
}
int main()
{
    int cases , caseno = 1  ;
    scanf("%d",&cases ) ;

    while( cases -- ) {
        scanf("%d%lf",&n,&d) ;
        Point temp ;
        for( int i = 0 ; i < n ; i++ ) {
            scanf("%lld%lld",&temp.x,&temp.y );
            arr.push_back(temp) ;
        }

        double ANS = 0 ;
        if( n == 2 ) {
            ANS = 2*dist( arr[0] , arr[1] ) ;
        } else {
            vector<Point> ConvexHull = convex_hull( arr ) ;
            ConvexHull.push_back(ConvexHull[0]) ;
            for( int i = 0 ; i < ConvexHull.size()-1 ; i++ ){
                ANS += dist( ConvexHull[i] , ConvexHull[i+1] ) ;
            }
        }
        printf("Case %d: %.8f\n",caseno++ , ANS+2.0*pi*d+1e-9 ) ;
        arr.clear() ;
    }

    return 0 ;
}

