#include <bits/stdc++.h>
using namespace std;
 
int isNotVisited(int x, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++) 
        if (path[i] == x) 
            return 0; 
    return 1;
}
 
// utility function for finding paths in graph
// from source to destination
void findpaths(vector<vector<int> >&g, int src, 
                                 int dst, int v,vector<vector<int> >&vv)
{
    // create a queue which stores
    // the paths
    queue<vector<int> > q;
 
    // path vector to store the current path
    vector<int> path;
    path.push_back(src);
    q.push(path);
    while (!q.empty()) {
        path = q.front();
        q.pop();
        int last = path[path.size() - 1];
 
        // if last vertex is the desired destination
        // then print the path
        if (last == dst) 
            vv.push_back(path);        
 
        // traverse to all the nodes connected to 
        // current vertex and push new path to queue
        for (int i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                q.push(newpath);
            }
        }
    }
}

bool comparei(string s1,string s2)
{
    
}

int main()
{

    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    int n,m;cin>>n>>m;
    string s;cin>>s;
    vector<vector<int> > vv;
    vector<vector<int> > g;
    g.resize(n+1);
    map<int,char> city;
    for(int i=1;i<=s.length();i++)
        city[i]=s[i-1];

    for(int i=0;i<m;i++)
    { 
        int a,b;cin>>a>>b;
        g[a].push_back(b);

    }
    int x,y;
    cin>>x>>y;
    
    findpaths(g, x, y, n,vv);

    if(vv.size()==0) cout<<"No way\n";
    else
    {
            vector<string> ss;
        for(int i=0;i<vv.size();i++)
        {
            string s1="";
            for(int j=0;j<vv[i].size();j++)
                {
                    s1+=city[vv[i][j]];
                }
                ss.push_back(s1);
        }
        sort(ss.begin(),ss.end(),comparei);
        cout<<ss[0];

    }

    
 
    return 0;
}
