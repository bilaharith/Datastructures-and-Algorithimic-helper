#include<bits/stdc++.h>

using namespace std;

bool isbinary(int n)
{
    int m=n;
    while(m!=0)
    {
        if(m%10!=0 || m%10!=1)
            return false;
        m=m/10;
    }
    return true;
}

int mod(string t,int n)
{
    int r=0;
    for(int i=0;i<t.length();i++)
    {
       r=r*10+(t[i]-'0');
       r%=n;
    }
    return r;
}

string min_binary_mul(int n)
{
    list<string> queue;
    string t="1";
    set<int> visit;
    queue.push_back(t);
    while(!queue.empty())
    {
        t=queue.front();
        queue.pop_front();
        int rem=mod(t,n);
        if(rem==0)
            return t;
        else if(visit.find(rem)==visit.end())
        {
            visit.insert(rem);
            queue.push_back(t+"0");
            queue.push_back(t+"1");
        }

    }

}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(!isbinary(n))
            cout<<min_binary_mul(n)<<endl;
        else
            cout<<n<<endl;
    }
    return 0;
}
