#include<bits/stdc++.h>
using namespace std ;
#define MAX 105
#define eps 1e-9

string str[MAX] ;
double dp[MAX][MAX] ;
int vis[2*MAX][2*MAX] ;

int r , c , color ;
int dirR[] = {-1,-1,1,1} ;
int dirC[] = {-1,1,-1,1} ;
double cir = acos(-1.0)/4.0 ;

int getPos( int x ) {
  if( x&1 )return (x-1)>>1 ;
  else return x>>1 ;
}

int getMotif( int x , int y ) {
  x = getPos(x) ;
  y = getPos(y) ;
  if( x == r )x-- ;
  if( y == c )y-- ;
  return str[x][y]-'0' ;
}
int getNum( int x , int y ) {
  return x*500*500+y;
}
int isValid( int x , int y ) {
  return ( x >= 0 && y >= 0 && x <= 2*r && y <= 2*c && vis[x][y] == 0 );
}

bool isOk(int motif,int newMotif,int x,int y) {
  if(motif == 0 && newMotif == 0 && x == -1 && y == 1)return 1 ;
  if(motif == 0 && newMotif == 1 && x == -1 && y == -1)return 1 ;
  if(motif == 0 && newMotif == 0 && x == 1 && y == -1)return 1 ;
  if(motif == 1 && newMotif == 0 && x == -1 && y == 1)return 1 ;
  if(motif == 1 && newMotif == 1 && x == -1 && y == -1)return 1 ;
  if(motif == 1 && newMotif == 0 && x == 1 && y == -1)return 1 ;
  if(motif == 1 && newMotif == 1 && x == 1 && y == 1)return 1 ;
  return 0 ;
}

double rec( int x , int y ) {
//  if( dp[x][y] > 0+eps ) {
//    return dp[x][y] ;
//  }
  if( (x+y)%2==1 ) return 0 ;
  vis[x][y] = 1 ;
  double ret = 0 ;
  int motif = getMotif(x,y) ;
  if( (x&1) && (y&1) ) {
    ret += 4*(1-cir)+cir*2 ;
    if( motif == 0 ) {
      if( isValid(x-1,y+1) ) {
        ret += rec( x-1 , y+1 ) ;
      }
      if( isValid(x+1,y-1) ) {
        ret += rec( x+1 , y-1 ) ;
      }
    } else if( motif == 1 ) {
      if( isValid(x-1,y-1) ) {
        ret += rec( x-1 , y-1 ) ;
      }
      if( isValid(x+1,y+1) ) {
        ret += rec( x+1 , y+1 ) ;
      }
    }
  } else {
    for( int i = 0 ; i < 4 ; i++ ) {
      int R = x + dirR[i] ;
      int C = y + dirC[i] ;
      if( isValid(R,C) ) {
        int newMotif = getMotif(R,C) ;
        if( isOk(motif,newMotif,dirR[i],dirC[i]) ) {
          ret += rec( R , C ) ;
        } else ret += cir ;
      }
    }
  }
  return /*dp[x][y] = */ret ;
}
inline int readInt()
{
    int ip = getchar_unlocked(), ret = 0, flag = 1;

    for(; ip < 48 || ip > 57; ip = getchar_unlocked())
    {
        if(ip == 45)
        {
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

  int cases , caseno = 1 ;
  //cin >> cases ;
  cases = readInt() ;
  while( cases -- ) {

    //cin >> r >> c ;
    r = readInt() ;
    c = readInt() ;
    for( int i = 0 ; i < r ; i++ ) {
      cin >>str[i] ;
    }
    //memset( dp , -1 , sizeof dp ) ;
    int q ;
    //cin >> q ;
    q = readInt() ;
    cout << "Case " << caseno++ << ":\n" ;
    while( q -- ) {
      int x , y ;
      //cin >> x >> y ;
      x = readInt() ;
      y = readInt() ;
      memset( vis , 0 , sizeof vis ) ;
      cout << setprecision(12) << rec(x,y) << "\n" ;
    }
  }
  return 0 ;
}
