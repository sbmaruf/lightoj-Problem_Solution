#include<bits/stdc++.h>
using namespace std ;
#define read freopen("1.txt" , "r" , stdin)
string s ;
int dp[51][6][4] ;
int l ;

bool isVowel( char ch ) {
    if( ch == 'A' || ch == 'E' || ch == 'I' || ch=='O' || ch=='U' || ch == '?' )return 1 ;
    else return 0 ;
}
bool isConsonant( char ch ) {
    if( (ch != 'A' && ch != 'E' && ch != 'I' && ch!='O' && ch!='U' ) || ch=='?' )return 1 ;
    else return 0 ;
}
bool bad() {
    for( int i = 0 ; i < l ; i++ ) {
        if( i+4 < l ) {
            if( isConsonant(s[i]) && isConsonant(s[i+1]) && isConsonant(s[i+2]) && isConsonant(s[i+3]) && isConsonant(s[i+4]) ) {
                return 1 ;
            }
        }
        if( i+2 < l ) {
            if( isVowel( s[i] ) && isVowel( s[i+1] ) && isVowel( s[i+2] ) ) {
                return 1 ;
            }
        }
    }
    return 0 ;
}
int good(int idx,int v , int c ){

    if( v>=3  || c >= 5 ) return 1000000000 ;
    if( idx == l )return 0 ;
    if( dp[idx][c][v] != -1 ) return dp[idx][c][v] ;
    int ret = 0 ;
    if( s[idx] == '?' ){
        ret = good( idx+1 , v+1 , 0 );
        ret = min( ret , good( idx+1 , 0 , c+1 ) ) ;
    }
    else if( isVowel( s[idx] ) ){
        ret = good( idx+1 , v+1 , 0 ) ;
    }else if( isConsonant( s[idx] )) {
        ret = good( idx+1 , 0 , c+1 ) ;
    }
    return dp[idx][c][v] = ret ;

}

int main() {

    //read ;

    int cases , caseno =1 ;
    scanf("%d",&cases) ;

    while( cases -- ) {

        cin >> s ;
        memset( dp , -1 , sizeof( dp ) ) ;
        l = s.size() ;

        bool f1 = bad() ;
        int f2 = good(0,0,0) ;
        //cout <<f2 << endl ;
        if(  f1 && f2 == 0 ) {
            cout << "Case "<< caseno++ << ": " << "MIXED" << "\n" ;
        }else if( f1 ){
            cout << "Case "<< caseno++ << ": " << "BAD" << "\n" ;
        }else if( f2 == 0 ) {
            cout << "Case "<< caseno++ << ": " << "GOOD" << "\n" ;
        }


    }

    return 0 ;

}

