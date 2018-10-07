#include <iostream>
using namespace std;

int reverse_n(int n)
{
    int reversedNumber = 0, remainder;
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n /= 10;
    }
    return reversedNumber;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {int n,m;
    cin >> n>>m;

    int n_rev=reverse_n(n);
    int m_rev=reverse_n(m);
    int sum_rev=reverse_n(n_rev+m_rev);

    cout<< sum_rev<<endl;

    }


    return 0;
}
