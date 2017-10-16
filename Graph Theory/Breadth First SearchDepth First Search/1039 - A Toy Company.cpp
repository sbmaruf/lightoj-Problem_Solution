#include<stdio.h>
#include<queue>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std ;

#define inf 100000000

int arr[27][27][27] ;
char ch1[5],ch2[5] ;

struct Node {
    char a,b,c ;
    Node(char a1 , char b1 , char c1 ) {
        a = a1;
        b = b1;
        c = c1;
    }
};

int bfs() {

    queue<Node> Q ;
    Q.push( Node( ch1[0] , ch1[1] , ch1[2] ) ) ;

    while( !Q.empty() ) {

        Node src = Q.front() ;
        Q.pop() ;

        int I = src.a-'a' ;
        int J = src.b-'a' ;
        int K = src.c-'a' ;

        if( src.a == ch2[0] && src.b == ch2[1] && src.c == ch2[2])
            return arr[I][J][K] ;

        int NI  ;

        NI = I-1 ;
        if( NI < 0 ) NI = 25 ;

        if( !arr[NI][J][K] ) {
            arr[NI][J][K] += arr[I][J][K] + 1 ;
            Q.push( Node( NI+'a' , J+'a' , K+'a') ) ;
        }
        NI = I+1 ;
        if( NI == 26 ) NI = 0 ;

        if( !arr[NI][J][K] ) {
            arr[NI][J][K] += arr[I][J][K] + 1 ;
            Q.push( Node(NI+'a' , J+'a' , K+'a') ) ;
        }

        NI = J-1 ;
        if( NI < 0 ) NI = 25 ;

        if( !arr[I][NI][K] ) {
            arr[I][NI][K] += arr[I][J][K] + 1 ;
            Q.push( Node( I+'a' , NI+'a' , K+'a') ) ;
        }

        NI = J+1 ;
        if( NI == 26 ) NI = 0 ;

        if( !arr[I][NI][K] ) {
            arr[I][NI][K] += arr[I][J][K] + 1 ;
            Q.push( Node(I+'a' , NI+'a' , K+'a') ) ;
        }

        NI = K-1 ;
        if( NI < 0 ) NI = 25 ;

        if( !arr[I][J][NI] ) {
            arr[I][J][NI] += arr[I][J][K] + 1 ;
            Q.push( Node( I+'a' , J+'a' , NI+'a') ) ;
        }
        NI = K+1 ;
        if( NI == 26 ) NI = 0 ;

        if( !arr[I][J][NI] ) {
            arr[I][J][NI] += arr[I][J][K] + 1 ;
            Q.push( Node( I+'a' , J+'a' , NI+'a') ) ;
        }

    }
    return -1 ;
}

int main() {
    //freopen( "in" ,"r" , stdin ) ;
    int cases , caseno = 1 ;
    scanf("%d",&cases ) ;
    getchar() ;
    while( cases -- ) {

        memset( arr , 0  , sizeof( arr ) ) ;
        getchar();

        scanf("%s%s",ch1,ch2) ;

        int n ;
        scanf("%d",&n) ;
        for( int i = 0 ; i< n ; i++ ) {
            char a[1000],b[1000],c[1000] ;
            scanf("%s%s%s",a,b,c) ;
            //cout << a << " " << b << " " << c << endl ;
            for( int i = 0 ; a[i] ; i++ ) {
                for( int j = 0 ; b[j] ; j++ ) {
                    for( int k = 0 ; c[k] ; k++ ) {
                        int p = a[i]-'a' ;
                        int q = b[j]-'a' ;
                        int r = c[k]-'a' ;
                        arr[p][q][r] = inf ;
                    }
                }
            }
        }
        printf("Case %d: ",caseno++);
        if( arr[ch1[0]-'a'][ch1[1]-'a'][ch1[2]-'a'] == inf ) {
            cout << "-1\n" ;
        } else {
            cout << bfs() << "\n" ;
        }



    }


    return 0 ;

}
/*
3

aab
zna
8
a a a
a a z
a z a
z a a
a z z
z a z
z z a
z z z

aaa
aaa
0

aab
nnn
1
a a ab
*/
