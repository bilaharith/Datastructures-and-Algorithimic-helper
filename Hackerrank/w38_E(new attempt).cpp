#include <bits/stdc++.h>
using namespace std;
int cnt=0,val=0;
class Graph
{
    int V;    
    list<int> *adj; 
 
    void printAllPathsUtil(int , int , bool [], int [], int &);
 
public:
    Graph(int V);   
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); 
}
 
void Graph::printAllPaths(int s, int d)
{
    bool *visited = new bool[V];
 
    int *path = new int[V];
    int path_index = 0; 
 
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    printAllPathsUtil(s, d, visited, path, path_index);
}
 
void Graph::printAllPathsUtil(int u, int d, bool visited[],
                              int path[], int &path_index)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    if (u == d)
    {
    	cnt++;val=path_index;
    }
    else 
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}


int main() {

		int n,m,k,t;cin>>n>>m>>k>>t;

		Graph g(n);

		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			g.addEdge(u,v);

		}
        g.printAllPaths(0,n-1);
		int ans=(int)((1.0)*k/cnt +0.5)-1-(int)((1.0)*t/(val-1) +0.5);
		cout<<ans<<"\n";

	// cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
