#include<bits/stdc++.h>

using namespace std;

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;cin>>n>>q;
    vector<vector<int> >arr;
    for(int i=1;i<=n;i++)
        {
            vector<int> temp;
            temp.push_back(i);
            arr.push_back(temp);
        }
   /* for(int i=0;i<arr.size();i++)
    {
        if(arr[i].size()==0)
        cout<<"YOOZEROOO\n";
        for(int j=0;j<arr[i].size();j++)
            cout<<arr[i][j];
        cout<<"\n";
    }*/
    for(int i=0;i<q;i++)
    {
        int a;cin>>a;
        if(a==1)
        {
            int b,c;cin>>b>>c;
            vector<int> temp1;
            vector<int> temp2;
            for(int j=0; j>=0 && j<arr.size();j++)
            {   vector<vector<int> >::iterator it;
                for(int k=0;k<arr[j].size();k++)
                {
                    if(j>=0 && j<arr.size() && k>=0 && k<arr[j].size() && arr[j][k]==b)
                    {temp1=arr[j];it=arr.begin()+j;arr.erase(it);j--;}
                    else if(j>=0 && j<arr.size() && k>=0 && k<arr[j].size() && arr[j][k]==c)
                    {temp2=arr[j];it=arr.begin()+j;arr.erase(it);j--;}
                    if(temp1.size()!=0 && temp2.size()!=0) break;
                }
                if(temp1.size()!=0 && temp2.size()!=0) break;
            }
            if(temp1.size()>=temp2.size())
            {
                for(int i=0;i<temp2.size();i++)
                    temp1.push_back(temp2[i]);
                arr.push_back(temp1);
            }
            else
            {
                for(int i=0;i<temp1.size();i++)
                    temp2.push_back(temp1[i]);
                arr.push_back(temp2);
            }

        }
        else
        {
            /*for(int i=0;i<arr.size();i++)
            {
                for(int j=0;j<arr[i].size();j++)
                {
                    cout<<arr[i][j]<<"|||||";
                }
                cout<<"\n";
            }*/
            int c,counter=0;cin>>c;vector<int> size_arr;
            for(int i=0;i<arr.size();i++)
            {
                size_arr.push_back(arr[i].size());
                /*
                for(int j=0;j<arr.size() && i!=j;j++)
                {
                    //cout<<"SIZEOF ARR___"<<arr[i].size()<<" 2nd__"<<arr[j].size()<<"\n";
                    if(abs(arr[i].size()-arr[j].size())>=c)
                        counter++;
                }*/
            }
            sort(size_arr.begin(),size_arr.end());
            if(size_arr.size()<=1)
                cout<<0<<"\n";
            else if(c==0)
            {
                long int s_s=size_arr.size()-1;
                cout<<(s_s*(s_s+1))/2<<"\n";
            }
            else if(abs((int)size_arr[0]-(int)size_arr[size_arr.size()-1])<c)
                cout<<0<<"\n";
            else
            {

                vector<bool> hashMap(size_arr[size_arr.size()-1],0);
                for(int i=0;i<size_arr.size();i++)
                {
                    hashMap[size_arr[i]]=1;
                }
                for(int i=0;i<size_arr.size();i++)
                {
                    //cout<<size_arr[i]<<" "<<hashMap[size_arr[i]]<<endl;
                    int temp=size_arr[i]+c;
                    if(temp<=size_arr[size_arr.size()-1])
                    {
                        //cout<<"---  "<<size_arr[i]<<" "<<temp;
                    for(int j=temp;j<=hashMap.size();j++)
                    {
                        if(hashMap[j]==1)
                            counter+=count(size_arr.begin(),size_arr.end(),j);
                    }
                    }
                }
                cout<<counter<<endl;
            }
           // cout<<counter<<"\n";
        }
    }

    return 0;
}
