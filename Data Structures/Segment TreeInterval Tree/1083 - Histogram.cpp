#include<bits/stdc++.h>
using namespace std ;
int arr[30000+2] , n ;
int Set[30000+2]  ;
int idx = 0 , frnt ;
long long val , len ;
inline long long histogram() {
  long long ret = -1 ;
  idx = 0 ;
  int i = 0 ;
  while( i < n ) {
    if( (idx == 0 || arr[Set[idx-1]]<= arr[i] ) ) {
      Set[idx++]=i++ ;
    } else {
      val = arr[Set[idx-1]] ;
      idx--;
      len = idx==0?i:i-Set[idx-1]-1 ;
      val = val*len ;
      if( val > ret )ret = val ;
    }
  }
  while( idx > 0 ) {
    val = arr[Set[idx-1]] ;
    idx--;
    len = idx==0?i:i-Set[idx-1]-1 ;
    val = val*len ;
    if( val > ret )ret = val ;
  }
  return ret ;
}

struct Input {
  #define maxBufSize (1 << 23)
  #define maxStrSize (1 << 23)
  int bufSize, bufEnd, bufPos;
  char buffer[maxBufSize];
  void grabBuffer() {
    bufSize = (maxBufSize);
    bufPos = 0;
    bufEnd = fread(buffer, sizeof (char), bufSize, stdin);
    buffer[bufEnd] = '\0';
  }
  bool bufEof() {
    return bufPos == bufEnd;
  }
  int getChar() {
    return buffer[bufPos++];
  }
  void skipWS() {
    while ((buffer[bufPos] == '\n' ||
            buffer[bufPos] == ' ' || buffer[bufPos] == '\t'))
      bufPos++;
  }
  int rUint() {
    int n = 0, x;
    skipWS();
    for (int x = getChar(); x <= '9' && x >= '0'; x = getChar())
      n = (n << 3) + (n << 1) + (x - '0');
    return n;
  }
  int Int() {
    int sign = 0, n = 0, x;
    skipWS();
    if (buffer[bufPos] == '-')
      sign = 1, getChar();
    for (x = getChar(); x <= '9' && x >= '0'; x = getChar())
      n = (n << 3) + (n << 1) + (x - '0');
    return sign == 0? n: -n;
  }
  inline bool isWhiteSpace(char x) {
    return x == ' ' || x == '\n' || x == '\t';
  }
  string rStr() {
    char result[maxStrSize];
    skipWS();
    int idx = 0, x;
    for (x = getChar(); !isWhiteSpace(x); x = getChar())
      result[idx++] = x;
    result[idx] = '\0';
    return result;
  }
  char rChar() {
    skipWS();
    return getChar();
  }
};

int main() {

  Input read;
  read.grabBuffer() ;

  int cases , caseno = 1 ;
  cases = read.Int() ;

  while( cases -- ) {
    n = read.Int() ;
    for( int i = 0 ; i < n ; i++ ) {
      arr[i] = read.Int() ;
    }
    cout << "Case " << caseno++ << ": " << histogram() << "\n" ;
  }

  return 0 ;
}

