#include<bits/stdc++.h>

using namespace std;

class Graph{

    int v;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int a,int b);
    void bfs(int s);//s is the starting vertex.
};

Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}
void Graph::addEdge(int a,int b)
{
    adj[a].push_back(b); //adding b to a's list
}
void Graph::bfs(int s)
{
    vector<bool> visited(v,false);
    list<int> queue;

    visited[s]=true;
    queue.push_back(s);

    list<int>::iterator i;

    while(!queue.empty())
    {
        s=queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for(i=adj[s].begin();i!=adj[s].end();i++)
        {
            if(!visited[*i])
            {
                queue.push_back(*i);
                visited[*i]=true;
            }
        }

    }

}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.bfs(2);

    return 0;
}
