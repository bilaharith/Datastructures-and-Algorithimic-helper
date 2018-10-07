#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL; 
typedef long double LD;

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

typedef pair<int,int> pii;

const int MAX = 2001;
const int INF = 0x3f3f3f3f;
//https://ideone.com/ndsR45
int d[MAX];
vector<pii> g[MAX];
int val=0;
void printPath(int parent[], int j,int temp)
{
     
    // Base Case : If j is source
    if (parent[j] == - 1)
        return;

    printPath(parent, parent[j],temp);
    temp=j;
    for(int i=0;i<g[val].size();i++)
    {
    	if(g[val][i].first==temp)
    		g[val][i].second++;
    }
    val=temp;

}

int djikstra_path(int s,int n,int x)
{
    
    int parent[n];
    int temp=0;
    if(s==x) return 0;

    for(int i=0;i<n;i++) {parent[0]=-1;d[i]=INF;}
    priority_queue<pii,vector<pii>,greater<pii> > q;

    q.push(pii(0,s));
    int u,c,v,w;
    d[s]=0;

    while(!q.empty())
    {
        c=q.top().first;
        u=q.top().second;
        q.pop();

        if(d[u]<c) continue;

        if(u==x) 
        	{
        		val=0;
        		printPath(parent,u,temp);

        	}
       

            for(int i=0;i<g[u].size();i++)
            {
                v=g[u][i].first;
                w=g[u][i].second;

                if(d[v] > d[u]+w)
                {
                    d[v]=d[u]+w;
                    q.push(pii(d[v],v));
                    parent[v]=u;

                }
            }
    }
    return -1;

}

bool comp(int a,int b)
{
	return a>=b;
}

int main() {

	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#endif

		int n,m,k,t;cin>>n>>m>>k>>t;
		for(int i=0;i<n;i++) g[i].clear();

		for(int i=0;i<m;i++)
		{
			int u,v;
			cin>>u>>v;
			g[u].push_back(pii(v,-1));
		}
	for(int i=0;i<k;i++)
		djikstra_path(0,n,n-1);

	vector<int> res;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<g[i].size();j++)
			res.push_back(g[i][j].second);
	}
	sort(res.begin(),res.end(),comp);
	
	while(t--)
	{
		res[0]--;
		sort(res.begin(),res.end(),comp);
	
	}
	cout<<res[0]<<"\n";

	// cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
