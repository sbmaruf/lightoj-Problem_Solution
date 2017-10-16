#include<bits/stdc++.h>

#define x first
#define y second.first
#define z second.second

using namespace std ;

typedef pair<double,pair<double,double> > _3Dpoint ;


double dist( _3Dpoint a , _3Dpoint b )
{
    return sqrt( (a.x-b.x)* (a.x-b.x) + (a.y-b.y)* (a.y-b.y) + (a.z-b.z)* (a.z-b.z) ) ;
}

double TS(_3Dpoint point[])
{

    _3Dpoint lthird , rthird ;
    int tmp = 100 ;

    while( tmp -- ) {

        lthird.x = (2*point[0].x+point[1].x)/3.0 ;
        lthird.y = (2*point[0].y+point[1].y)/3.0 ;
        lthird.z = (2*point[0].z+point[1].z)/3.0 ;
        rthird.x = (point[0].x+2*point[1].x)/3.0 ;
        rthird.y = (point[0].y+2*point[1].y)/3.0 ;
        rthird.z = (point[0].z+2*point[1].z)/3.0 ;

        if( dist( lthird,point[2] ) > dist( rthird , point[2] ) )
            point[0] = lthird ;
        else
            point[1] = rthird ;

    }

    double ret = dist( point[0] , point[2] ) ;
    return ret ;
}

int main()
{

    int T ;
    scanf("%d",&T) ;

    for( int i = 0; i < T ; i++ ) {
        _3Dpoint point[3] ;
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&point[0].x,&point[0].y,&point[0].z,&point[1].x,&point[1].y,&point[1].z,&point[2].x,&point[2].y,&point[2].z) ;
        double ans = TS(point) ;
        printf("Case %d: %.10f\n", i+1 , ans );
    }

    return 0 ;
}


