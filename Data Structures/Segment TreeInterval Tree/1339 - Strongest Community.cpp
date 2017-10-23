#include<bits/stdc++.h>
using namespace std;
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
#define MAX 1000000+2
int arr[MAX] ;
struct node{
  int mx, prefix_mx , suffix_mx ;
  int prefix_val , suffix_val ;
  node(){
    mx=prefix_mx=prefix_val=suffix_mx=suffix_val=0;
  }
  node( int _mx , int _prefix , int _suffix , int _prval , int _suffval ){
    mx = _mx ;
    prefix_mx = _prefix ;
    suffix_mx = _suffix ;
    prefix_val = _prval ;
    suffix_val = _suffval ;
  }
  void merge( node &l , node &r ){
      prefix_val = l.prefix_val ;
      suffix_val = r.suffix_val ;
      prefix_mx = l.prefix_mx ;
      suffix_mx = r.suffix_mx ;
      if( l.prefix_val == r.prefix_val )
        prefix_mx +=r.prefix_mx ;
      if( l.suffix_val == r.suffix_val )
         suffix_mx += l.suffix_mx ;
      mx = max(l.mx,r.mx) ;
      if( l.suffix_val == r.prefix_val ){
        mx = max( l.suffix_mx+r.prefix_mx , mx );
      }
      mx = max(prefix_mx,mx) ;
      mx = max(suffix_mx,mx) ;
  }
};
node tree[MAX*4+5] ;

void init( int nd , int st , int en ){
  if( st == en ){
    tree[nd] = node( 1 , 1 , 1 , arr[st] , arr[st] ) ;
    return ;
  }
  init( nd<<1 , st , (st+en)>>1 ) ;
  init( (nd<<1)+1 , ((st+en)>>1)+1, en ) ;
  tree[nd].merge(tree[nd<<1],tree[(nd<<1)+1]) ;
}

node query( int nd , int st , int en , int x , int y ){
  if( st > y || en < x )return node() ;
  if( st >= x && en <= y )return tree[nd] ;
  node l = query( nd<<1 , st , (st+en)>>1 , x , y ) ;
  node r = query( (nd<<1)+1 , ((st+en)>>1)+1 , en , x , y ) ;
  node par = node();
  par.merge(l,r) ;
  return par ;
}

int main(){
  int cases , caseno = 1 ;
  cases = readInt() ;
  while( cases -- ){
    int N , c , q ;
    N = readInt() ;
    c = readInt() ;
    q = readInt() ;
    for( int i = 1 ; i <= N ; i++ ){
      arr[i] = readInt() ;
    }
    init( 1 , 1 , N ) ;
    cout << "Case " << caseno++ << ":\n" ;
    while( q -- ){
      int x = readInt() ;
      int y = readInt() ;
      cout << query( 1 , 1 , N , x , y ).mx << "\n" ;
    }
  }
  return 0 ;
}

