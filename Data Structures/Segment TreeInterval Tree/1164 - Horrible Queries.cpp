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
#define SU(a)      scanf("%u",&a)
#define SHD(a)     scanf("%hd",&a)
#define SHU(a)     scanf("%hu",&a)
#define SLLD(a)    scanf("%lld",&a)
#define SLLU(a)    scanf("%llu",&a)
#define SF(a)      scanf("%f",&a)
#define SLF(a)     scanf("%lf",&a)
#define SC(a)      scanf("%c",&a)
#define SS(a)      scanf("%s",a)
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
int N , C ;

void update ( i64 arr[] , int idx , i64 v )
{

    while( idx <= N ) {
        arr[idx] += v ;
        idx += (idx & -idx);
    }

}

i64 read ( i64 arr[] , int idx )
{

    i64 sum = 0 ;
    while( idx > 0 ) {
        sum += arr[idx ] ;
        idx -= ( idx & -idx ) ;
    }
    return sum ;

}

int main()
{

    int cases,caseno=1  ;
    SI( cases ) ;
    while( cases -- ) {

        SI( N ) ;
        SI( C ) ;
        cout << "Case " <<caseno++ << ":\n" ;
        i64 tree1[100001] ;
        i64 tree2[100001] ;
        memset(tree1,0,sizeof tree1);
        memset(tree2,0,sizeof tree2);

        while( C -- ) {
            int T , p , q ;
            SI( T ) ;
            SI( p ) ;
            SI( q ) ;

            if( T == 0 ) {
                int V ;
                p++;
                q++;
                SI( V ) ;

                update ( tree1 , p , V ) ;
                update ( tree1 , q + 1 , -V ) ;
                update ( tree2 , p ,  -( long long )V * ( p - 1 ) ) ;
                update ( tree2 , q + 1 ,  ( long long ) V * q ) ;

            } else {
                p++;
                q++;
                printf("%lld\n", read ( tree1 , q ) * q + read( tree2 , q ) - read(tree1,p - 1) * (p - 1) - read( tree2,p - 1) ) ;
            }
        }



    }

    return 0;
}

