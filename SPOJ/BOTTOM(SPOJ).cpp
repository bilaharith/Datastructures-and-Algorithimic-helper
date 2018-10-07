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

double tick()
{static clock_t oldt,newt=clock();double diff=1.0*(newt-oldt)/CLOCKS_PER_SEC;oldt=newt;return diff;}
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
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;
}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

vector<int> res;

class Graph{

int V;
list<int> *adj;

void fillorder(int v,bool visited[],stack<int> &Stack);

void dfsUtil(int v,bool visited[],vector<int> &temp);

public:
	void addEdge(int a,int b);
	Graph getTranspose();
	void printSCC(vector<int> edg);

	Graph(int V);

};

Graph:: Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}

void Graph::addEdge(int a,int b)
{
	adj[a].push_back(b);
}

Graph Graph::getTranspose()
{
	Graph gr(V);
	for(int i=0;i<V;i++)
	{
		list<int>::iterator it;
		for(it=adj[i].begin();it!=adj[i].end();it++)
			gr.adj[*it].push_back(i);
	}
	return gr;
}

void Graph::fillorder(int s,bool visited[],stack<int> &Stack)
{
	visited[s]=true;

	list<int>::iterator it;

	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
			fillorder(*it,visited,Stack);
	}

	Stack.push(s);
}

void Graph::printSCC(vector<int> edg)
{

	vector<int> result;
	stack<int> Stack;
	 bool *visited=new bool[V];
	 for(int i=0;i<V;i++)
	 	visited[i]=false;
	 
	 for(int i=0;i<V;i++)
	 	if(visited[i]==false)
	 		fillorder(i,visited,Stack);

	 Graph gr=getTranspose();

	 for(int i=0;i<V;i++)
	 	visited[i]=false;

	 while(Stack.empty()==false)
	 {
	 	int s=Stack.top();
	 	Stack.pop();
	 	int c=0;

	 	if(visited[s]==false)
	 	{
	 		vector<int> temp;
	 		gr.dfsUtil(s,visited,temp);
	 		//cout<<temp.size()<<"\n";
	 		if(temp.size()==1 && temp[0]!=0)
	 		{
	 			list<int>::iterator itj=adj[temp[0]].begin();
	 			if(adj[temp[0]].empty() || *itj==temp[0])
	 				result.push_back(temp[0]);


	 		}
	 		else if(temp.size()>1)
	 		{
	 			int f=0;
	 			for(int i=0;i<temp.size();i++)
	 				{	
	 					for(int j=0;j<edg.size();j+=2)
	 					{
	 						if(edg[j]==temp[i] && count(temp.begin(),temp.end(),edg[j+1])==0){f=1;break;}
	 					}
	 					if(f==1) break;
	 				}
	 				if(f==0)
	 				{
	 					for(int i=0;i<temp.size();i++)
	 						result.push_back(temp[i]);
	 				}
	 		}

	 		
	 	}

	 }
	 sort(result.begin(),result.end());
	 for(int i=0;i<result.size();i++)
	 {
	 	cout<<result[i]<<" ";
	 }cout<<"\n";
}

void Graph::dfsUtil(int s,bool visited[],vector<int> &temp)
{
	visited[s]=true;
	temp.push_back(s);
	list<int>::iterator it;
	for(it=adj[s].begin();it!=adj[s].end();it++)
	{
		if(!visited[*it])
			dfsUtil(*it,visited,temp);
	}

}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#endif

		int v;
		while(cin>>v && v!=0)
		{

			int e;cin>>e;
			Graph g(v+1);
			vector<int> edg;
			for(int i=0;i<2*e;i++)
			{
				int x;cin>>x;
				edg.push_back(x);
			}
			for(int i=0;i<edg.size();i+=2)
				{
					int a=edg[i];int b=edg[i+1];
					g.addEdge(a,b);
				}
			g.printSCC(edg);
		}

    //cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
