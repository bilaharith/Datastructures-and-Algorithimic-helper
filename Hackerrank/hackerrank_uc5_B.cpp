#include <bits/stdc++.h>
using namespace std;

bool compa(map<int,int>::value_type &i,map<int,int>::value_type &j)
{
	return i.second<j.second;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("inp.txt", "r", stdin);
		freopen("output.txt","w", stdout);
	#endif

		int n;cin>>n;
		map<int,int> mymap;
		vector<int> inp(n);
		int s=0;
		for(int i=0;i<n;i++)
			{cin>>inp[i];s+=inp[i];}

		if(s%3!=0) cout<<0<<"\n";
		
		else
		{
				for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(i!=j)
					{
						for(int k=0;k<n;k++)
						{	

							if(j!=k && k!=i)
							{
								//cout<<i<<" "<<j<<" "<<k<<"\n";
								mymap[inp[i]+inp[j]+inp[k]]++;
							}
						}
					}
				}
			}
			//cout<<mymap[3]<<"\n";

			map<int,int>::iterator it=max_element(mymap.begin(),mymap.end(),compa);

			cout<<it->second<<"\n";


		}

		
	// cout<<"Execution time : "<<tick()<<"\n";
	return 0;
}
