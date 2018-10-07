#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 10000;
const int INF = 0x3f3f3f3f;

int d[MAX];
vector<pii> g[MAX];

int djikstra(int s,int n,int x)
{
    if(s==x) return 0;
    for(int i=0;i<MAX;i++) d[i]=INF;
    priority_queue<pii,vector<pii>,greater<pii> > q;

    q.push(pii(0,s));
    int u,c,v,w;
    d[s]=0;

    while(!q.empty())
    {
        c=q.top().first;
        u=q.top().second;
        q.pop();

        if(d[u]<c) continue;

        if(u==x)
            return d[u];

            for(int i=0;i<g[u].size();i++)
            {
                v=g[u][i].first;
                w=g[u][i].second;

                if(d[v] > d[u]+w)
                {
                    d[v]=d[u]+w;
                    q.push(pii(d[v],v));

                }
            }
    }
    return -1;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,e,u,v,w,s,x,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>e;
    for(int i=1;i<=n;i++)g[i].clear();
    for(int i=0;i<e;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(pii(v,w));
        //g[v].push_back(pii(u,w)) ;//for undirected graph;

    }
    cin>>s>>x;
    int res=djikstra(s,n,x);
    if(res==-1)
    {
        cout<<"NO\n";
    }
    else
        cout<<res<<"\n";
    }
    return 0;
}
