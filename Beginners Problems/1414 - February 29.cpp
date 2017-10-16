
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
#define pi         acos(-1.0)
#define eps        1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi          first
#define se          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

//int dirR8[]= {0,-1,-1,-1,0,1,1,1};
//int dirC8[]= {1,1,0,-1,-1,-1,0,1};
//int dirR4[]= {0,-1,0,1};
//int dirC4[]= {1,0,-1,0};
//int dirR[]={-2,-1, 1, 2, 2,1,-1,-2};
//int dirC[]={-1,-2,-2,-1, 1,2, 2, 1};

int main()
{
    //ios::sync_with_stdio(0);
    int cases , caseno = 1  ;
    SI( cases ) ;
    //getchar() ;
    while( cases -- )
    {

        int day1 , day2 , mon1 , mon2 , year1 , year2  ;
        string month1 , month2 ;
        char ch ;

        cin >> month1 >> day1 >>ch>> year1 ;
        cin >> month2 >> day2 >>ch >>  year2 ;

        if( month1 == "January" )
        {
            mon1 = 1 ;
        }
        else if( month1 == "February" )
        {
            mon1 = 2 ;
        }
        else if( month1 == "March" )
        {
            mon1 = 3 ;
        }
        else if( month1 == "April" )
        {
            mon1 = 4 ;
        }
        else if( month1 == "May" )
        {
            mon1 = 5 ;
        }
        else if( month1 == "June" )
        {
            mon1 = 6 ;
        }
        else if( month1 == "July" )
        {
            mon1 = 7 ;
        }
        else if( month1 == "August" )
        {
            mon1 = 8 ;
        }
        else if( month1 == "September" )
        {
            mon1 = 9 ;
        }
        else if( month1 == "October" )
        {
            mon1 = 10 ;
        }
        else if( month1 == "November" )
        {
            mon1 = 11 ;
        }
        else if( month1 == "December" )
        {
            mon1 = 12 ;
        }


        if( month2 == "January" )
        {
            mon2 = 1 ;
        }
        else if( month2 == "February" )
        {
            mon2 = 2 ;
        }
        else if( month2 == "March" )
        {
            mon2 = 3 ;
        }
        else if( month2 == "April" )
        {
            mon2 = 4 ;
        }
        else if( month2 == "May" )
        {
            mon2 = 5 ;
        }
        else if( month2 == "June" )
        {
            mon2 = 6 ;
        }
        else if( month2 == "July" )
        {
            mon2 = 7 ;
        }
        else if( month2 == "August" )
        {
            mon2 = 8 ;
        }
        else if( month2 == "September" )
        {
            mon2 = 9 ;
        }
        else if( month2 == "October" )
        {
            mon2 = 10 ;
        }
        else if( month2 == "November" )
        {
            mon2 = 11 ;
        }
        else if( month2 == "December" )
        {
            mon2 = 12 ;
        }

        if( mon1 > 2 ) year1++;
        if( mon2 ==1 ) year2--;
        else if( mon2 == 2 && day2 < 29 )year2--;

        int cnt = 0 ;
        cnt += year2 / 4 - ( year1-1 ) / 4 ;
        cnt -= year2 / 100 - ( year1-1 ) / 100 ;
        cnt += year2 / 400 - ( year1-1 ) / 400 ;

            printf("Case %d: %d\n",caseno++ , cnt ) ;
        }

    return 0;
}
