#include<bits/stdc++.h>
using namespace std ;



int main() {

    int cases , caseno =1 ;
    scanf("%d",&cases) ;

    while( cases -- ) {

        int n, W ;
        scanf("%d%d",&n,&W) ;

        if( n == 1 ){
            int p;
            scanf("%d",&p);
            if( p <= W ){
                 printf("Case %d: 2\n",caseno++);
            }else  printf("Case %d: 1\n",caseno++);
            continue ;
        }

        int arr1[16] , arr2[16] ;
        int idx1 = 0 , idx2 = 0 ;

        int tmp = n/2 ;
        for( int i = 0 ; i < tmp ; i++ ) {
            scanf("%d", &arr1[idx1++] ) ;
        }

        tmp = n-tmp ;
        for( int i = 0 ; i < tmp ; i++ ) {
            scanf("%d",&arr2[idx2++] );
        }

        vector<long long int> V1 ;
        vector<long long int> V2 ;


        for( int i = 0 ; i < 1<<idx1 ; i++ ) {
            long long int sum = 0 ;
            for( int k = 0 ; k < idx1 ; k++ ) {
                if( i & 1<<k ) {
                    sum += arr1[k] ;
                }
            }
            V1.push_back(sum) ;
        }

        for( int i = 0 ; i < 1<<idx2 ; i++ ) {
            long long int sum = 0 ;
            for( int k = 0 ; k < idx2 ; k++ ) {
                if( i & 1<<k ) {
                    sum += arr2[k] ;
                }
            }
            V2.push_back(sum) ;
        }

        sort( V2.begin() , V2.end() ) ;

        //cout << V1.size() << " " << V2.size() << endl ;
        //for(int i = 0 ;i < V1.size() ; i++)cout << " " <<V1[i] ;cout << endl ;
        //for(int i = 0 ;i < V2.size() ; i++)cout << " " <<V2[i] ;
        
        long long ans = 0 ;
        for( int i = 0 ; i < V1.size() ; i++ ) {
            if( W-V1[i]>= 0 ) {
                int p = upper_bound(V2.begin(),V2.end(),W-V1[i] )-V2.begin() ;
                ans += p ;
            }
        }
        
        printf("Case %d: %lld\n",caseno++,ans );

    }


    return 0 ;

}

