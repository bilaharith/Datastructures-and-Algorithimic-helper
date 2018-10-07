#include<bits/stdc++.h> 
using namespace std; 

typedef uint64_t lt;

vector<int> prime_nos;

void SieveOfEratosthenes(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n+1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        { 
            // Update all multiples of p 
            for (int i=p*2; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
    // Print all prime numbers 
    for (int p=2; p<=n; p++) 
       if (prime[p]) 
          prime_nos.push_back(p);
} 


int main() 
{ 

    #ifndef ONLINE_JUDGE
        freopen("inp.txt", "r", stdin);
        freopen("output.txt","w", stdout);
    #endif

    int t;cin>>t;
    while(t--)
    {
        lt n;cin>>n;
        lt c=0;
        SieveOfEratosthenes(int(cbrt(n)));

       // cout<<int(cbrt(n))<<" "<<prime_nos.size()<<"\n";

        for(int i=0;i<prime_nos.size();i++)
        {   
           // cout<<prime_nos[i]<<"\n";

            int x=1;
            while(x*pow(prime_nos[i],3)<=n)
                {c++;x++;}
        }

       cout<<c<<"\n";

    prime_nos.clear();

    }
    return 0; 
} 