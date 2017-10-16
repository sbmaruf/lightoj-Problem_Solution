/*
ID: Ordinary_Sheep
LANG: C++
TASK:
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
#define eps        1e-9
#define sq(a)      ((a)*(a))

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define x          first
#define y          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())
vector<i64> pure ;
vector<i64> ans ;
string p = "1000000000000" ;
int temp[] = { 0 , 4 , 7 } ;

long long int ArraytoInt( string s ){
    int p = 0 ;
    int l = s.size() ;
    for( int i = 0 ; i < l  ; i++ ){
        if( s[i] == '0' ) p++ ;
        else break ;
    }
    if( p == l )return 0;
    i64 A = s[p] - '0' ;
    p++ ;
    if( p == l )return A ;
    for( int i = p ; i < l ; i++ ){
        A = 10*A + (s[i]-'0') ;
    }
    return  A ;
}


void rec( string s , bool res1 , bool res2 , int l ){
    if( l == 13 ){
        //cout << s << endl ;
        long long int a = ArraytoInt( s ) ;
        if(a)pure.pb(a) ;
        return  ;
    }
    if( res1 ){
        rec( s+'0' , 0 , 0 , l+1 ) ;
    }else {
        int k = 0 ;
        if( res2 ) k = 1 ;
        for( int i = k ; i < 3 ; i++ ){
            int t = temp[i] ;
            if( t == 0 ){
                rec( s+'0' , 0 , 0 , l+1 ) ;
            }else {
                char ch = (t+'0') ;
                rec( s + ch  , 0 , 1 , l+1 ) ;
            }
        }
    }
}
#define MAX 1000000000000LL
void make(){

    string s="" ;
    rec( s , 1 , 0 , 0 ) ;
    sort( ALL( pure ) ) ;
    //cout << pure.size() << endl ;
    //cout << pure[pure.size()-1]<<endl ;
    ans = pure ;
   //cout << ans.size() ;
    vector<i64> temp1;
    temp1 = pure ;
//int u = 0 ;
    while(1){
//u++ ;
        vector<i64> temp2 ;

        //cout << pure.size() <<endl ;
        for(int i = 0 ; i<pure.size() ; i++ ){

            bool flag = 0 ;

            for( int j = 0 ; j < temp1.size() ; j++ ){

                i64 q = temp1[j]*pure[i] ;

                if( q > MAX )break ;
                temp2.pb( q ) ;
                flag = 1 ;
            }
            if( !flag )break ;
        }
        if(temp2.size() == 0 )break ;
        temp1 = temp2 ;


        sort( ALL( temp1 ) );
        vector<i64>::iterator it =  unique(ALL(temp1));
        temp1.resize( it - temp1.begin() );

        ans.insert( ans.end() , temp1.begin() , temp1.end() ) ;

    }
    //cout << u << endl ;
    sort( ALL( ans ) );
    vector<i64>::iterator it =  unique(ALL(ans));
    ans.resize( it - ans.begin() );
}

int solve( i64 a ,i64 b ){
    vector<i64>::iterator it1 = upper_bound( ans.begin() , ans.end() , b ) ;
    vector<i64>::iterator it2 = lower_bound( ans.begin() , ans.end() , a ) ;
    return it1 - it2 ;
}

int main()
{
    make();

    int cases , caseno = 1 ;
    //cout << ans.size();
    SI( cases ) ;
    while( cases -- ){

        i64 a , b ;
        SLLD( a ) ;
        SLLD( b ) ;

        printf("Case %d: %lld\n",caseno++ , solve( a , b ) ) ;
    }


    return 0;
}

