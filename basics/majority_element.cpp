#include<bits/stdc++.h>

using namespace std;

int main(){
int n=11;
int a[]={0,1,1,4,5,1,6,6,1,1,3,1};

sort(a+1,a+n+1);//sorted

//now the majority element is potentially a[n/2 +1]

int maj=a[n/2+1];
//count numberofoccruences of maj
int nOcc=0;
for(int i=1;i<=n;i++){
    if(a[i]==maj)
        nOcc++;
}
if(nOcc>=n/2+1)
    cout<<"Majority element is "<<maj<<"\nAnd it occurs "<<nOcc<<" times\n";
else
    cout<<"-1\n";
return 0;
}
