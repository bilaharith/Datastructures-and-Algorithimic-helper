#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--)
    {
        int row,col;cin>>row>>col;
        vector<string> g;
        for(int i=0;i<row;i++)
            {
                string s;cin>>s;
                g.push_back(s);
            }
        int row_2,col_2;cin>>row_2>>col_2;
        vector<string> p;
        for(int i=0;i<row_2;i++)
            {
                string s1;cin>>s1;
                p.push_back(s1);
            }
        int f=0;
        for(int j=0;j<row;j++)
        {   int cnt=0;
            size_t found=g[j].find(p[cnt]);

            if(found!=string::npos)
            {   //cout<<found<<"\n";
                int l;
                l=j+1;
                cnt++;
                while(cnt!=row_2)
                {

                    //cout<<"YES\n";
                    //cout<<p[cnt]<<"\n";
                    size_t found_anoth=g[l].find(p[cnt]);
                    //cout<<found_anoth<<"\n";
                    if(found_anoth==found)
                    {
                        l++;cnt++;
                    }
                    else
                        break;
                }

            if(cnt==row_2){f=1;break;}
            }
        }
        if(f==1) cout<<"YES\n";
        else cout<<"NO\n";


    }

    return 0;
}
