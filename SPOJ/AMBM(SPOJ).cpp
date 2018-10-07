#include<bits/stdc++.h>

using namespace std;

vector<int> result_back;

void combinationUtil(vector<int> arr, int n, int r,
                     int index, vector<int> data, int i,int k,vector<int> result);

vector<int> printCombination(vector<int> arr, int n, int r,int k,vector<int> result)
{
    vector<int> data(r);

      combinationUtil(arr, n, r, 0, data, 0,k,result);
      return result;
}
void combinationUtil(vector<int> arr, int n, int r, int index,
                     vector<int> data, int i,int k,vector<int> result)
{
    int sum=0;
    if (index == r) {
        for (int j = 0; j < r; j++)
            {sum+=data[j];}
            cout<<sum<<endl;
            if(sum==k)
            {
                sort(data.begin(),data.end());
                for(int i=0;i<r;i++)
                    cout<<data[i]<<" ";
                cout<<endl;
                result=data;
                cout<<"RESULT "<<result[0]<<" "<<endl;
                return ;
            }
        return ;
    }

    if (i >= n)
        return ;

    data[index] = arr[i];
    combinationUtil(arr, n, r, index + 1, data, i + 1,k,result);

    combinationUtil(arr, n, r, index, data, i + 1,k,result);
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;cin>>k>>n;
        vector<int> a(n);
        vector<int> b(n);
        vector<int> result;
        for(int i=0;i<n;i++)
            {cin>>a[i];
            if(i==0)
                b[0]=a[0];
            else
                {
                    b[i]=a[i]+2*b[i-1];
                }
            }
        for(int i=1;i<=b.size();i++)
            {result=printCombination(b,b.size(),i,k,result);
            if(result.size()>0) break;}
       if(result.size()!=0)
            for(int i=0;i<result.size();i++)
                cout<<result[i]<<" ";
        else
            cout<<-1;
        cout<<endl;
    }
    return 0;
}
