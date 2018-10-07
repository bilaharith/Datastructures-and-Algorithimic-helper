#include<bits/stdc++.h>

using namespace std;
void addEdge(vector<int > adj[],int a,int b)
{
    adj[a].push_back(b);
    adj[b].push_back(a);
}
int bfs(vector<int> adj[],int x,int y,int n)
{
    vector<bool> visited(n+1,false);
    vector<int> distance(n+1,0);
    distance[x]=0;
    queue<int> q;
    q.push(x);
    visited[x]=true;
    while(!q.empty())
    {
        int a=q.front();
        q.pop();
        for(int i=0;i<adj[a].size();i++)
        {
           if(visited[adj[a][i]])
                continue;
            distance[adj[a][i]]=distance[a]+1;
            q.push(adj[a][i]);
            visited[adj[a][i]]=true;
        }
    }
   // cout<<distance[y]<<"||}|}|"<<"\n";
    if(distance[y]!=0)
        return(distance[y]);
    else
        return -1;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    vector<int >adj[n+1];
    for(int i=0;i<n-1;i++)
    {
        int a,b;cin>>a>>b;
        addEdge(adj,a,b);
    }
    vector<int> temp_adj[n+1]=adj;
    int q;cin>>q;
    while(q--)
    {
        string s;
        int x,y;
        cin>>s>>x>>y;
        //cout<<s<<"\n";
        if(s=="q")
        {
            //cout<<"HMM"<<"\n";
            int res=bfs(adj,x,y,n);
            if(res!=-1)
                cout<<res<<"\n";
            else
                cout<<"Impossible\n";
        }
        else if(s=="d")
        {
            int f=0;
            for(int i=0;i<adj[x].size();i++)
            {
                if(adj[x][i]==y)
                {
                     f=1;break;
                }
            }
            if(f==1)
            {
                int pos=distance(adj[x].begin(),find(adj[x].begin(),adj[x].end(),y));
           // cout<<pos<<"\n";
            adj[x].erase(adj[x].begin()+pos);

            //cout<<adj[x].size()<<"\\\\\\"<<adj[x][0]<<" "<<adj[x][1]<<"\n";
            pos=distance(adj[y].begin(),find(adj[y].begin(),adj[y].end(),x));
           // cout<<pos<<"\n";
            adj[y].erase(adj[y].begin()+pos);
            }

        }
        else
        {
            int f=0;
            for(int i=0;i<adj[x].size();i++)
            {
                if(adj[x][i]==y)
                {f=1;break;}
            }
            if(f==0)
            {
                    if(count(temp_adj[x].begin(),temp_adj[x].end(),y)>0)
                            {addEdge(adj,x,y);}
            }
        }
    }


    return 0;
}
