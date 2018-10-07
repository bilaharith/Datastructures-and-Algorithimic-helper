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

struct TreeNode{
int key;
TreeNode *left,*right;
};

TreeNode *insert(TreeNode *node,int data)
{
	if(node==NULL)
	{
		TreeNode *temp;
		temp=new TreeNode;
		temp->key=data;
		temp->left=NULL;
		temp->right=NULL;
		return temp;
	}
	if(data > node->key)
	{
		node->right=insert(node->right,data);
	}
	else if(data < node->key)
	{
		node->left=insert(node->left,data);
	}
	return node;
}

void inorder(TreeNode *node)
{
	if(node!=NULL)
	{
		inorder(node->left);
		cout<<node->key<<" ";
		inorder(node->right);
	}

}

TreeNode *search(TreeNode *node,int data)
{
	if(node==NULL) {return NULL;}

	if(data < node->key) return search(node->left,data);
	else if(data > node->key) return search(node->right,data);
	else return node;

}

TreeNode *min_elem(TreeNode *node)
{
	if(node==NULL) return NULL;

	if(node->left) return min_elem(node->left);
	else return node;
}

TreeNode *max_elem(TreeNode *node)
{
	if(node==NULL) return NULL;
	if(node->right) return max_elem(node->right);
	else return node;
}

TreeNode *dele(TreeNode *node,int data)
{
	TreeNode *temp;
	if(node==NULL)
		cout<<"nothin\n";
	if(data<node->key) node->left= dele(node->left,data);
	else if(data>node->key) node->right= dele(node->right,data);
	else
	{
		if(node->right && node->left)
        {
            /* Here we will replace with minimum element in the right sub tree */
            temp = min_elem(node->right);
            node->key = temp->key;
            /* As we replaced it with some other node, we have to delete that node */
            node->right = dele(node->right,temp->key);
        }
        else
        {
            /* If there is only one or zero children then we can directly
            remove it from the tree and connect its parent to its child */
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;
            free(temp); /* temp is longer required */
        }
	}
	return node;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#endif

	TreeNode *root=NULL,*temp;

	root=insert(root,50);

	root=insert(root,30);
	root=insert(root,80);
	root=insert(root,60);
	root=insert(root,40);
	root=insert(root,20);

    inorder(root);
    cout<<"\n";
    temp=search(root,30);
    if(temp==NULL) cout<<"NOT FOUND\n";
    else cout<<"Found !\n";

    cout<<"Min elem: "<<min_elem(root)->key<<"\n";
    cout<<"Max elem: "<<max_elem(root)->key<<"\n";

    root=dele(root,40);
    inorder(root);
	// cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
