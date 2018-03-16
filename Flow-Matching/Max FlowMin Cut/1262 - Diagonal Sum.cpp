//this is not my code... I just run it for debugging purpose....
#include<bits/stdc++.h>

#define pause           system("pause");
#define FOR(s,e,inc)    for(int i=s;i<=e;i+=inc)
#define mod             1000000007
#define inf             1<<30
#define pb              push_back
#define ppb             pop_back
#define mp              make_pair
#define F               first
#define S               second
#define sz(x)           ((int)x.size())
#define sqr(x)          ( (x)* (x) )
#define eps             1e-9
#define lcm(x,y)        (abs(x) /gcd(x,y))* abs(y)
#define on(x,w)         x|(1<<w)
#define check(x,w)      (x&(1<<w))
#define all(x)          (x).begin(),(x).end()
#define pf              printf
#define pi              acos(-1.0)
#define reset(x,v)      memset(x,v,sizeof(x));
#define AND             &&
#define OR              ||
#define what_is(x)      cerr<<#x<<" is "<<x<<"\n";

typedef long long ll;
typedef unsigned long long llu;

using namespace std;


template<class T>
inline T mod_v(T num)
{
    if(num>=0)
        return num%mod;
    else
        return (num%mod+mod)%mod;
}
template<class T>
inline T gcd(T a,T b)
{
    a=abs(a);
    b=abs(b);

    while(b)
    {
        a=a%b;
        swap(a,b);
    }

    return a;
}

template<class T>
T fast_pow(T n , T p)
{
    if(p==0) return 1;
    if(p%2)
    {
        T g=mod_v ( mod_v(n) * mod_v(fast_pow(n,p-1)) );
        return g;
    }
    else
    {
        T g=fast_pow(n,p/2);
        g=mod_v( mod_v(g) * mod_v(g) ) ;
        return g;
    }
}

template<class T>
inline T modInverse(T n)
{
    return fast_pow(n,mod-2);
}

template<class T>
inline void debug(string S1,T S2,string S3)
{
    cout<<S1<<S2<<S3;
}

bool equalTo ( double a, double b ){ if ( fabs ( a - b ) <= eps ) return true; else return false; }
bool notEqual ( double a, double b ){if ( fabs ( a - b ) > eps ) return true; else return false; }
bool lessThan ( double a, double b ){ if ( a + eps < b ) return true; else return false; }
bool lessThanEqual ( double a, double b ){if ( a < b + eps ) return true;   else return false;}
bool greaterThan ( double a, double b ){if ( a > b + eps ) return true;else return false;}
bool greaterThanEqual ( double a, double b ){if ( a + eps > b ) return true;else return false;}


template<class T>
inline T in()
{
    register char c=0;
    register T num=0;
    bool n=false;
    while(c<33)c=getchar();
    while(c>33){
        if(c=='-')
            n=true;
        else num=num*10+c-'0';
        c=getchar();
    }
    return n?-num:num;
}

/******* ! Code start from here ! *******/

int visit[205]={0},cc;
int cap[205][205];
vector<int>aj_list[205];
int d[205],cost[205],par[205];
int n,m;

int main()
{
 //    std::ios_base::sync_with_stdio(false);

	int t=in<int>(),tcase=1;
	cc=1;

	while(t--)
	{
		n=in<int>();
		m=in<int>();

        int s=2*(n+m)-1;

		fill(aj_list,aj_list+s+1,vector<int>() );


		for(int i=1;i<=2*(n+m)-2 ;i++)
			d[i]=in<int>();

		for(int i=1;i<=n+m-1;i++)
		{
			aj_list[0].pb(i);
			aj_list[i].pb(0);

			cap[0][i]=d[i];
		}


		for(int i=n+m;i<=2*(n+m)-2 ;i++)
		{
			aj_list[i].pb(s);
			aj_list[s].pb(i);

			cap[i][s] =d[i];
		}

		for(int i=1,j=n+m+m-1;i<=n;i++,j++)
		{
			for(int k=0;k<m;k++)
			{
				aj_list[i+k].pb(j-k);
				aj_list[j-k].pb(i+k);
		//	printf("(%d %d) ",i+k,j-k);
				cap[i+k][j-k]=99;
				cap[j-k][i+k]=0;
				cap[0][i+k] -- ;
				cap[j-k][s] -- ;
			}
			//	printf("\n");
		}
		bool ok=true;

		while(ok)
		{
			ok=false;

			queue<int>st;

			st.push(0);

			cost[0]=inf;

			while(!st.empty())
			{
				int nw=st.front();
				st.pop();

				if(nw==s)
				{
					int c=cost[nw];
					while(nw!=0)
					{
					//	printf("%d ",nw);
						cap[par[nw] ][nw]-=c;
						cap[nw][par[nw] ]+=c;
						nw=par[nw];
					}
					//printf("\n");
				//	printf("Cost: %d\n",c);
					ok=true;
					break;
				}
//printf("nw :  %d\n ",nw);
				for(int i=0;i<sz(aj_list[nw] );i++ )
				{
					int k=aj_list[nw][i];
//printf("k :  %d\n ",k);
					if(visit[k]!=cc &&  cap[nw][k] > 0 )
					{

						st.push(k);
						cost[k]=min(cost[nw],cap[nw][k] );
						par[k]=nw;
						visit[k] = cc ;
					}
				}


			}

			cc++;
		}
		printf("Case %d:\n",tcase++);
		for(int i=1,j=n+m+m-1,x=1;i<=n;i++,j++,x++)
		{
			for(int k=0,y=1;k<m;k++,y++)
			{
			    if( k != 0 ) cout << " " ;
				printf("%d",cap[j-k][i+k]+1 );
			}
			printf("\n");

		}

	}

    return 0;
}

