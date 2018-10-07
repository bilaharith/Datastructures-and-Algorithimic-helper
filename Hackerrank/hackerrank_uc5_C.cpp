#include <bits/stdc++.h>
using namespace std;

typedef map<int,int> M;

M mymap;
int c;

bool compa(M::value_type &i,M::value_type &j)
{
	return i.second<j.second;
}

bool compa2(map<int,int>::value_type &i,map<int,int>::value_type &j)
{
	return i.second<j.second;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#endif

		int n,m,a,b,x,y;cin>>n>>m>>a>>b;

		list<int> adj(n);

		for(int i=0;i<m;i++)
		{
			cin>>x>>y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			mymap[x]++;
			mymap[y]++;
		}

		M::iterator it1=max_element(mymap.begin(),mymap.end(),compa);
		M::iterator it2=min_element(mymap.begin(),mymap.end(),compa2);

		int val1=a*(it2->second);
		int val2=b*(it1->second);
		M::iterator it;
		for(it=mymap.begin();it!=mymap.end();it++)
		{
			if(it->second >val1  && it->second < val2 )
				c++;
		}

		cout<<c<<"\n";

	// cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
