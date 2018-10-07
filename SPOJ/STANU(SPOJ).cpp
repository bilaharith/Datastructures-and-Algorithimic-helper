#include<iostream>
#include<vector>

using namespace std;

typedef pair<int,int> pii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    for(int j=1;j<=t;j++)
    {
        int n,q;cin>>n>>q;
        vector<int> inp;
        for(int i=0;i<n;i++)
        {
            int a;cin>>a;
            inp.push_back(a);
        }
        cout<<"Case "<<j<<":\n";
        while(q--)
        {

        int t1,t2;cin>>t1>>t2;
        long long int ans=0;
        for(int i=t1-1;i<=t2-1;i++)
            ans+=inp[i];
        cout<<ans<<"\n";
        }
    }
    return 0;
}
