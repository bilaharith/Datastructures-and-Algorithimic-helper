#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long double x)
{

  long double sr = sqrt(x);


  return ((sr - floor(sr)) == 0);
}

int main() {
  int n;
  while(n)
  {
      cin>>n;
      vector<long double> input(n);
      for(int i=0;i<n;i++)
           cin>>input[i];
      sort(input.begin(),input.end());
      int high_sq=pow(input[n-1],2);

  }
  return 0;
}
