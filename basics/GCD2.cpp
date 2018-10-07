#include<iostream>
#include<string>
using namespace std;
 int c=0;
int gcd(int a, string b)
{


	if (b=="0")
		return 0;
    if(a==0 && c==0)
        return stoi(b);
    if(c>0)
        int b=stoi(b);
    if(c==0)
        return gcd(b,mod(b,a));
}


int mod(string num, int a)
{
    int res = 0;

    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;
    c++;
    return res;
}

int main()
{
    string num;cin>>num;
    int n;cin>>n;
    cout << mod(num, n);
    return 0;
}
