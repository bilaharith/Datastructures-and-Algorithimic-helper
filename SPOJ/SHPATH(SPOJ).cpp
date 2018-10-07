#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef pair<string,int> psi;

const int MAX=100000;
const int INF=0x3f3f3f3f;

vector<pii> g[MAX];
int d[MAX];

int djikstra(int s,int n,int e)
{
    if(s==e) return 0;

    for(int i=0;i<MAX;i++) d[i]=INF;
    priority_queue<pii,vector<pii>,greater<pii> > q;

    int u,c,v,w;
    q.push(pii(0,s));
    d[s]=0;

    while(!q.empty())
    {

    //cout<<s<<" "<<e<<endl;
        u=q.top().second;
        c=q.top().first;
        q.pop();

        if(d[u]<c) continue;

        if(u==e)
            return d[u];

        for(int i=0;i<g[u].size();i++)
        {

            v=g[u][i].first;
            w=g[u][i].second;
            //cout<<"\\\\"<<u<<"  "<<v<<" "<<w<<endl;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push(pii(d[v],v));
            }
        }
    }
    return 0;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {
        int n_c;cin>>n_c;
         for(int i=1;i<=n_c;i++)g[i].clear();
        vector<string > input(n_c);
        for(int i=1;i<=n_c;i++)
        {
            string s;
            cin>>s;
            input[i-1]=s;
            int neigh_c,w,c_i;cin>>neigh_c;
            for(int j=0;j<neigh_c;j++)
            {
                cin>>c_i>>w;
                g[i].push_back(pii(c_i,w));
            }
        }
        int q;
        cin>>q;
        while(q--)
        {
            int i1=0,i2=0;
            string c1,c2;
            cin>>c1>>c2;
            for(int i=0;i<input.size();i++)
                {
                    if(input[i]==c1)
                    {i1=i+1;}
                    if(input[i]==c2)
                    {i2=i+1;}
                    if(i1!=0 && i2!=0)
                        break;
                }
                //cout<<i1<<" "<<i2<<endl;
            int res=djikstra(i1,n_c,i2);
                cout<<res<<"\n";
        }
    }

    return 0;
}
