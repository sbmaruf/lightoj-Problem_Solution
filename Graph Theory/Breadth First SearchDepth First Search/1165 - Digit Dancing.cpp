#include<bits/stdc++.h>
using namespace std ;
#define MOD1 1299827
#define MOD2 101747
int vis[101748] ;
bool isPrime[] = {0,0,1,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1,0,1,0};

int Hash( vector<int> v ) {
  int ret = 0 ;
  for( int i = 0 ; i < (int)v.size() ; i++ ) {
    ret = ret*10+abs(v[i]) ;
  }
  return ((ret%MOD1)+MOD1)%MOD2 ;
}
struct node {
  vector<int>V ;
  int w ;
  node() {}
  node( vector<int> _V , int _w ) {
    V = _V , w = _w ;
  }
};
void print( vector<int> u ) {
  for( int i = 0  ; i < u.size() ; i++ ) {
    cout << u[i] << " ";
  }
  cout << endl ;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0) ;
  int cases , caseno = 1 ;
  cin >> cases ;
  while( cases -- ) {
    int p ;
    vector<int>V ;
    for( int i = 0 ; i < 8 ; i++ ) {
      cin >> p ;
      V.push_back(p) ;
    }
    for( int i = 0 ; i < MOD2+1 ; i++ ) {
      vis[i] = 1<<28 ;
    }
    queue< node > pq ;
    pq.push(node(V,0)) ;
    vis[Hash(V)]=0 ;
    while( !pq.empty() ) {
      vector<int> u = pq.front().V ;
      int w = pq.front().w ;
      //cout << w << endl ;
      pq.pop() ;
      //print(u) ;
      for( int i = 0 ; i < u.size() ; i++ ) {
        for( int j = i+1 ; j < u.size() ; j++ ) {
          vector<int>t1 ;
          if( ((u[i] > 0 && u[j] < 0)||(u[i] < 0 && u[j] > 0)) && isPrime[abs(u[i])+abs(u[j])] ) {
            int m=u[i] ;
            int f=u[j] ;
            t1=u ;
            vector<int>t=u ;
            {
              u.erase(u.begin()+j) ;
              u.insert(u.begin()+i,f) ;
              //print(u) ;
              int k = Hash(u) ;
              //cout << k << endl << w << " " << endl ;
              if( w+1 < vis[k] ) {
                vis[k] = w+1 ;
                pq.push(node(u,vis[k])) ;
              }
            }
            {
              u.erase(u.begin()+i) ;
              u.insert(u.begin()+i+1,f) ;
              //print(u) ;
              int k = Hash(u) ;
              //cout << k << endl << w << " " << endl ;
              if( w+1 < vis[k] ) {
                vis[k] = w+1 ;
                pq.push(node(u,vis[k])) ;
              }
            }
            {
              t.erase(t.begin()+i) ;
              t.insert(t.begin()+(j-1),m);
              // print(u) ;
              int k = Hash(t) ;
              //cout << k << endl << w << " " << endl ;
              if( w+1 < vis[k] ) {
                vis[k] = w+1 ;
                pq.push(node(t,vis[k])) ;
              }
            }
            {
              t.erase(t.begin()+(j-1));
              t.insert(t.begin()+j,m);
              //print(u) ;
              int k = Hash(t) ;
              //cout << k << endl << w << " " << endl ;
              if( w+1 < vis[k] ) {
                vis[k] = w+1 ;
                pq.push(node(t,vis[k])) ;
              }
            }
            u=t1 ;
          }
        }
      }
    }
    cout << "Case " << caseno++ << ": " ;
    if( vis[13869]==(1<<28) ) {
      cout << -1 << "\n" ;
    } else cout << vis[13869] << "\n" ;
  }

  return 0 ;
}

/*
5
1 2 4 5 6 -7 -3 8
1 2 3 4 5 6 7 8
1 2 3 5 -4 6 7 8
1 2 3 5 4 6 7 8
2 -8 -4 5 6 7 3 -1
*/
