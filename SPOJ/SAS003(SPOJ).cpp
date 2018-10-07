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

bool isPrime(int n)
{
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    vector<int> a;
    for(int i=0;i<n;i++)
    {int ob;cin>>ob;a.push_back(ob);}
    int x;cin>>x;
    vector<int> b;
    for(int i=0;i<x;i++)
    {int ob1;cin>>ob1;b.push_back(ob1);}
    vector<int> p;
        for(int i=0;i<x;i++)
        {
            if(b[i]<0)
                {for(int j=abs(b[i]);j<n;j++)
                    p.push_back(a[j]);}
            else
                {for(int j=0;j<=b[i];j++)
                    p.push_back(a[j]);}
        }
    int q;cin>>q;
    while(q--)
    {
        int k;cin>>k;
        int cnt=0;
        for(int i=0;i<p.size();i++)
        {   if(isPrime(p[i]))
                {
                    cnt++;
                    if(cnt==k) {cout<<p[i]<<"\n";break;}
                }
        }
       if(cnt<k)
            cout<<-1<<"\n";


    }
    return 0;
}
