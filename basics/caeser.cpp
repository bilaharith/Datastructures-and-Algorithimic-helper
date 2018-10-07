#include <bits/stdc++.h>

using namespace std;

// Complete the caesarCipher function below.
string caesarCipher(string s, int k) {

    k=k%26;
    for(int i=0;i<s.length();i++){
        if(isalpha(s[i])){
            if(s[i]>='A' && s[i]<='Z'){
                if(s[i]+k>'Z')
                    s[i]=s[i]+k-'A'-1;
                else
                    s[i]=s[i]+k;
            }
            if(s[i]>='a' && s[i]<='z'){
                if(s[i]+k>'z')
                    s[i]=s[i]+k-'a';
                else
                    s[i]=s[i]+k;
            }
        }
    }
    return s;

}

int main()
{

    int n;
    cin >> n;

    string s;
    getline(cin, s);

    int k;
    cin >> k;

    string result = caesarCipher(s, k);

    cout << result << "\n";


    return 0;
}
