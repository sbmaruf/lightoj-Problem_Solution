#include<bits/stdc++.h>
using namespace std ;
#define MOD 5000000

int tree[1000+3][1000+3] ;
bool v[1003][1003] ;
void update( int x , int y ){
    int c = y ;
    while( x <= 1002 ){
        y = c ;
        while( y <= 1002 ){
            tree[x][y]++ ;
            y += (y & (-y)) ;
        }
        x += (x & (-x)) ;
    }
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
int query( int x ,int y ){
    if( x < 0 ) x = 0 ;
    if( y < 0 ) y = 0 ;
    int ret = 0 ;
    int c = y ;
    while( x > 0 ){
        y = c ;
        while( y > 0 ){
            ret += tree[x][y] ;
            y -= ( y & (-y)) ;
        }
        x -= (x & (-x)) ;
    }
    return ret ;
}

int main() {

   int cases , caseno = 1 ;
   //scanf("%d",&cases ) ;
   cases = readInt() ;
   while( cases -- ){

        int q ;
        //scanf("%d",&q) ;
        q = readInt() ;
        cout << "Case " << caseno++ << ":\n" ;
        while( q -- ){
            int t ;
//            scanf("%d",&t ) ;
            t = readInt() ;
            if( t == 0 ){
                int x , y ;
                //scanf("%d%d",&x,&y) ;
                x = readInt() ;
                y = readInt() ;
                if( !v[x+2][y+2] ) v[x+2][y+2] = 1,update( x+2 , y+2 )  ;
            }else{
                int x1 , y1 , x2 , y2 ;
                //scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;;
                x1 = readInt() ;
                y1 = readInt() ;
                x2 = readInt() ;
                y2 = readInt() ;
                long long ans = 0 ;
                ans = query( x2+2 , y2+2 ) - query( x2+2 , y1-1+2 ) - query( x1-1+2 , y2+2 ) + query( x1-1+2, y1-1+2 ) ;
                cout << ans << "\n" ;
            }
        }
        memset( tree , 0 , sizeof tree ) ;
        memset( v , 0 , sizeof v ) ;
   }
}

