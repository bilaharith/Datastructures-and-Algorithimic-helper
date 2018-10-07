#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the membersInTheLargestGroups function below.
void membersInTheLargestGroups(int n, int m, int a_1, int b_1, int f, int s, int t) {
    // Print the names of the students in all largest groups or determine if there are no valid groups.

    vector<string> inp_s(n);
    vector<int> inp_i(n);
    vector<vector<string> > result;
    vector<string> first_grp(m);
    vector<string> second_grp(m);
    for(int i=0;i<n;i++)
    {
        cin>>inp_s[i]>>inp_i[i];
    }
    for(int i=0;i<m;i++)
    {
        cin>>first_grp[i]>>second_grp[i];
        vector<string> temp;
        if(result.size()==0)
        {temp.push_back(first_grp[i]);temp.push_back(second_grp[i]);}
        else
        {
            int a=0,b=0;
            for(int j=0;j<result.size();j++)
            {
                a+=count(result[j].begin(),result[j].end(),first_grp[i]);
                b+=count(result[j].begin(),result[j].end(),second_grp[i]);



            }
             //cout<<"COUNT OF A AND B  "<<a<<" "<<b<<"\n";
                if(a>0 && b==0)
                {

                for(int j=0;j<result.size();j++)
                {
                    if(count(result[j].begin(),result[j].end(),first_grp[i])>0)
                    {

                            if(result[j].size()<b_1)
                    {
                        vector<vector<string> >::iterator it;
                        int pos=distance(inp_s.begin(),find(inp_s.begin(),inp_s.end(),first_grp[i]));
                        int count_class=1;
                        for(int k=0;k<result[j].size();k++)
                        {
                            int temp_pos=distance(inp_s.begin(),find(inp_s.begin(),inp_s.end(),result[j][k]));
                            if(inp_i[temp_pos]==inp_i[pos])
                                count_class++;
                        }
                        if(inp_i[pos]==1 && count_class<=f)
                        {temp=result[j];temp.push_back(second_grp[i]);it=result.begin()+j;result.erase(it);}
                        else if(inp_i[pos]==2 && count_class<=s)
                        {temp=result[j];temp.push_back(second_grp[i]);it=result.begin()+j;result.erase(it);}
                        else if(inp_i[pos]==3 && count_class<=t)
                        {temp=result[j];temp.push_back(second_grp[i]);it=result.begin()+j;result.erase(it);}
                    }

                    break;
                    }

                }
                }
                else if(b>0 && a==0)
                {
                   for(int j=0;j<result.size();j++)
                    {
                           // cout<<"COUNT OF B IN INIT____"<<count(result[j].begin(),result[j].end(),second_grp[i])<<"\n";
                        if(count(result[j].begin(),result[j].end(),second_grp[i])>0)
                        {
                            //cout<<"SIZE OF RESULT ___ AND B"<<result[j].size()<<" "<<b_1<<"\n";
                            if(result[j].size()<b_1)
                    {
                       // cout<<"YUP_WENT HERE|||\n";
                        vector<vector<string> >::iterator it;
                        int pos=distance(inp_s.begin(),find(inp_s.begin(),inp_s.end(),second_grp[i]));
                        int count_class=1;
                        for(int k=0;k<result[j].size();k++)
                        {
                            int temp_pos=distance(inp_s.begin(),find(inp_s.begin(),inp_s.end(),result[j][k]));
                            if(inp_i[temp_pos]==inp_i[pos])
                                count_class++;
                        }
                        if(inp_i[pos]==1 && count_class<=f)
                        {temp=result[j];temp.push_back(first_grp[i]);it=result.begin()+j;result.erase(it);}
                        else if(inp_i[pos]==2 && count_class<=s)
                        {temp=result[j];temp.push_back(first_grp[i]);it=result.begin()+j;result.erase(it);}
                        else if(inp_i[pos]==3 && count_class<=t)
                        {temp=result[j];temp.push_back(first_grp[i]);it=result.begin()+j;result.erase(it);}
                    }
                    break;
                        }
                    }
                }
                else if(a>0 && b>0)
                {
                    int x=-1,y=-1;
                    for(int j=0;j<result.size();j++)
                    {
                        if(count(result[j].begin(),result[j].end(),first_grp[i])>0)
                        {
                            x=j;
                        }
                        if(count(result[j].begin(),result[j].end(),second_grp[i])>0)
                        {
                            y=j;
                        }
                        if(x!=-1 && y!=-1)
                            break;
                    }
                    if(x!=y)
                    {
                        if(result[x].size()+result[y].size()<=b_1)
                        {
                            int c_f_1=0,c_s_1=0,c_t_1=0,c_f_2=0,c_s_2=0,c_t_2=0;
                            for(int k=0;k<result[x].size();k++)
                            {
                                int temp_pos=distance(inp_s.begin(),find(inp_s.begin(),inp_s.end(),result[x][k]));
                                if(inp_i[temp_pos]==1)
                                    c_f_1++;
                                else if(inp_i[temp_pos]==2)
                                    c_s_1++;
                                else
                                    c_t_1++;
                            }
                            for(int k=0;k<result[y].size();k++)
                            {
                                int temp_pos=distance(inp_s.begin(),find(inp_s.begin(),inp_s.end(),result[y][k]));
                                if(inp_i[temp_pos]==1)
                                    c_f_2++;
                                else if(inp_i[temp_pos]==2)
                                    c_s_2++;
                                else
                                    c_t_2++;
                            }

                            if(c_f_1+c_f_2<=f && c_s_1+c_s_2<=s && c_t_1+c_t_2<=t)
                            {
                                temp=result[x];
                                for(int k=0;k<result[y].size();k++)
                                    temp.push_back(result[y][k]);
                                vector<vector<string> >::iterator it=result.begin()+x;
                                result.erase(it);
                                if(x<y)
                                    {it=result.begin()+y-1;
                                    result.erase(it);}
                                else
                                {
                                    it=result.begin()+y;
                                    result.erase(it);
                                }

                            }
                        }
                    }
                }
                else
                {
                   // cout<<"THIS WORKS|||\n";
                    temp.push_back(first_grp[i]);
                    temp.push_back(second_grp[i]);
                }

            }

      /*  for(int x=0;x<temp.size();x++)
            cout<<temp[x]<<" ";
        cout<<"\n";*/
      //  cout<<"SIZE OF RESULT "<<result.size()<<"\n";
        if(temp.size()!=0)
            result.push_back(temp);

      //  cout<<"////////\n";


    }
    /*
for(int i=0;i<result.size();i++)
        {

        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<"\n";
        }*/
    int max_size=-1;
    for(int i=0;i<result.size();i++)
    {
        int size_temp=result[i].size();
        //cout<<size_temp<<"\n";
        if(size_temp<a_1)
        {
            //cout<<"NUUH "<<"\n";
            vector<vector<string> >::iterator it=result.begin()+i;
            result.erase(it);
            i--;
        }
        if(size_temp>max_size)
            {//cout<<"YEEA BOIII "<<"\n";
                max_size=size_temp;}
    }
    //cout<<"MMMAAACXX SIZEE "<<max_size<<"\n";
    if(result.size()==0)
        cout<<"no groups\n";

    else
    {
        vector<string> final_result;
        for(int i=0;i<result.size();i++)
        {
            int size_temp=result[i].size();
            if(size_temp==max_size)
            for(int j=0;j<result[i].size();j++)
            {
                final_result.push_back(result[i][j]);
            }
        }
        sort(final_result.begin(),final_result.end());
        for(int i=0;i<final_result.size();i++)
            cout<<final_result[i]<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int n,m,a,b,f,s,t;cin>>n>>m>>a>>b>>f>>s>>t;

    membersInTheLargestGroups(n, m, a, b, f, s, t);

    return 0;
}
