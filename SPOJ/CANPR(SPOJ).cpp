#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b)
{
    if(a==0 || b==0)
        return 0;
    else if(a==b)
        return a;
    else if(a>b)
        return gcd(a-b,b);
    return gcd(a,b-a);
}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,l;cin>>n>>l;

        if(n>l)
        {
            int c=0;
            for(int i=l;i<=n;i+=l)
            {
                for(int j=l;j<=n;j+=l)
                {
                    if(gcd(i,j)==l) c++;
                }
            }
            cout<<c<<endl;
        }

        else if(n==l)
            cout<<1<<endl;
        else
            cout<<0<<endl;
    }
    return 0;
}
