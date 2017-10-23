#include<bits/stdc++.h>
using namespace std ;

long long n , x1 , x2 , yy1 , y2 , idx;//cant declare y1 :(
vector<long long>Y ;

struct sweepPoint {
  long long yy1 , y2 , x , w ;
  sweepPoint() {}
  sweepPoint( long long _yy1 , long long _y2 , long long _x , int _w ) {
    yy1 = _yy1 , y2 = _y2 , x = _x , w = _w ;
  }
  bool operator < ( const sweepPoint & a ) const {
    if( x == a.x )return w > a.w ;
    return x < a.x ;
  }
};
sweepPoint arr[2*30000+3] ;

struct node {
  long long prop , totOne ;
  /*
  -------------
  prop = 000011111000022222000033333300000111222333322110000
       = 000011111000011111000011111100000111111111111110000
totone =       5   +    5    +    6    +         14     =      30
  -------------
  */
  node() {}
  node(long long _prop , long long _totOne) {
    prop = _prop ;
    totOne = _totOne ;
  }
};

node tree[2*30003*8] ;

void build() {
  for( int i = 0 ; i < 2*8*30003 ; i++ ) {
    tree[i] = node(0,0) ;
  }
  Y.clear() ;
  idx=0;
}

void update( int nd , int st , int en , int i ,int j , int w ) {
  if( j < Y[st] || i > Y[en] ) return ;
  if( Y[st]>=i && Y[en]<=j ) {
    tree[nd].prop += w ;
    if( tree[nd].prop ) {
      tree[nd].totOne = Y[en]-Y[st] ;
    } else tree[nd].totOne = tree[nd<<1].totOne + tree[(nd<<1)+1].totOne ;
    return ;
  }
  if( st+1 == en ) return ;
  update( nd<<1 , st , (st+en) >> 1 , i , j , w ) ;
  update( (nd<<1)+1 , (st+en) >> 1 , en , i , j , w ) ;
  if( tree[nd].prop ) {
    tree[nd].totOne = Y[en]-Y[st] ;
  } else tree[nd].totOne = tree[nd<<1].totOne + tree[(nd<<1)+1].totOne ;
  return ;
}

int main() {

  int cases , caseno =1 ;
  scanf("%d",&cases ) ;

  while( cases -- ) {

    scanf("%d",&n) ;

    build() ;

    for( int i = 0 ; i < n ; i ++ ) {
      scanf("%d%d%d%d",&x1,&yy1,&x2,&y2) ;
      arr[idx++] = sweepPoint( yy1 , y2 , x1 , 1 ) ;
      arr[idx++] = sweepPoint( yy1 , y2 , x2 , -1 ) ;
      Y.push_back(yy1) ;
      Y.push_back(y2) ;
    }

    sort( Y.begin(),Y.end() ) ;
    Y.resize( unique(Y.begin(),Y.end())-Y.begin() ) ;

    sort( arr , arr + idx ) ;

    long long ans = 0 ;
    int l = Y.size()-1 ;
    update( 1 , 0 , l , arr[0].yy1 , arr[0].y2 , arr[0].w ) ;
    for( int i = 1 ; i < idx ; i++ ) {
      //cout << "it " << i << ": " << (arr[i].x-arr[i-1].x)  << " " << tree[1].totOne << endl ;
      ans +=  (arr[i].x-arr[i-1].x) * tree[1].totOne ;
      update( 1 , 0 , l , arr[i].yy1 , arr[i].y2 , arr[i].w ) ;
    }
    cout << "Case " << caseno++ << ": " << ans << "\n" ;

  }
  return 0 ;
}

/*
2
3
0 2 3 6
1 3 6 7
2 1 5 4
2
0 0 4 4
1 1 2 5
*/

