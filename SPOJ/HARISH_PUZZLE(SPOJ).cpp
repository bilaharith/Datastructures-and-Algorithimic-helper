#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;cin>>t;
    while(t--)
    {
        char t[8][8];
    vector<int> col_stor;
    int r_f,c_f=0;
    for(int i=0;i<8;i++)
        for(int j=0;j<8;j++)
            cin>>t[i][j];

    for(int i=0;i<8;i++)
    {
        r_f=0;
        vector<int>::iterator it;
        for(int j=0;j<8;j++)
        {
            if(t[i][j]=='R' )
            {
                it=find(col_stor.begin(),col_stor.end(),j);
                 if(it!=col_stor.end())
                 {
                     c_f=1;break;
                 }
            }
            if(t[i][j]=='R' && r_f==0)
                {r_f=1;col_stor.push_back(j);}
            else if(t[i][j]=='R' && r_f==1)
            {c_f=1;break;}
        }
        if(c_f==1) break;

    }
        if(c_f==1)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }

    return 0;
}
