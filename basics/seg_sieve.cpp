#include<bits/stdc++.h>

using namespace std;

void simple_seive(int l,vector<long long> prime)
{
    vector<bool> isprimes(l,true);

    for(int i=2;i<=l;i++)
    {
        for(int j=2*i;j<=l;j+=i)
        {
            isprimes[j]=false;
        }
    }
    prime.push_back(2);
    for(int i=3;i<=l;i+=2)
        if(isprimes[i]) prime.push_back(i);
}

void segment_seive(long long m,long long n)
{
    vector<long long> prime;
    int limit=sqrt(n);
    simple_seive(limit,prime);

    vector<bool> isprime(n-m+1,true);

    for(int i=0;(long long)prime[i]*prime[i]<=n;i++)
       {
        int currPrime=prime[i];
        long long base=(m/currPrime)*currPrime;
        if(base<m)
            base+=currPrime;
        for(long long j=base;j<=n;j+=currPrime)
            isprime[j-m]=false;
        if(base==currPrime)
            isprime[base-m]=true;
    }
    for(int i=0;i<=n-m;i++)
        if(isprime[i])
        cout<<i+m<<" ";

}


int main(){
long long n,m;cin>>m>>n;
segment_seive(m,n);
return 0;}
