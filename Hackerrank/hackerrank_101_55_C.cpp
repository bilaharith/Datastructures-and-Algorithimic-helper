#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll; 
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

int func_c(int i,int j,vector<ll> inp)
{
	if(i==j) return(max((ll)0,inp[i-1]));

	return (max((ll)0,func_c(i,j-1,inp)+inp[j-1]));
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#endif

	int n;
	cin>>n;
	vector<ll> inp;
	vector<pair<ll,ll> >pairs;
	for(int i=0;i<n;i++)
	{
		int a;cin>>a;
		inp.push_back(a);
	}
	int cnt=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			

				if(func_c(i,j,inp)==0)
					{pairs.push_back(pair<ll,ll>(i,j));cnt++;}
			
		}
	}
	for(int i=0;i<cnt-1;i++)
	{
		for(int j=i+1;j<cnt;j++)
		{	
			if(pairs[i].first<=pairs[j].first && pairs[i].second>pairs[j].first)
				cnt++;

		}
	}
	cout<<cnt<<"\n";


	// cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
