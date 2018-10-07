#include<bits/stdc++.h>
#include <limits>
#include<iostream>
#include<unordered_map>
#include<cstdio>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int s;cin>>s;
    while(s--)
    {

    unordered_map<string,string> pesel;
    unordered_map<string,string>::iterator it;
        int p;cin>>p;
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        char str_pes[40],str_mro[10];
        for(int i=0;i<p;i++)
        {
            cin>>str_pes>>str_mro;
            pesel[(string)str_pes]=str_mro;
        }
        int z;cin>>z;
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        char old_mro[10],new_mro[10];
        for(int i=0;i<z;i++)
        {
            cin>>old_mro>>new_mro;
            for(it=pesel.begin();it!=pesel.end();it++)
            {
                if(it->second==old_mro)
                    {
                        //cout<<"FOUND"<<endl;
                        it->second=new_mro;
                    }
            }
        }
        int x;cin>>x;
        cin.ignore(numeric_limits <streamsize>::max(), '\n');
        char result[40];
        for(int i=0;i<x;i++)
        {
            cin>>result;
            unordered_map<string,string>::iterator it;
            it=pesel.find(result);
            if(it!=pesel.end())
            {
                cout<<it->first<<" "<<it->second<<endl;
            }
        }

    }



    return 0;
}
