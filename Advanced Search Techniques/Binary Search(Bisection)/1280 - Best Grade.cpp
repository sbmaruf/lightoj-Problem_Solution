#include<bits/stdc++.h>
using namespace std ;
double hi , lo , mid , av ;

bool comp ( pair<double,double> a , pair<double,double> b ){
    return ((100*a.first-mid*a.second)>(100*b.first-mid*b.second) ) ;
}
inline int readInt()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
            flag = -1;
            ip = getchar_unlocked();
            break;
        }
    }

    for(; ip > 47 && ip < 58; ip = getchar_unlocked())
        ret = ret * 10 + ip - 48 ;
    return flag * ret;
}
int main(){

    int cases , caseno =1 ;
    //scanf("%d",&cases ) ;
    cases = readInt() ;

    while( cases -- ){
        int n,d ;
        //scanf("%d%d",&n,&d ) ;
        n = readInt() ;
        d = readInt() ;
        pair<double,double>P[n] ;
        for( int i = 0 ;i < n ; i++ ){
        //     scanf("%lf%lf",&P[i].first , &P[i].second);
            P[i].first = double(readInt()) ;
            P[i].second = double(readInt()) ;
        }

        lo = 0 ;
        hi = 100 ;
        av = 0 ;
        for( int i = 0; i < 14 ; i++ ){
            mid = (lo+hi)/2.0 ;
            sort( P , P + n , comp ) ;
            double Neu = 0 , Den = 0 ;
            for( int i = 0 ; i < (n-d) ; i++ ){
                Neu += P[i].first ;
                Den += P[i].second ;
            }
            double aa = (Neu*100)/Den ;
            //cout << "---  " << aa << " " << mid << endl ;
            if( (aa)<mid ){
                hi = mid ;
            }else{
                av = max( aa , av ) ;
                lo = mid ;
            }
        }

        cout <<setprecision(10) << "Case " << caseno++ << ": " << av << "\n" ;
    }



    return 0 ;
}

