#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

typedef pair<int,int> pii;


void simpleSieve(int limit, vector<int> &prime)
{
    bool mark[limit+1];
    memset(mark, true, sizeof(mark));

    for (int p=2; p*p<limit; p++)
    {
        if (mark[p] == true)
        {
            for (int i=p*2; i<limit; i+=p)
                mark[i] = false;
        }
    }

    for (int p=2; p<limit; p++)
    {
        if (mark[p] == true)
        {
            prime.push_back(p);
        }
    }
}

vector<int> segment_seive(int n)
{
    int limit = floor(sqrt(n))+1;
    vector<int> prime;
    simpleSieve(limit, prime);
    vector<int> result;
    int low = limit;
    int high = 2*limit;

    while (low < n)
    {
        if (high >= n)
           high = n;

        bool mark[limit+1];
        memset(mark, true, sizeof(mark));

        for (int i = 0; i < prime.size(); i++)
        {
            int loLim = floor(low/prime[i]) * prime[i];
            if (loLim < low)
                loLim += prime[i];
            for (int j=loLim; j<high; j+=prime[i])
                mark[j-low] = false;
        }

        for (int i = low; i<high; i++)
            if (mark[i - low] == true)
                result.push_back(i);

        low = low + limit;
        high = high + limit;
    }
    return result;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--)
    {
        long long l,r,k;cin>>l>>r>>k;
        int c=0;
        //cout<<l<< " "<<r<"\n";
        if(r>=l){
            //cout<"what\n";
            vector<int> primes=segment_seive(r);
            for(int i=0;i<primes.size();i++)
            {
                if(primes[i]>l && primes[i]<r)
                {
                    int low=i,high=primes.size()-1;
                    while(low<=high)
                    {
                        int mid=low+(high-low)/2;
                        if(primes[mid]==primes[i]+k && primes[mid]<r){c++;break;}
                        else if(primes[mid]>primes[i]+k){high=mid-1;}
                        else low=mid+1;
                    }
                }
            }
        cout<<c<<"\n";
        }
       /* else
        {   //cout<<"hmm\n";
            vector<int> primes=segment_seive(l);
            for(int i=0;i<primes.size();i++)
            {
                //cout<<primes[i]<<"\n";
                if(primes[i]>r && primes[i]<l)
                {
                    int low=i,high=primes.size()-1;
                    while(low<=high)
                    {
                        int mid=low+(high-low)/2;
                        if(primes[mid]==primes[i]+k){c++;break;}
                        else if(primes[mid]>primes[i]+k){high=mid-1;}
                        else low=mid+1;
                    }
                }
            }
        cout<<c<<"\n";
        }*/

    }

    return 0;
}
