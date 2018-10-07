#include<bits/stdc++.h>

using namespace std;

void sieve_prime(int m,int n)
{
        vector<bool> primes(n+1,true);
    for(int i=2;i<=(int)sqrt(n);i++)
    {
        for(int j=2*i;j<=n;j+=i)
        {
            primes[j]=false;
        }
    }
    for(int i=m;i<primes.size();i++)
        if(primes[i]) cout<<i<<" ";
}
int main()
{
    int m,n;
    cin>>m>>n;
    sieve_prime(m,n);
    return 0;

}
