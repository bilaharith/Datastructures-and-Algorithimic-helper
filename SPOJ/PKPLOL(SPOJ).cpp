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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        vector<string> inp(10);

            inp[0]="abcdef";inp[1]="bc";inp[2]="abdeg";
            inp[3]="abcdg";inp[4]="bcfg";inp[5]="acdfg";
            inp[6]="acdefg";inp[7]="abc";inp[8]="abcdefg";
            inp[9]="abcdfg";

    int T;cin>>T;
    for(int t=1;t<=T;t++)
    {
        int n;cin>>n;
        cout<<"Case "<<t<<": ";
        cout<<inp[n]<<"\n";;
    }


    return 0;
}
