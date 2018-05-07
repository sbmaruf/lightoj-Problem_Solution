#include<bits/stdc++.h>
#define rep(i,n) for( long long i = 0 ; i < n ; i++ )
#define rep1(i,n) for( long long i = 1 ; i <= n ; i++ )
using namespace std ;
string s ,s1 ;
int Next[2*1000000+10];
int failure(string P)
{
    memset( Next , 0 , sizeof(Next) ) ;
    int q = 0 , k , m = P.size() ;
    Next[0] = 0;
    for( int i=1; i < m ; i++ )
    {
        while(q > 0 && P[i]!=P[q])
        {
            q = Next[q-1];
        }
        if(P[q]==P[i]) q++;
        Next[i] = q;
    }
    return P.size()-1-Next[P.size()-1] ;
    /*
    cout << m <<endl ;
    for( int i = 0 ; i< P.size() ; i++ ){
        cout << Next[i] << " " ;
    }cout << endl;
    return 0 ;
    */
}

int main()
{
    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        cin >> s ;
        string tmp = s ;
        reverse( s.begin(),s.end() ) ;
        cout << "Case " << caseno++ << ": " << failure(s+"^"+tmp) << "\n" ;

    }

}

