#include<bits/stdc++.h>

using namespace std;

bool comp(char c1,char c2){

return c1<c2;
}

int main(){

string s="aabdcdc";
int n=s.length();
sort(s.begin(),s.end());
cout<<s<<endl;

return 0;}
