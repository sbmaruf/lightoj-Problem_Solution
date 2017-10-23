#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
int arr[MAX] ;
int tree[MAX] ;
int IDX[MAX] ;
int n , query ;
struct data{
    int idx , st , en ;
    data(){}
    data(int _idx , int _st , int _en ){
        idx = _idx , st = _st , en = _en ;
    }
};
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
data A[50001] ;
bool comp( data a , data b ){
    if( a.en == b.en )return a.st < b.st ;
    return a.en<b.en ;
}

inline int Update( int idx , int val ){
    while( idx <= n ){
        tree[idx] += val ;
        idx += (idx & (-idx)) ;
    }
    return 0;
}
inline int Query( int idx ){
    int ret = 0 ;
    while( idx > 0 ){
        ret += tree[idx] ;
        idx -= (idx & (-idx)) ;
    }
    return ret ;
}

int main() {

    int cases , caseno = 1;
    //scanf("%d",&cases) ;
    cases = readInt() ;

    while( cases -- ){

        //scanf("%d%d",&n,&query) ;
        n = readInt() ;
        query = readInt() ;
        for( int i = 1; i <= n ; i++ ){
            //scanf("%d",&arr[i]) ;
            arr[i] = readInt() ;
        }

        for( int i = 1; i <= query ; i++ ){
            //scanf("%d%d",&A[i].st,&A[i].en) ;
            A[i].st = readInt() ;
            A[i].en = readInt() ;
            A[i].idx = i ;
        }
        sort( A+1 , A + query+1 , comp ) ;

        int ANS[query+1] ;
        int last = 1 ;
        int IDX[MAX] ;

        memset( tree , 0 , sizeof tree ) ;
        memset( IDX , 0 , sizeof IDX ) ;

        for( int i = 1 ; i <= query ; i++ ){
            for( int j = last ; j <= A[i].en ; j++ ){
                (IDX[arr[j]])? Update(IDX[arr[j]] , -1):0 ;
                IDX[arr[j]] = j;
                Update( j , 1 ) ;
            }
            last = A[i].en+1 ;
            ANS[A[i].idx] = Query( A[i].en ) - Query( A[i].st-1 ) ;
        }
        cout << "Case " << caseno++ << ":\n" ;
        for(int i = 1; i <= query ; i++ ){
            cout << ANS[i] << "\n" ;
        }

    }

    return 0;
}

