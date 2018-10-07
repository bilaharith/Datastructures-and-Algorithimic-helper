#include<bits/stdc++.h>
using namespace std;int main(){int n=10;while(n--){string s;cin>>s;string::iterator a=s.begin(),b=s.end();int u=count(a,b,'T')+count(a,b,'D')+count(a,b,'L')+count(a,b,'F');if(s.size()==1)cout<<1;else cout<<u*(u+1)/2+1;cout<<"\n";}}
