#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

struct edge{

int src,dest,w;
};
struct graph{

int v,e;

struct edge *E;

};
struct graph* createGraph(int v,int e)
{
    struct graph* g=new graph;
    g->v=v;
    g->e=e;
    g->E=new edge[e];
    return g;
};
struct subset{

int parent,rank_p;
};
int find_p(struct subset subs[],int a)
{
    if(subs[a].parent!=a)
        subs[a].parent=find_p(subs,subs[a].parent);
    return subs[a].parent;
}
void union_xy(struct subset subs[],int x,int y)
{
    int root_x=find_p(subs,x);
    int root_y=find_p(subs,y);

    if(subs[root_x].rank_p>subs[root_y].rank_p)
    {
        subs[root_y].parent=root_x;
    }
    else if(subs[root_x].rank_p<subs[root_y].rank_p)
    {
        subs[root_x].parent=root_y;
    }
    else
    {
        subs[root_y].parent=root_x;
        subs[root_x].rank_p++;
    }
}

int myComp(const void* a,const void* b)
{
    struct edge* a1=(struct edge*)a;
    struct edge* b1=(struct edge*)b;

    return a1->w > b1->w;
}

void kruskal(struct graph* g)
{
    int v=g->v;
    struct edge result[v];
    int e=0;
    int i=0;

    qsort(g->E,g->e,sizeof(g->E[0]),myComp);
    struct subset *subs=(struct subset*) malloc(v*sizeof(struct subset));
    for(int i=0;i<v;i++)
    {
        subs[i].parent=i;
        subs[i].rank_p=0;
    }
    while(e<v-1)
    {
        struct edge next_edge=g->E[i++];
        int x=find_p(subs,next_edge.src);
        int y=find_p(subs,next_edge.dest);

        if(x!=y)
        {
            result[e++]=next_edge;
            union_xy(subs,x,y);
        }
    }
     printf("Following are the edges in the constructed MST\n");
    for (i = 0; i < e; ++i)
        printf("%d -- %d == %d\n", result[i].src, result[i].dest,
                                                 result[i].w);
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* Let us create following weighted graph
             10
        0--------1
        |  \     |
       6|   5\   |15
        |      \ |
        2--------3
            4       */
        int v=4;
        int e=5;

        struct graph* g=createGraph(v,e);

        // add edge 0-1
    g->E[0].src = 0;
    g->E[0].dest = 1;
    g->E[0].w = 10;

    // add edge 0-2
    g->E[1].src = 0;
    g->E[1].dest = 2;
    g->E[1].w = 6;

    // add edge 0-3
    g->E[2].src = 0;
    g->E[2].dest = 3;
    g->E[2].w = 5;

    // add edge 1-3
    g->E[3].src = 1;
    g->E[3].dest = 3;
    g->E[3].w = 15;

    // add edge 2-3
    g->E[4].src = 2;
    g->E[4].dest = 3;
    g->E[4].w = 4;

    kruskal(g);


    return 0;
}
