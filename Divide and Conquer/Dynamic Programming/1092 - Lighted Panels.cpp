#include<bits/stdc++.h>
using namespace std ;

int R[8] = { 1 , -1 , 0 , 0 , 1  , -1 , -1 , 1 };
int C[8] = { 0 , 0 , 1 , -1 , -1 , 1  , -1 , 1 };
int r , c , row[10] , dp[8+1][(1<<8)+1][(1<<8)+1] ;
char ch ;

int rec( int pos , int pmask , int curmask ) {

  if( pos == r ) {
    if(pmask==((1<<c)-1))
       return 0 ;
    else
      return (1<<28) ;
  }

  if( dp[pos][pmask][curmask] != -1 )
    return dp[pos][pmask][curmask] ;

  int ret = (1<<28) ;

  for( int i = 0 ; i < (1<<c) ; i++ ) {

    int _cur = curmask ;
    int _back = pmask ;
    int _next = row[pos+1] ;
    int cnt = 0 ;

    for( int j = 0 ; j < c ; j++ ) {
      if( (i&(1<<j)) ) {
        _cur = (_cur^(1<<j));
        for( int k = 0 ; k < 8 ; k++ ) {
          int _r = pos + R[k] ;
          int _c = j + C[k] ;
          if( _r < 0 || _r >= r || _c < 0 || _c >= c  )continue ;
          if( R[k] == 0 )_cur = _cur ^ (1<<_c) ;
          else if( R[k] == -1 )_back = _back ^ (1<<_c) ;
          else if( R[k] == 1 )_next = _next ^ (1<<_c) ;
        }
        cnt ++ ;
      }
    }

    if( pos == 0 ) {
      ret = min( ret , rec(pos+1,_cur,_next)+cnt ) ;
    } else if( _back==((1<<c)-1) ) {
      ret = min( ret , rec(pos+1,_cur,_next)+cnt ) ;
    }

  }

  return dp[pos][pmask][curmask] = ret ;
}



int main() {

  ios_base::sync_with_stdio(0) ;
  cin.tie( NULL ) ;

  int cases , caseno = 1;
  cin >> cases ;
  while( cases -- ) {
    cin >> r >> c ;
    for( int i = 0; i < r ; i++ ) {
      row[i] = 0 ;
      for( int j = 0; j < c ; j++ ) {
        cin >> ch ;
        if( ch == '*' )row[i] = row[i] | (1<<j) ;
      }
    }
    memset( dp , -1 , sizeof dp ) ;
    int ans = rec( 0 , 0 , row[0] ) ;
    cout << "Case " << caseno++ << ": ";
    if( ans >= (1<<28) )cout <<  "impossible\n" ;
    else cout << ans << "\n";
  }


  return 0 ;
}


/*

4
5 5
*****
*...*
*...*
*...*
*****
1 2
.*
3 3
**.
**.
...
4 4
*...
**..
..**
...*

3
3 5
**.**
...**
..*..
8 8
****..*.
****..*.
..*.....
*...**..
*...*.**
...**.**
*****...
********
6 8
******..
******..
***...**
......**
......**
........



*/

