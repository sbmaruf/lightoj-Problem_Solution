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
#define PI         acos(-1.0)
#define eps        1e-9

bool CHECK(int num,int pos){ return num&(1<<(pos)); }
int SET(int &num,int pos){ return num|=(1<<(pos));}
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
    int cases, caseno=1  ;
    SI( cases ) ;
    while( cases -- ){

        int n , m ;
        SI( n ) ;
        SI( m ) ;

        int limit = 0 ;
        for( int i = 1 ; i <= m ; i++ ){
            limit = SET( limit , i );
        }

        list<int>Li;

        rep( i , n )
            Li.pb( i+1 ) ;

        int flag[21] ; // 2097150
        int FW[21] ;

        rep( i , 21 ){
            flag[i] = 0 ;
            FW[i] = -1 ;
        }

        int cnt = 0 ;
        int index = 1 ;

        while( 1 ){


            if( index == m+1 )
                index = index % m ;

            if( FW[index] == -1 ){
                if( !Li.empty()){
                    for( list<int>::iterator it = Li.begin() ; it != Li.end() ; it++ ){
                         //cout << *it << endl ;
                        if( !CHECK( flag[*it] , index ) ){
                            FW[index] = *it ;
                            Li.erase( it ) ;
                            break ;
                        }
                    }
                }
            }else{
                int temp = FW[index] ;
                flag[temp] = SET( flag[temp] , index ) ;

                FW[index] = -1 ;
                if( !Li.empty()){
                    for( list<int>::iterator it = Li.begin() ; it != Li.end() ; it++ ){
                            //cout << *it << endl ;
                        if( !CHECK( flag[*it] , index ) ){
                            FW[index] = *it ;
                            Li.erase( it ) ;
                            break ;
                        }
                    }
                }
                if( flag[temp] != limit ) Li.push_back( temp  ) ;
            }


//            cout << "Index : " << index << endl ;
//            cout << "List is : " ;for( list<int>::iterator it = Li.begin() ; it != Li.end() ; it++ )cout << *it << " " ;cout << endl ;
//            cout << "FW is : ";for( int i =1 ; i <=m ;i++ )cout << FW[i] << " " ;cout << endl ;
//            cout << endl << endl ;


            cnt ++ ;
            int fg = 1 ;
            for( int i = 1 ; i <= n ; i++ ){
                if( flag[i] != limit ){
                    fg = 0 ;
                    break ;
                }
            }

            if( fg )
                break ;

            index++ ;
        }


        printf("Case %d: %d\n",caseno++ , cnt*5 ) ;

    }

    return 0;
}

