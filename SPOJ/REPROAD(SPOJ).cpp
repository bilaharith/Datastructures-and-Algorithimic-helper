#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    int max_c=-1;
    while(t--)
    {
        int n,k;cin>>n>>k;
        char r[n];
        for(int i=0;i<n;i++)
            cin>>r[i];

        for(int i=0;i<n;i++)
        {
            int c_z=0,c=0;
            for(int j=i;j<n;j++)
            {
                if(r[j]=='0' && c_z<k)
                    c_z++;
                else if(r[j]=='0' && c_z==k)
                    break;
                c++;
            }
            if(c>max_c)
                max_c=c;
        }
        cout<<max_c<<endl;
    }

    return 0;
}
