#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 200001;  //since n can be atmost 10^5 and m can be too so we can add 10^5 more vertices
const int INF = 0x3f3f3f3f;

long int d[MAX];  //distance storage
vector<pii> g[MAX];  //this is the graph

int djikstra(int s,int n)     //FUNCTION FOR FARTHEST NODE
{
    for(int i=0;i<MAX;i++) d[i]=INF;  //intializing dist
    priority_queue<pii,vector<pii>,greater<pii> > q;  //priority queue for djikstra

    q.push(pii(0,s));
    int u,c,v,w;  //u is the node we are at; c is its cost; v is the node adjacent to u; and w is its weight
    d[s]=0;   //itself is zero dist

    while(!q.empty())
    {
        c=q.top().first;
        u=q.top().second;
        q.pop();   //poped

        if(d[u]<c) continue;  //continue if already less path

            for(int i=0;i<g[u].size();i++)  //adjacent to u nodes
            {
                v=g[u][i].first;   //node
                w=g[u][i].second;  //weight

                if(d[v] > d[u]+w)
                {
                    d[v]=d[u]+w;
                    q.push(pii(d[v],v));

                }
            }
    }
    int max_elem=-1,max_val=-1;  //max elem is the farthest node; max_val is its value
    int i;
    for(i=1;i<=n;i++)
    {
        if(d[i]>max_val && i!=s && d[i]!=INF) {max_elem=i;max_val=d[i];}  //d[i]!=INF coz when I erase a node, it might still check its val as INF and can give bad result
    }
    return max_elem;  //farthest node

}
long int djikstra_path(int s,int n,int x)  //FUNCTION FOR FARHEST NODE's VALUE
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

        if(u==x) return d[u];  //just return asap you find the farthest node to s(starting node)
       

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
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
   // g.resize(n);         //no of vertices
    for(int i=1;i<=n;i++)g[i].clear(); //clearing
    for(int i=1;i<=n;i++)
    {  
        int w;  //since we know the edge is from i-> i+1 only weight is required
        cin>>w;
        if(i<n)
            g[i].push_back(pii(i+1,w)); 
        else
            g[n].push_back(pii(1,w)); //if i==n then we take n->1 edge
        //g[v].push_back(pii(u,w)) ;//for undirected graph;
    }

    int m;cin>>m; //no of queries
    while(m--)
    {
        int a;cin>>a;  //first digit decides what operation
        int x,we;
        if(a==1)
        {
            cin>>x>>we;  //x is the starting node and we is the weight to be added to the new conn. farthest-> n+1 with weight=we
            
            int far=djikstra(x,n);//find the farthest from x
            n++;
           // g.resize(n);
            g[far].push_back(pii(n,we));  // make a new conn.

        }
        else if(a==2)
        {
            cin>>x>>we;  //just make a new conn. from x-> n+1 with weight=we
            n++;
            //g.resize(n);
            g[x].push_back(pii(n,we));
        }
        else if(a==3)
        {
            cin>>x;  // THIS IS THE SKEPTICAL PART I THINK ( DELETION OF THE FARTHEST NODE)

            int farth=djikstra(x,n); //find farthest node
            int f=0;
            for(int i=1;i<=n;i++)
            {
                for(int j=0;j<g[i].size();j++)
                {
                    if(g[i][j].first==farth)
                    {
                        g[i].erase(g[i].begin()+j);  //delete it's connection with the node previous to it[THIS MIGHT BE REASON FOR SEG FAULT??]
                        f=1;break;
                    }
                }
                if(f==1) break;
            }


        }
        else if(a==4)  //PRINT ONLY IN THIS OPERATION
        {

            cin>>x;   //take x
            int farr=djikstra(x,n); //find the farthest from x

            cout<<djikstra_path(x,n,farr)<<"\n"; //print value of the farthest 

        }
    }
    return 0;
}
