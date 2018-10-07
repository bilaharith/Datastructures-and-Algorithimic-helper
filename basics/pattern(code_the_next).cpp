#include<bits/stdc++.h>
using namespace std;

class Graph{

int v;
list<int> *adj;

void dfs_recur(int s,bool visited[]);
public:
    Graph(int v);
    void dfs_intial(int s);
    void addEdge(int a,int b);
};
Graph::Graph(int v)
{
    this->v=v;
    adj=new list<int>[v];
}

void Graph::addEdge(int a,int b)
{
    adj[a].push_back(b);
}

int main()
{
    int n;cin>>n;
        vector<int> cord_x(n);
        vector<int> cord_y(n);

        for(int i=0;i<n;i++)
                cin>>cord_x[i]>>cord_y[i];

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int f=0;
                if(cord_x[i]==cord_x[j])
                {
                    for(int k=0;k<n && k!=i && k!=j;k++)
                    {
                        if(cord_x[k]==cord_x[i] && cord_y[i]>cord_y[j] && cord_y[k]<cord_y[i] && cord_y[k]>cord_y[j])
                            {f=1;break;}
                        else if(cord_x[k]==cord_x[i] && cord_y[j]>cord_y[i] && cord_y[k]<cord_y[j] && cord_y[k]>cord_y[i])
                            {f=1;break;}
                    }
                }
                else if(cord_y[i]==cord_y[j])
                {
                    for(int k=0;k<n && k!=i && k!=j;k++)
                    {
                        if(cord_y[k]==cord_y[i] && cord_x[i]>cord_x[j] && cord_x[k]<cord_x[i] && cord_x[k]>cord_x[j])
                            {f=1;break;}
                        else if(cord_y[k]==cord_y[i] && cord_x[j]>cord_x[i] && cord_x[k]<cord_x[j] && cord_x[k]>cord_x[i])
                            {f=1;break;}
                    }
                }
                else if()
                if(f==0)
                    {g.addEdge(i,j);g.addEdge(j,i);}
            }
        }

}
