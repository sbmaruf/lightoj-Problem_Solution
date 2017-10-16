#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI vector<int>
#define VVI vector< VI >
#define VIit VI::iterator
#define pi pair<int,int>
#define ui64 unsigned long long int
#define i64 long long int
#define pb(a) push_back(a)
#define mp make_pair


#define SI(a) scanf("%d",&a)
#define Si(a) scanf("%d",&a)
#define SU(a) scanf("%u",&a)
#define SHD(a) scanf("%hd",&a)
#define SHU(a) scanf("%hu",&a)
#define SLLD(a) scanf("%lld",&a)
#define SLLU(a) scanf("%llu",&a)
#define SF(a) scanf("%f",&a)
#define SLF(a) scanf("%lf",&a)
#define SC(a) scanf("%c",&a)
#define SS(a) scanf("%s",a)
#define read freopen("in.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define PI acos(-1.0)
#define eps 1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi first
#define se second
#define bg begin()
#define en end()
#define ALL(x) (x).begin(), (x).end()
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x) (int)(x.size())
int N , K ;
int arr[1000+10] ;

bool ok(int mid)
{

    int dist = 0 ;
    int night = 0 ;
    for( int i = 0 ; i < N+1 ; i++ ) {
        if( arr[i] >mid )return 0 ;
        dist+=arr[i] ;
        if( dist>mid ) {
            night++ ;
            dist=0;
            i-- ;
        }
    }
    if( dist!= 0 )night++ ;
    if( night <= K+1 )return 1 ;
    else return 0 ;


}



int main()
{

    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases -- ) {

        SI( N ) ;
        SI( K ) ;
        int sum = 0 ;
        rep( i , N+1 ) {
            SI( arr[i] ) ;
            sum += arr[i] ;
        }

        int l = 1 ;
        int r = sum ;

        while( r-l >= 4 ) {

            int mid = (l+r)/2 ;

            if( ok(mid) ) {
                r = mid -1 ;
            } else {
                l = mid ;
            }

        }

        int i ;
        for( i = l ; i<= r ; i++ ) {
            if( ok(i) == 1 )break ;
        }

        printf("Case %d: %d\n",caseno++,i );


        pair< int , pi > P[K+1+1 ] ;
        int Pindex = 0 ;
        int st = 0 ;
        int En = 0 ;
        int ans = i ;
        int dist = 0 ;
        for( int i = 0 ; i < N+1 ; i++ ) {
            dist+=arr[i] ;
            if( dist>ans ) {
                En = i-1 ;
                P[Pindex++] = mp ( (dist-arr[i] ) , mp(st , En ) ) ;
                dist=0;
                i-- ;
                st = i+1 ;
                En = i +1;
            }
        }
        if( dist != 0 ) {
            P[Pindex++] = mp ( dist , mp ( st , N ) ) ;
        }

// for( int i = 0 ; i < Pindex ; i++ ) {
// cout << P[i].first << " " << P[i].second.first << " " << P[i].second.second << endl ;
// }
        vector<int>Ans;
        if( Pindex == K+1 ) {
            rep( i , Pindex ) {
                printf("%d\n",P[i].first ) ;
            }
        } else {
            int extra = K+1 - Pindex ;
            for( int i = Pindex-1 ; i >= 0 ; i-- ) {
                if( extra ) {
                    int st = P[i].second.first ;
                    int En = P[i].second.second ;
                    if( (En - st )== 0 ) {
                        Ans.pb( P[i].first ) ;
// continue ;
                    } else {
                        int j ;
                        for( j = En ; j >= st && extra ; j-- , extra-- ) {
                            Ans.pb( arr[j] ) ;
                        }
                        if( j <st )extra++;
                        if( j >=st ) {
                            int sum = 0 ;
                            for( int k = j ; k >= st ; k--) {
                                sum+=arr[k] ;
                            }
                            Ans.pb( sum ) ;
                        }
                    }
                } else Ans.pb( P[i].first ) ;
            }
        }

        for( int i = Ans.size() -1 ; i>= 0 ; i-- ) {
            cout << Ans[i] << endl;
        }



    }

    return 0 ;
}

