//This is not my code. I am just testing others code.
 
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //ios_base::sync_with_stdio(0);
//    cin.tie(0);
    int t;
    string s;
    cin>>t;
    for(int l=1;l<=t;l++)
    {
//        printf("Case %d:\n",l);
        cout << "Case " << l << ":" << endl;
        int i = 0 ;
        vector<string>v;
        v.push_back("http://www.lightoj.com/");
        while(cin>>s)
        {
            if(s == "VISIT")
            {
                v.resize(++i);
                cin>>s;
                cout << s << endl;
                v.push_back(s);
                continue;
            }
            if(s == "QUIT") break;
            if( (i==0 && s == "BACK" ) || (i+1 == v.size() && s =="FORWARD" )) { printf("Ignored\n"); continue; }
            if(s == "BACK") i--;
            if(s == "FORWARD") i++;
            cout << v[i] << endl;
        }
    }
    return 0;
}
 
