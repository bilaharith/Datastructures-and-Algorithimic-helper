#include<bits/stdc++.h>

using namespace std;

struct node
{
    int r,c,depth;
};

queue <node> q;
int visited[8][8];

void nakanj(int x1,int y1,int x2,int y2)
{
    node temp;
    temp.r=x1;
    temp.c=y1;
    temp.depth=0;

    q.push(temp);

    while(!q.empty())
    {
        node k=q.front();
        q.pop();
        int rr[8]={-1,1,-1,1,-2,-2,2,2};
        int cc[8]={-2,-2,2,2,-1,1,-1,1};
        for(int i=0;i<8;i++)
        {
            int new_r=k.r+rr[i];
            int new_c=k.c+cc[i];
            if(new_r>=8 || new_r<0 || new_c>=8 || new_c<0 || visited[new_r][new_c])
                continue;
            temp.r=new_r;
            temp.c=new_c;
            temp.depth=k.depth+1;
            visited[new_r][new_c]=k.depth+1;
            q.push(temp);
        }
    }

    visited[x1][y1]=0;
    cout<<visited[x2][y2]<<endl;

}

int main()
{
    int t;cin>>t;
    while(t--)
    {
        char a,b;
        int y1,y2;
        cin>>a>>y1>>b>>y2;
        int x1=a-'a';
        int x2=b-'a';

        nakanj(x1,y1-1,x2,y2-1);
    }

    return 0;
}
