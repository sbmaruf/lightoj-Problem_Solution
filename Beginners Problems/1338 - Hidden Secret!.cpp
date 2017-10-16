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

int arr1[26+1] ;
int arr2[26+1] ;

int main()
{
    int cases , caseno = 1 ;

    SI( cases ) ;
    getchar() ;

    while( cases-- ){


        string s1 , s2 ;
        getline( cin , s1 ) ;
        //cout << s1 <<  endl ;
        getline( cin , s2 ) ;
        //cout << s2 << endl ;

        zero( arr1 ) ; zero( arr2 ) ;

        for( int i  = 0 ; s1[i] ; i++ ){
            if( s1[i] >= 'A' && s1[i] <= 'Z' ){
                arr1[ s1[i] - 'A']++ ;
            }else if( s1[i] >= 'a' && s1[i] <= 'z' ) arr1[ s1[i] - 'a' ]++ ;
        }

        for( int i  = 0 ;s2[i] ; i++ ){
            if( s2[i] >= 'A' && s2[i] <= 'Z' ){
                arr2[ s2[i] - 'A']++ ;
            }else if( s2[i] >= 'a' && s2[i] <= 'z' ) arr2[ s2[i] - 'a' ]++ ;
        }

        int flag = 1 ;
        rep( i , 26 ) {
            if( arr1[i] != arr2[i] ){
                flag = 0 ;
                break ;
            }
        }

        if( flag ){
            printf("Case %d: Yes\n",caseno++) ;
        }else {
            printf("Case %d: No\n",caseno++) ;
        }

    }

    return 0;
}
