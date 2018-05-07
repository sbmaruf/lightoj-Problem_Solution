/*
ID: Ordinary_Sheep
LANG: C++
TASK:
*/
   //bismillahirrahmanirrahim
#include <bits/stdc++.h>

using namespace std;

#define zero(arr) memset(arr,0,sizeof(arr));
#define mem(arr,k) memset(arr,k,sizeof(arr));

#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1(i,n) for(int i=1;i<n;i++)
#define FOR(i,m,n,k) for(int i=m;i<n;i=i+k)

#define VI         vector<int>
#define VVI        vector< VI >
#define VIit       VI::iterator
#define pii        pair<int,int>
#define ui64       unsigned long long int
#define i64        long long int
#define pb(a)      push_back(a)
#define mp         make_pair


#define SI(a)      scanf("%d",&a)
#define SU(a)      scanf("%u",&a)
#define SHD(a)     scanf("%hd",&a)
#define SHU(a)     scanf("%hu",&a)
#define SLLD(a)    scanf("%lld",&a)
#define SLLU(a)    scanf("%llu",&a)
#define SF(a)      scanf("%f",&a)
#define SLF(a)     scanf("%lf",&a)
#define SC(a)      scanf("%c",&a)
#define SS(a)      scanf("%s",a)
#define read       freopen("in.txt","r",stdin)
#define write      freopen("out.txt","w",stdout)
#define pi         acos(-1.0)
#define eps        1e-9

//bool CHECK(int num,int pos){ return num&(1<<(pos)); }
//int SET(int &num,int pos){ return num=(1<<(pos));}
//int CLEAR(int &num,int pos) {return num&=~(1<<(pos));}
//int TOGGLE(int num,int pos) {return num^=(1<<(pos)); }

#define fi          first
#define se          second
#define bg          begin()
#define en          end()
#define ALL(x)      (x).begin(), (x).end()
#define TR(i,x)     for(typeof(x.begin()) i=x.begin();i!=x.end();++i)
#define SZ(x)       (int)(x.size())

//
//
//As I understand the algorithm, the failure function for your example should be the following:
//
//1 2 3 4 5 6 7 8 9
//a a b a a b a b b
//
//0 1 0 1 2 3 4 0 0
//
//f - failure function (by definition, this is the length of the longest prefix of the string which is a suffix also)
//
//Here how I built it step by step:
//
//f(a) = 0 (always = 0 for one letter)
//
//f(aa) = 1 (one letter 'a' is both a prefix and suffix)
//
//f(aab) = 0 (there is no the same suffixes and prefixes: a != b, aa != ab)
//
//f(aaba) = 1 ('a' is the same in the beginning and the end, but if you take 2 letters, they won't be equal: aa != ba)
//
//f(aabaa) = 2 ( you can take 'aa' but no more: aab != baa)
//
//f(aabaab) = 3 ( you can take 'aab')
//
//f(aabaaba) = 4 ( you can take 'aaba')
//
//f(aabaabab) = 0 ( 'a' != 'b', 'aa' != 'ab' and so on, it can't be = 5, so as 'aabaa' != 'aabab')
//
//f(aabaababb) = 0 ( the same situation)




//The failure function actually tells us this: if you matched X characters
// of a string, what is the longest suffix of such string such that it's
// also a prefix of a search string. You are asking how it's built, the
// approach is quite straightforward, if you add a new character at the
// end of a string, that is you are building f[x], and if it matches with
// character at position f[x-1], then f[x] is simply f[x-1]+1, the other
// case where it doesn't match you try to find smaller and smaller suffixes
// and check if they match, that is you have a word "accadaccac" for which
// you are building a failure function and you just added the letter 'c',
//  that is you are building failure function for the last letter, letter 'c'.
//   First you check the failure function of the previous letter, it's failure
//   function was 4 because you can match suffix "acca" with the prefix "acca",
//    and now you add the letter 'c', it doesn't match with the letter 'a' succeeding
//     prefix "acca" so you backtrack, to the last good suffix. That is you are now
//      searching for a suffix of "acca" which is also a prefix of "accadaccac" but
//      is smaller than "acca", the answer to that question holds f[length("acca")-1],
//       or f[3] and the answer is f[3] = 1, because suffix of length 1 (just the letter 'a')
//        is also a prefix of a search string, and now you can try if the 'c' matches
//         with the character on the position 1 and voila, it matches, so now you know
//         f[9] = f[f[8]-1]+1 = 2. I hope this will help you. Good luck! :)

int Next[1000000+10];
int Tn , Pn ;
void failure(string P)
{
    int q = 0 , k , m = Pn ;
    Next[0] = 0;
    for( int i=1; i < m ; i++ )
    {
        while(q > 0 && P[i]!=P[q])
        {
            q = Next[q-1];
        }
        if(P[q]==P[i]) q++;
        Next[i] = q;
    }
}

int Matcher( string T , string P ){

    int cnt = 0 ;
    Tn = T.size() ;
    Pn = P.size() ;
    if( Tn < Pn ){
            swap( Tn , Pn ) ;
            swap( T , P ) ;
    }
    failure(P) ;

    int q = 0 ;

    for( int i = 0 ;i < Tn; i++ ){
        while( q > 0  && P[q] != T[i] ){
            q = Next[q-1] ;
        }
        if( P[q] == T[i] )q++ ;
        if( q == Pn ){
            cnt ++ ;
            //pattern occurs with shift i - m .
            q = Next [q-1] ;
        }
    }
    return cnt ;
}
int main()
{
    int cases , caseno = 1 ;
    SI( cases ) ;
    while( cases -- ){

        string s1 , s2 ;
        cin >> s1 >> s2 ;
        printf("Case %d: %d\n", caseno ++ ,Matcher(s1 , s2) ) ;

    }
    return 0;
}

