#include<bits/stdc++.h>
using namespace std ;

struct trie {
  int next[2] ;
  trie() {
    next[0] = next[1] = -1 ;
  }
} tree[50002*32] ;
int arr[50002] , Xor[50002] , idx , temp ;

void Insert( int n ) {
  int root = 0 ;
  for( int i = 31 ; i >= 0 ; i-- ) {
    bool bit = (n&(1<<i)) ;
    if( tree[root].next[bit] == -1 ) {
      tree[root].next[bit]=idx++ ;
    }
    root = tree[root].next[bit] ;
  }
  return ;
}

int Query( int n , bool f ) {
  int root = 0 , ret = 0 ;
  for( int i = 31 ; i >= 0 ; i-- ) {
    bool bit = (n&(1<<i)) ;
    if( !f ) {
      if( tree[root].next[1-bit] != -1 )bit = 1-bit ;
    } else {
      if( tree[root].next[bit] == -1 )bit = 1-bit ;
    }
    root = tree[root].next[bit] ;
    ret = (ret*2) + (int)bit;
  }
  return ret^n ;
}
inline int readInt() {
  int ip = getchar_unlocked(), ret = 0, flag = 1;

  for(; ip < 48 || ip > 57; ip = getchar_unlocked()) {
    if(ip == 45) {
      flag = -1;
      ip = getchar_unlocked();
      break;
    }
  }

  for(; ip > 47 && ip < 58; ip = getchar_unlocked())
    ret = ret * 10 + ip - 48 ;
  return flag * ret;
}
int main() {

  int cases , caseno = 1;
  cases = readInt() ;

  while( cases -- ) {

    for( int i = 0; i <= idx ; i++ ) {
      tree[i] = trie() ;
    }
    idx = 1 ;

    int n ;
    n = readInt() ;

    Xor[0] = 0 ;
    arr[1] = readInt() ;
    int mx = arr[1] ;
    int mn = arr[1] ;
    Xor[1] = arr[1] ;
    Insert(Xor[1]) ;

    for( int i = 2; i <= n ; i++ ) {

      arr[i] = readInt() ;
      Xor[i] = Xor[i-1]^arr[i] ;

      if( mx < Xor[i] ) mx = Xor[i]  ;
      if( mn > Xor[i] ) mn = Xor[i]  ;

      temp = Query(Xor[i] , 0 ) ;
      if( mx < temp ) mx = temp  ;

      temp = Query(Xor[i] , 1 ) ;
      if( mn > temp ) mn = temp ;

      Insert( Xor[i] ) ;
    }

    cout << "Case " << caseno++ << ": " << mx << " " << mn << "\n" ;

  }

  return 0 ;
}



