#include <bits/stdc++.h>

using namespace std;

string super_reduced_string(string s){

    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1] && s.size()!=2)
        {
                s.erase(i,2);
                i=0;
        }
        if(s[i]==s[i+1] && s.size()==2)
            return "Empty String";
    }
        return s;

}

int main() {
    std::string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
