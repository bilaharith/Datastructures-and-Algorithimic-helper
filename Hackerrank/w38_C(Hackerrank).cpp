#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 100001;
const int INF = 0x3f3f3f3f;

int d[MAX];   //the distance of each node from the starting node
vector<pii> g[MAX]; // the graph could be as large as 100001 due to constraint

int djikstra(int s,int n,int x,int k)
{
    
    if(s==x) return 0; //if starting and ending node is same

    for(int i=0;i<MAX;i++) d[i]=INF;  //intializing the distances

    int temp=0;           //this value acts as the remainder of green light(sometimes while travelling we hit the kth value so for some time it will be green and after that some time to make it kth value)

    priority_queue<pii,vector<pii>,greater<pii> > q; //priority queue for applying djikstra

    q.push(pii(0,s));  //pushed first
    int u,c,v,w;   //u poped node; c its cost; v node adjacent to poped node; w weight of that node
    d[s]=0;      //starting vertex has 0 distance
    while(!q.empty())
    {
        c=q.top().first;
        u=q.top().second;
        q.pop();  //popped

        if(d[u]<c) continue;  //we need shortest distance


        
        if(u==x)
            {return d[u];} //return dist when found the last node(we pass x as last node always)


            for(int i=0;i<g[u].size();i++)  //g[u] is the graph at node u
            {

                v=g[u][i].first;  //adjacent nodes
                w=g[u][i].second; //their weights

                /*if(d[u]%k==0) temp=0; //This is where I start getting skeptical of my logic. but I update temp val because We could go off route on another edge but that edge might not be in the route.So i update it.
                else temp=k-(d[u]%k);
               
                if(v!=x)        // We don't add weight when we reach last node since we already reached
                    {

                        if(w<=k)  //divided this in two parts < k val and > k val
                        {
                            int we=w;  
                            if(temp!=0)  //check if temp is empty(meaning we hit green light for k seconds)
                            {   

                                if(temp<=we)
                                    {   we-=temp;
                                        w+=k-(we%k);  //add remainder of time(we wait at this node)
                                        temp=0;
                                    }
                                else
                                {
                                    temp-=w;  //else no time added (we don't wait)
                                }
                            }
                            else
                            {
                                if(w%k==0)
                                {
                                    w+=k;  //we wait
                                }
                                else
                                {
                                    temp=k-(we%k);  //don't wait
                                }
                            }

                        }
                        else //if(w>k)
                        {
                            int wei=w;
                            wei-=temp;  //firstly clear the temp val

                                if((wei/k)%2!=0)
                                {
                                    w+=k-(wei%k); //if the weight is odd multiple of k then we add weight(this is right??)
                                    temp=0; //get temp back

                                }
                                else
                                {
                                    if(wei%k==0) temp=0; 
                                    else temp=k-(wei%k);//no waiting
                                } 
                        }

                    }*/


                

                if(d[v] > d[u]+w)
                    {
                        //cout<<v<<" "<<w<<" "<<temp<<"\n";
                        d[v]=d[u]+w;
                        q.push(pii(d[v],v));
                        if(v!=x && (d[v]/k)%2==1)
                {
                    d[v]+=k-(d[v]%k);
                }
                    }
            }
    }

    return -1;  //not gonna happen , but compiler sees eof

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k,m,u,v,w;cin>>n>>k>>m;

    for(int i=1;i<=n;i++)g[i].clear();

    for(int i=0;i<m;i++)
    {
        cin>>u>>v>>w;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
        //for undirected graph;

    }
    cout<<djikstra(1,n,n,k);
    /*if(res%k!=0) res+=(res/k)*k;
    else {res+=(res/k-1)*k;}
    cout<<res<<"\n";
    */
    return 0;
}
