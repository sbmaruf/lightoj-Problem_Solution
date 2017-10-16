
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

int main()
{
    int cases , caseno = 1 ;
    scanf("%d",&cases);

    while( cases -- ) {
        deque<int> a;
        printf("Case %d:\n",caseno++);
        int n , m ;
        scanf("%d%d",&n,&m);
        char str[11] ;
        int p ;
        int sz = 0 ;
        while( m -- ) {
            scanf("%s",str);
            if( str[1] == 'u' ) {
                scanf("%d",&p);
                sz++;
                if( sz > n ) {
                    sz = n ;
                    printf("The queue is full\n");
                    continue ;
                }
                if( str[4] == 'L' ) {
                    a.push_front(p);
                    printf("Pushed in left: %d\n",p);
                } else {
                    a.push_back(p);
                    printf("Pushed in right: %d\n",p);
                }
            } else {
                sz-- ;
                if( sz < 0 ) {
                    sz = 0 ;
                    printf("The queue is empty\n");
                    continue ;
                }
                if( str[3] == 'L') {
                    printf("Popped from left: %d\n",*a.begin());
                    a.pop_front();

                } else {
                    printf("Popped from right: %d\n",*(a.end()-1));
                    a.pop_back();

                }
            }

        }

    }
    return 0;
}
