#include<bits/stdc++.h>

using namespace std;

int mod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;

    return res;
}

bool isPrime(long long n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}

bool isPlover(long long a)
{
    long long res_sum=0;
    while(a>0)
    {
        res_sum+=mod(to_string(a),3);
        //cout<<a<<"|||| "<<res_sum<<"\n";
        a=a/3;
    }
    if (res_sum==1) return false;
    if(isPrime(res_sum))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;cin>>t;
    while(t--)
    {
        long long n,k,counter=0;
        cin>>n>>k;
        for(long long i=2;i<=n;i++)
        {

            if(isPlover(i))
            {
                //cout<<"|||||| "<<i<<"\n";
                counter++;
                if(counter==k)
                {
                    cout<<i<<"\n";break;
                }
            }
            if(k-counter>n-i)
                break;

        }
        if(k>counter)
            cout<<-1<<"\n";
    }

    return 0;
}
