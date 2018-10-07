#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
    int q;cin>>q;
    cin.ignore();
    while(q--)
    {
        string a,b;
        getline(cin,a);getline(cin,b);
        //cout<<a<<" "<<b<<endl;
        if(a==" ")
            cout<<0<<endl;
        else if(b==" ")
            cout<<a.length()<<endl;
        else
        {
            int a_length=a.length();
            int c=0;
            for(int i=0,j=0;i<a.length();i++)
            {
                //cout<<a[i]<<" "<<b[j]<<" "<<c<<endl;
                if(a.length()<b.length())
                    {c=a_length;break;}
                else if(a[i]==b[j])
                {
                    if(j==b.length()-1) j=0;
                    else j++;
                }
                else
                {
                    //cout<<"arrived here"<<endl;
                    c++;a.erase(i,1);i--;
                }
                //cout<<a<<endl;
            }
            if(a.length()>b.length() && a.length()%b.length()!=0)
            {
                c+=a.length()%b.length();
            }
            cout<<c<<endl;
        }
    }

    return 0;
}
