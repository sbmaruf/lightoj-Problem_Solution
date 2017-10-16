#include<bits/stdc++.h>
using namespace std ;
#define MOD 1000000007
long long _pow( long long a , long long b ){
  if( b == 0 ) return 1LL ;
  if( b & 1 ){
    return (a*_pow(a,b-1))%MOD ;
  }else{
    long long t = _pow( a , b>>1 )%MOD ;
    return (t*t)%MOD ;
  }
}

int main(){
  int cases , caseno =1 ;
  scanf("%d",&cases ) ;
  while( cases -- ){

    long long n , K ;
    scanf("%lld%lld",&n,&K) ;
    long long ans = 0 ;
    for( long long i = 0; i <= n-1 ; i++ ){
      ans += ((_pow( K , __gcd(i,n)))*_pow(n,MOD-2))%MOD ;
      ans = ans % MOD ;
      //cout << ans << " " << _pow(K , __gcd(i,n)) << " " << _pow(K , __gcd(i,n))/n << endl ;
    }
    cout << "Case " << caseno++ << ": " << ans << "\n" ;
  }
  return 0 ;
}


/*
It's called Burnside's lemma and says (citing from Wikipedia):
 let G be a finite group that acts on a set X. Then the number
  of orbits is equal to the average number of points fixed by
  an element of G. What does this all mean and how is this
  applicable to programming competitions? Let's continue with
  an example. A standard problem that is best solved using Burnside's
   lemma is: consider a circular stripe of n cells. How many
    ways are there to color these cells with two colors, black
    and white, up to a rotation? Here, X is a set of all colored
    stripes (it has 2^n elements), and G is the group of its
    rotations (it has n elements: rotation by 0 cells, y 1 cell,
    by 2 cells, etc, by (n-1) cells), and an orbit is exactly
    the set of all stripes that can be obtained from each
    other using rotations, so the number of orbits will be
    the number of distinct stripes up to a rotation. Now let's
     apply the lemma, and find the number of stripes that are
     fixed by the rotation by K cells. If a stripe becomes itself
     after rotating by K cells, then its 1st cell must have the same
     color as its (1+K modulo n)-th cell, which is in turn the same
     as its (1+2K modulo n)-th cell, etc, until we get back to the
      1st cell when m*K modulo n=0. One may notice that this will
      happen when m=n/gcd(K,n), and thus we get n/gcd(K,n) cells
      that must all be of the same color. Analogously, the same
      amount of cells must be of the same color starting with cell
      2, (2+K modulo n), etc. Thus, all cells are separated into gcd(K,n)
       groups, with each group being of one color, and that yields us
       2^gcd(K,n) choices. An by Burnside's lemma, the answer to the
       original problem is sum(2^gcd(K,n))/n, where the sum is taken
       over K from 0 to n-1.
*/
