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
//   bismillahirrahmanirrahim
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
//
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction
//
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

struct comp {
    bool operator() (const int& lhs, const int&rhs) const {
        return (lhs>rhs);
    }
};


char str[100];
priority_queue<char,vector<char>,comp> pq ;
map<char,int>mp ;
int l ;
long long fac[21+1] ;
char ch ;
long long tot ;
char arr[100] ;
int idx = 0 ;

void precal()
{
    fac[0]=1 ;
    fac[1]=1 ;
    for( int i = 2 ; i < 21 ; i++ ) {
        fac[i] = i*fac[i-1] ;
    }
    //cout << fac[20] << endl ;
}

long long calc( long long cnt , int l )
{

    mp.clear() ;
    tot = fac[l] ;

    int c = 0 ;
    idx = 0 ;
    while( !pq.empty() ) {
        ch = pq.top();
        if( mp.find( ch ) == mp.end() ) c++ ;
        if(c != cnt )mp[ch]++ ;
        pq.pop() ;
        str[idx++] = ch ;
    }

    for( map<char,int>:: iterator it = mp.begin() ; it!= mp.end() ; it++ ) {
        tot = tot/fac[it->second] ;
    }
    idx-- ;
    while( idx >= 0 ) {
        pq.push(str[idx]);
        idx-- ;
    }

    return tot ;
}

int main()
{

    precal() ;

    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        while( !pq.empty() )pq.pop()  ;
   // for( int i = 0 ; i < 200 ; i++ ){
        scanf("%s",str) ;
    //char str[] = "abcdefghijklmnopqrst" ;
        long long n ;
        scanf("%lld",&n) ;
//n=2432902008176640000;
        cout << "Case " << caseno++ << ": " ;
        l = 0 ;
        mp.clear() ;
        for( int i = 0;  str[i] ; i++ ) {
            pq.push( str[i] ) ;
            mp[str[i]]++ ;
            l++ ;
        }

        tot = fac[l] ;
        for( map<char,int>:: iterator it = mp.begin() ; it!= mp.end() ; it++ ) {
            tot = tot/fac[it->second] ;
        }
        if( n > tot ) {
            cout << "Impossible\n" ;
            continue ;
        }
        l-- ;

        while( n > 0 && l > 0 ) {

            long long  cnt = 1 ;
            long long ans = calc(cnt,l) ;
            while( n > ans ) {
                cnt ++ ;
                ans+=calc(cnt,l);
            }
            long long  tmp = cnt ;
            long long cmp = ans - calc(cnt,l) ;
            mp.clear() ;
            idx = 0 ;
            while( cnt ) {
                ch = pq.top() ;
                arr[idx++] = ch ;
                if( mp.find(ch) == mp.end() ) {
                    cnt-- ;
                    mp[ch]++;
                }
                pq.pop() ;
            }
            idx-- ;
            cout << arr[idx] ;
            idx-- ;
            while( idx>= 0 ) {
                pq.push( arr[idx] ) ;
                idx-- ;
            }
            n -= cmp ;
            l--;

        }

        while( !pq.empty() ) {
            cout << pq.top() ;
            pq.pop() ;
        }
        cout << "\n" ;

        //}

    }

    return 0;
}



//int main()
//{
//    string s = "aaabbx" ;
//    int cnt = 0 ;
//    do{
//        cnt++;
//        cout << cnt << " " <<  s << endl; ;
//    }while( next_permutation(s.begin(),s.end())) ;
//
//    return 0;
//}

