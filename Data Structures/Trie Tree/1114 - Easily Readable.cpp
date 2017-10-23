#include<bits/stdc++.h>
using namespace std  ;
map<string , int> mp ;
char str[1000000+1] ;
string s ;
string tmp ;
int main()
{

    int cases , caseno =1 ;
    scanf("%d",&cases ) ;

    while( cases -- ) {

        int n ;
        scanf("%d",&n) ;
        getchar() ;
        mp.clear() ;
        while( n -- ) {
            gets( str ) ;
            s = str ;
            if( s.size() > 2 )sort( s.begin()+1 , s.end()-1 ) ;
            mp[s]++ ;
        }

        int k ;
        scanf("%d",&k) ;
        getchar() ;
        cout << "Case " << caseno++ << ":\n" ;
        while( k-- ) {
            gets( str ) ;
            stringstream ss ;
            ss << str ;
            string s ;
            long long ans = 1 ;
            while( ss >> s ) {
                tmp.assign( s.begin() , s.end() ) ;
                if( s.size() > 2 )sort( tmp.begin()+1 , tmp.end()-1 ) ;
                if( mp.find( tmp ) != mp.end() ) {
                    ans *= mp[tmp] ;
                } else {
                    ans = 0 ;
                    break ;
                }
            }
            cout << ans << "\n" ;
        }
    }

}

