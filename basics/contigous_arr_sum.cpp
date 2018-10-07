#include <iostream>
using namespace std;

int countsubarray(int array[], int n, int k,int m)
{
    int count = 0;
    int i, j, mul;

    for (i = 0; i < n; i++)
    {
        if (array[i]%m== k)
            count++;
        mul = array[i];

        for (j = i + 1; j < n; j++)
        {
            mul = mul * array[j];
            if (mul %m== k)
                count++;
        }
    }

    return count;
}

// Driver Code
int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,m,k;cin>>n>>m>>k;
        int array[n];
        for(int i=0;i<n;i++)
            cin>>array[i];
    int size = sizeof(array) / sizeof(array[0]);
    int count = countsubarray(array, size, k,m);
    cout << count << "\n";
    }

}
