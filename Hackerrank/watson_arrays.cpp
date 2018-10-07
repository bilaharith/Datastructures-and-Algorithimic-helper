#include<bits/stdc++.h>
#include<string>

using namespace std;
string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";

    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);

    // Below two indexes are used to find positions
    // in result.
    int i_n1 = 0;
    int i_n2 = 0;

    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';

        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0;

        // Go from right to left in num2
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';

            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position.
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;

            // Carry for next iteration
            carry = sum/10;

            // Store result
            result[i_n1 + i_n2] = sum % 10;

            i_n2++;
        }

        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;

        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }

    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;

    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";

    // generate the result string
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);

    return s;
}
int mod(string num, int a)
{
    // Initialize result
    int res = 0;

    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
         res = (res*10 + (int)num[i] - '0') %a;

    return res;
}



int main()
{ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    {

    int n,m,k;cin>>n>>m>>k;
    vector<int> arr(n);
    vector<bool> mul(n,false);

        for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]%m==0)
            mul[i]=true;
    }
        if(m==1)
            cout<<n*(n+1)/2<<"\n";

    else if(k!=0)
    {
        long long c=0;
        for(int i=0;i<n && !(mul[i]);i++)
        {
            if(mod(to_string(arr[i]),m)==k)
                c++;
            string prod=to_string(arr[i]);
            for(int j=i+1;j<n;j++)
            {
                if(j<n && mul[j])
                    break;
                else
                {
                    prod=multiply(prod,to_string(arr[j]));
                }
                if(mod(prod,m)==k)
                    c++;
            }
        }

        cout<<c<<"\n";
    }
    else
    {
        vector<long long> seq_sum(n,0);
        int f=0;
        for(int i=0,j=0;i<mul.size();i++)
        {
            //cout<<mul[i]<<" "<<endl;
            if(!(mul[i]))
               {
                   seq_sum[j]++;
                   f=1;
               }
            else if(mul[i] && f==1)
            {
                f=0;j++;
            }
        }
        long long sum_rem=0;
        for(int i=0;i<seq_sum.size();i++)
        {
            //cout<<"SEQ_LENGTHS __"<<seq_sum[i]<<endl;
            if(seq_sum[i]==0)
                break;
            else
            {
                int temp=seq_sum[i]*(seq_sum[i]+1)/2;
                sum_rem+=temp;
            }
        }

        long long suma=n*(n+1)/2;
        cout<<suma-sum_rem<<"\n";
    }

    }
    return 0;
}
