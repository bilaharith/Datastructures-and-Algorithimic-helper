#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
const int MAX=1001;
struct Edge{
int src,dest,w;
};

struct graph{

int v;

struct Edge* edge;

};

struct graph* create_graph(int v)
{
    struct graph* g=new graph;
    g->v=v;
    g->edge=new Edge[MAX];
    return g;
};

struct new_subset{
int parent,rank_p;
};

int root_p(struct new_subset subs[],int x)
{
    if(subs[x].parent!=x)
        subs[x].parent=root_p(subs,subs[x].parent);
    return subs[x].parent;
}

void new_union(struct new_subset subs[],int x,int y)
{
    int root_x=root_p(subs,x);
    int root_y=root_p(subs,y);

    if(subs[root_x].rank_p>subs[root_y].rank_p)
        subs[root_y].parent=root_x;
    else if(subs[root_x].rank_p<subs[root_y].rank_p)
        subs[root_x].parent=root_y;
    else
    {
        subs[root_y].parent=root_x;
        subs[root_x].rank_p++;
    }
}

int myComparator(const void* a,const void* b)
{
    struct Edge* a1=(struct Edge*)a;
    struct Edge* a2=(struct Edge*)b;

    return a1->w > a2->w;
}

void kruskal_mst(struct graph* g,int n_e)
{
    int answer=0;
    int v=g->v;
    struct Edge result[v];
    int e=0;
    int i=0;
    qsort(g->edge,n_e,sizeof(g->edge[0]),myComparator);

    struct new_subset *subs=(struct new_subset*) malloc(v*sizeof(struct new_subset));
    for(int i=0;i<v;i++)
    {
        subs[i].parent=i;
        subs[i].rank_p=0;
    }

    while(e<v-1)
    {
        struct Edge next_edge=g->edge[i++];
        int x=root_p(subs,next_edge.src);
        int y=root_p(subs,next_edge.dest);
        if(x!=y)
        {
            result[e++]=next_edge;
            new_union(subs,x,y);
        }
    }
    for(int i=0;i<e;i++)
    {
        answer+=result[i].w;
    }
    cout<<answer<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;
        struct graph* g=create_graph(n);
        int n_e=0;
        for(int i=0;i<n;i++)
        {
            string s;cin>>s;
            int ne;cin>>ne;
            for(int j=0;j<ne;j++)
            {
                int y,wy;cin>>y>>wy;
                g->edge[n_e].src=i;
                g->edge[n_e].dest=y;
                g->edge[n_e].w=wy;
                n_e++;
            }
        }

        kruskal_mst(g,n_e);

    }

    return 0;
}
