#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int z[n];
    int l=0,r=0;

    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            l=r=i;
            while(r<n && s[r-l]==s[r]) r++;
            z[i]=r-l;r--;
        }
        else
        {
            int k=i-l;
            if(z[k]<r-i+1) z[i]=z[k];
            else
            {
                l=i;
                while(r<n && s[r-l]==s[r])r++;
                z[i]=r-l;r--;
            }
        }
    }
   int maxz = 0, res = 0;
    for (int i = 1; i < n; i++) {
    if (z[i] == n-i && maxz >= n-i) { res = n-i; break;}
    maxz = max(maxz, z[i]);
    }
    if(res!=0)
        cout<<s.substr(0,res);
    else
        cout<<"Just a legend";
}
