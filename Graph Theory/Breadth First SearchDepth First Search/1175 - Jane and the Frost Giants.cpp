/*
ID: prime.m2
TASK:
LANG: C++
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

bool CHECK(int num,int pos) {
    return num&(1<<(pos));
}
int SET(int &num,int pos) {
    return num=(1<<(pos));
}
int CLEAR(int &num,int pos) {
    return num&=~(1<<(pos));
}
int TOGGLE(int num,int pos) {
    return num^=(1<<(pos));
}

#define fi          first
#define se          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())
#define sync {ios_base::sync_with_stdio(0);cin.tie(NULL);}


int dirR8[]= {0,-1,-1,-1,0,1,1,1};
int dirC8[]= {1,1,0,-1,-1,-1,0,1};
int dirR4[]= {0,-1,0,1};
int dirC4[]= {1,0,-1,0};
int dirR[]= {-2,-1, 1, 2, 2,1,-1,-2};
int dirC[]= {-1,-2,-2,-1, 1,2, 2, 1};

#define MAX 1000+10


int r , c ;
char G[MAX][MAX] ;

bool Jvis[MAX][MAX] ;
bool Fvis[MAX][MAX] ;

int Jval[MAX][MAX] ;
int Fval[MAX][MAX] ;

pair< int  , int > Jpos ;
int found = 0 ;
void init(int k) {

    if( k == 1 ) {
        rep( i , r )
        rep( j , c ) {
            Jval[i][j] = -1 ;
            Jvis[i][j] = 0 ;
        }
    } else {
        rep( i , r )
        rep( j , c ) {
            Fval[i][j] = -1 ;
            Fvis[i][j] = 0 ;
        }
    }

}

void Jbfs() {

    init(1);

    queue< int > Q ;

    Q.push( Jpos.first ) ;
    Q.push( Jpos.second ) ;

    Jvis[Jpos.first][Jpos.second] = 1 ;
    Jval[Jpos.first][Jpos.second] = 0 ;

    while( !Q.empty() ) {

        int i = Q.front() ;
        Q.pop() ;
        int j = Q.front() ;
        Q.pop() ;

        rep( k , 4 ) {

            int R = i + dirR4[k] ;
            int C = j + dirC4[k] ;

            if( R >=0 && R < r &&  C >= 0 && C < c ) {
                if( !Jvis[R][C] ) {
                    if( G[R][C] == '.') {

                        Jval[R][C] = Jval[i][j] + 1 ;
                        Jvis[R][C] = 1 ;
                        Q.push( R ) ;
                        Q.push( C ) ;

                    }
                }
            }
        }

    }

}

void Fbfs() {

    init(2) ;

    queue< int > Q ;

    rep( i , r )
    rep( j ,c ) {
        if( G[i][j] == 'F' ) {
            Q.push( i ) ;
            Q.push( j ) ;
            Fvis[i][j] = 1 ;
            Fval[i][j] = 0 ;
        }
    }

    while( !Q.empty() ) {

        int i = Q.front() ;
        Q.pop() ;
        int j = Q.front() ;
        Q.pop() ;

        rep( k , 4 ) {

            int R = i + dirR4[k] ;
            int C = j + dirC4[k] ;

            if( R>= 0 && R < r && C >= 0 && C < c ) {
                if( !Fvis[R][C] ) {
                    if( G[R][C] == '.' ) {
                        Fval[R][C] = Fval[i][j] + 1 ;
                        Fvis[R][C] = 1 ;
                        Q.push(R) ;
                        Q.push(C) ;

                    }
                }
            }
        }

    }

}


int main() {

    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases -- ) {
        cin >> r >> c ;

        found = 0 ;

        rep( i , r )
        rep( j , c ) {
            cin >> G[i][j] ;
            if( G[i][j] == 'J' ) {
                Jpos.first = i ;
                Jpos.second = j ;
            } else if( G[i][j] == 'F') {
                found = 1 ;
            }
        }

        Jbfs() ;
        if( found ) Fbfs() ;


        int ans = numeric_limits<int>::max() ;
        if( found ) {
            rep( i , r ) {
                if( Jval[i][0] != -1 ) {
                    if( Fval[i][0] != -1 ) {
                        if( Fval[i][0] > Jval[i][0] ) {
                            ans = min( ans , Jval[i][0] ) ;
                        }
                    } else ans = min( ans , Jval[i][0] ) ;
                }
                if( Jval[i][c-1] != -1 ) {
                    if( Fval[i][c-1] != -1 ) {
                        if( Fval[i][c-1] > Jval[i][c-1] ) {
                            ans = min( ans , Jval[i][c-1] ) ;
                        }
                    } else ans = min( ans , Jval[i][c-1] ) ;
                }
            }

            rep( i , c ) {
                if( Jval[0][i] != -1 ) {
                    if( Fval[0][i] != -1 ) {
                        if( Fval[0][i] > Jval[0][i] ) {
                            ans = min( ans , Jval[0][i] ) ;
                        }
                    } else  ans = min( ans , Jval[0][i] ) ;
                }
                if( Jval[r-1][i] != -1 ) {
                    if( Fval[r-1][i] != -1 ) {
                        if( Fval[r-1][i] > Jval[r-1][i] ) {
                            ans = min( ans , Jval[r-1][i] ) ;
                        }
                    } else ans = min( ans , Jval[r-1][i] ) ;
                }
            }
        } else {
            rep( i , r ) {
                if( Jval[i][0] != -1 ) {
                    ans = min( ans , Jval[i][0] ) ;
                }
                if( Jval[i][c-1] != -1 ) {
                    ans = min( ans , Jval[i][c-1] ) ;
                }
            }
            rep( i , c ) {
                if( Jval[0][i] != -1 ) {
                    ans = min( ans , Jval[0][i] ) ;
                }
                if( Jval[r-1][i] != -1 ) {
                    ans = min( ans , Jval[r-1][i] ) ;
                }
            }
        }
        if( ans == numeric_limits<int>::max() ) {

            printf("Case %d: IMPOSSIBLE\n",caseno++) ;
        } else printf("Case %d: %d\n",caseno++,ans+1) ;

    }




    return 0;
}
