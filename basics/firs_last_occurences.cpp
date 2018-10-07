#include<iostream>
using namespace std;

int binary_first_occ(int a[],int n,int x){

int l=0,r=n,m,result=-1;

while(l<=r){
    m=(l+r)/2;

    if(x==a[m])
    {
        result=m;
        r=m-1;
    }
    else if(x>a[m]){
        l=m+1;
    }
    else if(x<a[m]){
        r=m-1;
    }
    else
        continue;
}
return result;

}
int binary_last_occ(int a[],int n,int x){

int l=0,r=n,m,result=-1;

while(l<=r){
    m=(l+r)/2;

    if(x==a[m])
    {
        result=m;
        l=m+1;
    }
    else if(x>a[m]){
        l=m+1;
    }
    else if(x<a[m]){
        r=m-1;
    }
    else
        continue;
}
return result;

}

int main(){
    int x;
int a[]={2,3,3,4,5,5,5,8,10};
cout<<"Input the number you want to check(First occ., Last occ. and Number of occ.)"<<endl;
cin>>x;
cout<<"first occ is at "<<binary_first_occ(a,9,x)<<endl;
cout<<"last occ is at "<<binary_last_occ(a,9,x)<<endl;
if(binary_first_occ(a,9,x)!=-1){
cout<<"Number of times it appears is "<< binary_last_occ(a,9,x)- binary_first_occ(a,9,x)+1<<endl;
}
else
    cout<<"Number of times it appears is ZERO times"<<endl;
return 0;}
