#include<bits/stdc++.h>

using namespace std;

int main()
{
int n,c;cin>>n>>c;
int counter=0;
vector<int> size_arr(n);
for(int i=0;i<n;i++)
    cin>>size_arr[i];
sort(size_arr.begin(),size_arr.end());
if(abs(size_arr[0]-size_arr[size_arr.size()-1])<c)
                cout<<0<<endl;

            else
            {
                vector<bool> hashMap(size_arr[size_arr.size()-1],0);
                for(int i=0;i<size_arr[size_arr.size()-1];i++)
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
return 0;
}
