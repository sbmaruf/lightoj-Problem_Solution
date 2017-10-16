#include<bits/stdc++.h>
using namespace std ;

#define MAX 32

int dirR[] = {0,0,0,1,-1,1,-1,-1,1} ;
int dirC[] = {0,1,-1,0,0,1,1,-1,-1} ;
string type[] = {"*","R","L","D","U","DR","UR","UL","DL"} ;
int r , c , q ;
char s[MAX][MAX],str[MAX] ;
//int pathDir[MAX][MAX][MAX] ;
int visX[MAX][MAX][MAX] ;
int visY[MAX][MAX][MAX] ;


pair<int,int> bfs(char in[],int l){
  queue<int>Q ;
  memset( visX , -1 , sizeof visX ) ;
  for( int i = 0 ; i < r ; i++ ){
    for( int j = 0 ; j < c ; j++ ){
      if( s[i][j] == in[0] ) {
        Q.push(i);
        Q.push(j);
        Q.push(0);
      }
    }
  }
  while( !Q.empty() ){
    int x = Q.front() ; Q.pop() ;
    int y = Q.front() ; Q.pop() ;
    int z = Q.front() ; Q.pop() ;
    if( z+1 == l ){
      return {x,y} ;
    }
    for( int k = 0 ; k < 9 ; k++ ){
      int R = x + dirR[k] ;
      int C = y + dirC[k] ;
      if( R >= 0 && R < r && C >= 0 && C < c ){
        if( visX[R][C][z+1] == -1 && s[R][C]==in[z+1] ){
          visX[R][C][z+1] = x ;
          visY[R][C][z+1] = y ;
          Q.push(R) ;
          Q.push(C) ;
          Q.push(z+1) ;
        }
      }
    }
  }
  return {-1,-1} ;
}

void print(int x , int y , int sz ){
  if( sz == 0 ){
    cout << "(" << x+1 << "," << y+1 << ")" ;
    return ;
  }
  int X = visX[x][y][sz] ;
  int Y = visY[x][y][sz] ;
  //cout << X << " = " << Y << endl ;
  print(X,Y,sz-1) ;
  cout << ", " ;
  for( int k = 0 ; k < 9 ; k++ ){
    int R = X+dirR[k] ;
    int C = Y+dirC[k] ;
    if( R == x && C == y ){
      cout << type[k] ;
      break ;
    }
  }
  return ;
}

int main(){

//  ios_base::sync_with_stdio(0);
//  cin.tie(0);

  int cases , caseno = 1 ;
  scanf("%d",&cases) ;
  while( cases -- ){

    scanf("%d%d",&r,&c) ;
    for( int i = 0 ; i < r ; i++ ){
      scanf("%s",s[i]) ;
    }
    cout << "Case " << caseno++ << ":\n" ;
    scanf("%d",&q) ;
    while( q -- ){
      scanf("%s",str) ;
      int l = strlen(str) ;
      pair<int,int>pos = bfs(str,l) ;
      if( pos.first == -1 ) cout << str << " not found\n" ;
      else {
        cout << str << " found: ";
        //cout << pos.first << " " << pos.second << endl ;
        print(pos.first,pos.second,l-1) ;
        cout << "\n" ;
      }
    }
  }

  return 0 ;
}
