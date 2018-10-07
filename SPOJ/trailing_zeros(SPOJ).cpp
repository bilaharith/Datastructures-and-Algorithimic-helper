#include<bits/stdc++.h>

using namespace std;

int main(){
int t;cin>>t;
while(t--)
{
    long long n;
    cin>>n;

long long c=0;
for(long long i=5;i<=n;i=i*5)

{
        int temp=n/i;
        c+=temp;
}
cout<<c<<endl;
}

return 0;

}
