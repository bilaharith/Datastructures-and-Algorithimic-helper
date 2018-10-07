#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL; 
typedef long double LD;

const int MAX	= 1e5 + 5;
const int LIM	= 3e5 + 5;
const int MOD	= 1e9 + 7;
const LD  EPS	= 1e-10;
const double PI = acos(-1.0);

#define fastio			ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define Assert(x)		{if(!(x)){cerr<<"Assertion failed at line "<<__LINE__<<": "<<#x<<" = "<<(x)<<"\n";exit(1);}}
#define inchar			getchar//_unlocked
#define outchar(x)		putchar(x)//_unlocked(x)

double tick(){static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
template<typename T> void inpos(T &x){x=0;register T c=inchar();while(((c<48)||(c>57))&&(c!='-'))c=inchar();bool neg=0;\
if(c=='-')neg=1;for(;c<48||c>57;c=inchar());for(;c>47&&c<58;c=inchar())x=(x<<3)+(x<<1)+(c&15);if(neg)x=-x;}
template<typename T> void outpos(T n){if(n<0){outchar('-');n*=-1;}char snum[65];int i=0;do{snum[i++]=n%10+'0';n/=10;}\
while(n);i=i-1;while(i>=0)outchar(snum[i--]);outchar('\n');}
inline void instr(char *str){register char c=0;register int i=0;while(c<33)c=inchar();while(c!='\n'&&c!=' '&&c!=EOF){\
str[i]=c;c=inchar();++i;}str[i]='\0';}
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int add(int a, int b, int c){int res=a+b;return(res>=c?res-c:res);}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mul(int a, int b, int c){LL res=(LL)a*b;return(res>=c?res%c:res);}
LL mulmod(LL a,LL b, LL m){LL q = (LL)(((LD)a*(LD)b)/(LD)m);LL r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

# define INF 0x3f3f3f3f
typedef pair<int, int> iPair;
 
class Graph
{
    int V;    // No. of vertices
 
    // In a weighted graph, we need to store vertex
    // and weight pair for every edge
    list< pair<int, int> > *adj;
 
public:
    Graph(int V);  // Constructor
 
    // function to add an edge to graph
    void addEdge(int u, int v, int w);
 	void removeEdge(int ed);
 	void new_size(int n);
    // prints shortest path from s
    int shortestPath(int s,int op);
};
 
// Allocates memory for adjacency list
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}
void Graph::new_size(int n)
{
	this->V=n;
	adj->resize(n);
}
 
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
}

void Graph::removeEdge(int ed)
{	int f=0;
	 list< pair<int, int> >::iterator i;
        
        
	for(int j=1;j<=V;j++)
	{
		for (i = adj[j].begin(); i != adj[j].end(); ++i)
        {
			if((*i).first==ed)
				{(*i).first=-1;return;}
		}
	}
}
 
// Prints shortest paths from src to all other vertices
int Graph::shortestPath(int src,int op)
{
    // Create a priority queue to store vertices that
    // are being preprocessed. This is weird syntax in C++.
    // Refer below link for details of this syntax
    // http://geeksquiz.com/implement-min-heap-using-stl/
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
 
    // Create a vector for distances and initialize all
    // distances as infinite (INF)
    vector<int> dist(V, INF);
 
    // Insert source itself in priority queue and initialize
    // its distance as 0.
    pq.push(make_pair(0, src));
    dist[src] = 0;
 
    /* Looping till priority queue becomes empty (or all
      distances are not finalized) */
    while (!pq.empty())
    {
        // The first vertex in pair is the minimum distance
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted distance (distance must be first item
        // in pair)
        int u = pq.top().second;
        pq.pop();
 
        // 'i' is used to get all adjacent vertices of a vertex
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = (*i).first;
            int weight = (*i).second;
 
            //  If there is shorted path to v through u.
            if (v!=-1 && dist[v] > dist[u] + weight)
            {
                // Updating distance of v
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    int max_pos=-1,max_val=-1;
    for(int i=1;i<=V;i++)
    {
    	if(dist[i]!=INF && dist[i]>max_val){max_val=dist[i];max_pos=i;}
    }
    if(op==1) return max_pos;
    else return max_val;
 	
}


int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#endif

	int n;
    cin>>n;           //no of vertices
    Graph g(n);
    for(int i=1;i<=n;i++)
    {  
        int w;  //since we know the edge is from i-> i+1 only weight is required
        cin>>w;
        if(i<n)
            g.addEdge(i,i+1,w);
        else
            g.addEdge(n,1,w); //if i==n then we take n->1 edge
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
            cout<<"YES";
            int far=g.shortestPath(x,1);
            cout<<far<<"\n";
            n++;
            g.addEdge(far,n,we);

        }
        else if(a==2)
        {
            cin>>x>>we;  //just make a new conn. from x-> n+1 with weight=we
            n++;
            g.new_size(n);
            g.addEdge(x,n,we);

        }
        else if(a==3)
        {
            cin>>x;  // THIS IS THE SKEPTICAL PART I THINK ( DELETION OF THE FARTHEST NODE)
            int farr=g.shortestPath(x,1);
            g.removeEdge(farr);
            
        }
        else if(a==4)  //PRINT ONLY IN THIS OPERATION
        {

            cin>>x;   //take x

            cout<<g.shortestPath(x,0)<<"\n";
        }
    }
    return 0;

	// cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
