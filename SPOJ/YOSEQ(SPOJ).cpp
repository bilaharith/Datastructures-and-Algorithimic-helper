#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    int fa=0,fb=0,fc=0,fd=0,fe=0,ff=0,fg=0,fh=0,fi=0,fj=0;
    string s;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='0')
            fa=1;
        else if(s[i]=='1')
            fb=1;
        else if(s[i]=='2')
            fc=1;
        else if(s[i]=='3')
            fd=1;
        else if(s[i]=='4')
            fe=1;
        else if(s[i]=='5')
            ff=1;
        else if(s[i]=='6')
            fg=1;
        else if(s[i]=='7')
            fh=1;
        else if(s[i]=='8')
            fi=1;
        else if(s[i]=='9')
            fj=1;
    }
    if(fa*fb*fc*fd*fe*ff*fg*fh*fi*fj==0)
    {
        if(fa==0)
            cout<<0<<endl;
        else if(fb==0)
            cout<<1<<endl;
        else if(fc==0)
            cout<<2<<endl;
        else if(fd==0)
            cout<<3<<endl;
        else if(fe==0)
            cout<<4<<endl;
        else if(ff==0)
            cout<<5<<endl;
        else if(fg==0)
            cout<<6<<endl;
        else if(fh==0)
            cout<<7<<endl;
        else if(fi==0)
            cout<<8<<endl;
        else if(fj==0)
            cout<<9<<endl;
    }
    else
    {
        for(long long i=10;true;i++)
        {
            string find_s=to_string(i);
            size_t found=s.find(find_s);
            if(found==string::npos)
            {cout<<find_s<<endl; break;}
        }
    }
}
