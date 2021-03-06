/*
Author          :          Saiful Bari
LANG            :          C++
Problem No      :          Light Oj / UVA / SPOJ / LIVE Archive / Codeforces /
Problem Link    :

Learning        :
                            TASK
------------------------------------------------------------

------------------------------------------------------------
*/
   //bismillahirrahmanirrahim
#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI         vector<int>
#define VVI        vector< VI >
#define VIit       VI::iterator
#define pii        pair<int,int>
#define ui64       unsigned long long int
#define i64        long long int
#define pb(a)      push_back(a)
#define mp         make_pair


#define SI(a)      scanf("%d",&a)
#define Si(a)      scanf("%d",&a)
#define SU(a)      scanf("%u",&a)
#define SHD(a)     scanf("%hd",&a)
#define SHU(a)     scanf("%hu",&a)
#define SLLD(a)    scanf("%lld",&a)
#define SLLU(a)    scanf("%llu",&a)
#define SF(a)      scanf("%f",&a)
#define SLF(a)     scanf("%lf",&a)
#define SC(a)      scanf("%c",&a)
#define SS(a)      scanf("%s",a)
#define read       freopen("in.txt","r",stdin)
#define write      freopen("out.txt","w",stdout)
#define PI         acos(-1.0)
#define eps        1e-11
#define sq(a)      ((a)*(a))

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

//bool equalTo ( double a, double b ){
//    if ( abs ( a - b ) <= eps ) return true;
//    else return false;
//}
//bool notEqual ( double a, double b ){
//    if ( abs ( a - b ) > eps ) return true;
//    else return false;
//}
//bool lessThan ( double a, double b ){
//    if ( a + eps < b ) return true;
//    else return false;
//}
//bool lessThanEqual ( double a, double b ){
//    if ( a < b + eps ) return true;
//    else return false;
//}
//bool greaterThan ( double a, double b ){
//    if ( a > b + eps ) return true;
//    else return false;
//}
//bool greaterThanEqual ( double a, double b ){
//    if ( a + eps > b ) return true;
//    else return false;
//}

#define x          first
#define y          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

pair<double , double> Rotate_Point( pair<double,double> P ,pair<double,double> Ref ,double dist, double cosA ,double sinA ){

    //if only theta comes then sinA= sin(theta) , conA = cos( theta ) ;
    double a = sqrt( (P.first-Ref.first)*(P.first-Ref.first) + (P.second-Ref.second)*(P.second-Ref.second) ) ;

    double x1 = (dist*(Ref.first-P.first))/a ;
    double y1 = (dist*(Ref.second-P.second))/a ;

    pair<double,double> ret ;
    ret.first = x1*cosA-y1*sinA+P.first ;
    ret.second = x1*sinA+y1*cosA+P.second ;

    return ret ;

}
int main()
{
    int cases , caseno = 1 ;
    scanf("%d",&cases) ;

    while( cases -- ){

        double Ax , Ay , Bx , By , b , c , d ;
        scanf("%lf%lf%lf%lf%lf%lf%lf",&Ax,&Ay,&Bx,&By,&b,&c,&d ) ;

        double a = sqrt( (Ax-Bx)*(Ax-Bx) + (Ay-By)*(Ay-By) ) ;
        double diff = a-c ;

        double cosA = (diff*diff+d*d-b*b)/(2*diff*d) ;
        double sinA = sqrt( 1 - cosA*cosA ) ;

        pair<double,double> P = mp( Ax , Ay ) ;
        pair<double,double> Ref = mp( Bx , By ) ;
        pair<double,double> D = Rotate_Point( P , Ref , d , cosA , sinA ) ;

//        cosA = (diff*diff+b*b-d*d)/(2*diff*b) ;
//        sinA = sqrt( 1 - cosA*cosA ) ;
//         won't work why ... ?
//        swap( P , Ref ) ;
//        pair<double,double> C = Rotate_Point( P , Ref , b , cosA , sinA ) ;

        pair<double,double>C ;
        C.x = (((Bx-Ax)*( c ))/a)+D.first ;
        C.y = (((By-Ay)*( c ))/a)+D.second ;

        cout <<setprecision(12) << "Case " << caseno++ << ":\n" << C.first << " " << C.second << " " << D.first << " " << D.second << "\n" ;

    }

    return 0;
}

