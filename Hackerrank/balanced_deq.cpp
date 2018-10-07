#include<bits/stdc++.h>

using namespace std;

int main()
{
int n;
cin>>n;
vector<int> balanced_pos;
string s;cin>>s;
int f=0;
int c_m=0;
for(int i=0;i<s.length();i++)
{
    if(s[i]=='(')
        f=1;
    else if(s[i]==')' && f==1)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(s[j]=='(')
            {
                s.erase(i,1);
                s.erase(j,1);
                if(j>0 || j<n-1)
                    c_m++;
                balanced_pos.push_back(j);
                i-=2;
                break;
            }
        }
    }
}
int c_a=0,c_b=0,result=0;
vector<int> copy_seq;
if(balanced_pos.size()==0)
    cout<<1<<"\n";
else if(s.length()==2)
    cout<<1<<"\n";
else if(s.length()!=0)
    {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                {copy_seq.push_back(1);c_a++;}
            else
                {copy_seq.push_back(2);c_b++;}
        }
        if(c_a==s.length())
        {
            for(int i=0;i<balanced_pos.size();i++)
            {
                copy_seq.insert(copy_seq.begin()+balanced_pos[i],-1);
            }
            int new_flag=0,new_count=0;
            for(int i=0;i<copy_seq.size();i++)
            {
                if(copy_seq[i]==1 && new_count<=c_a/2)
                    new_count++;
                else if(new_count>c_a/2)
                {if(copy_seq[i]==1 && new_flag==0)
                    {result++;new_flag=1;}
                else if(copy_seq[i]==-1)
                    {new_flag=0;}
                }
            }
            cout<<result<<"\n";
        }
        else if(c_b==s.length())
        {
            for(int i=0;i<balanced_pos.size();i++)
            {
                copy_seq.insert(copy_seq.begin()+balanced_pos[i],-1);
            }
             int new_flag=0,new_count=1;
            for(int i=0;i<copy_seq.size();i++)
            {
                if(new_count>c_b/2)
                    break;
                if(copy_seq[i]==2)
                {
                    if(new_flag==0)
                        {result++;new_flag=1;}
                    new_count++;
                }
                else if(copy_seq[i]==-1)
                    new_flag=0;
            }
            cout<<result<<"\n";

        }
        else
        {
            for(int i=0;i<balanced_pos.size();i++)
            {
                copy_seq.insert(copy_seq.begin()+balanced_pos[i],-1);
            }
             int new_flag_1=0,new_count_1=0,new_flag_2=0,new_count_2=1;
             for(int i=0;i<copy_seq.size();i++)
             {
                 if(new_count_2<=c_b/2)
                 {
                    // cout<<"COUNTING 2ss___"<<new_count_2<<"\n";
                     if(copy_seq[i]==2)
                     {
                         if(new_flag_2==0)
                            {result++;new_flag_2=1;}
                         new_count_2++;
                     }
                     else if(copy_seq[i]==-1)
                        new_flag_2=0;
                 }
                 if(copy_seq[i]==1 && new_count_1<=c_a/2)
                    new_count_1++;
                 else if(new_count_1>c_a/2)
                 {
                     if(copy_seq[i]==1 && new_flag_1==0)
                     {result++;new_flag_1=1;}
                     else if(copy_seq[i]==-1)
                        new_flag_1=0;
                 }
             }
             cout<<result<<"\n";
        }
    }
    else
        cout<<0<<"\n";


return 0;
}
