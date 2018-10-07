#include<bits/stdc++.h>
#include<string>

using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;cin>>n;
    cin.ignore();
    vector<string> data(n);
    for(int i=0;i<n;i++)
        getline(cin,data[i]);

    int t;cin>>t;
    cin.ignore();
    int cursor=n-1;
    vector<string>::iterator it;
    string buffer;
    while(t--)
    {
        it=data.begin()+cursor;
        string test;
        getline(cin,test);
        if(test=="dd" && data.size()!=0)
        {
            data.erase(it);
            if(cursor==data.size() && cursor!=0)
                cursor--;
            else if(cursor==0)
                cursor=0;

        }
        else if(test[0]==':')
        {
            int temp_curs=test[1]-'0'-1;
            if(temp_curs < data.size() && temp_curs>=0)
                cursor=temp_curs;
        }
        else if(test[0]=='i' && test[2]!='0')
        {
            int n_l=test[2]-'0';
            int i;
            for(i=cursor;i<n_l+cursor;i++)
            {

                //cout<<cursor<<" "<<i<<endl;

                string new_string;getline(cin,new_string);
                if(i==cursor && data.size()!=0)
                    data[i]=data[i]+new_string;
                else
                {
                    vector<string>::iterator temp_it=data.begin()+i;
                    data.insert(temp_it,new_string);
                }
            }

            cursor=i-1;
        }
        else if(test=="y")
        {
           buffer=data[cursor];
        }
        else if(test=="p" && !buffer.empty())
        {

            if(data.size()!=0)
                data[cursor]=data[cursor]+buffer;
            else
                data.insert(it,buffer);
        }
        else if(test=="dy" && data.size()!=0)
        {
            buffer=data[cursor];
            data.erase(it);
                if(cursor==data.size() && cursor!=0)
                    cursor--;
                else if(cursor==0)
                    cursor=0;

        }

        //cout<<cursor<<endl;

    }
for(int i=0;i<data.size();i++)
        cout<<data[i]<<endl;

    return 0;
}
