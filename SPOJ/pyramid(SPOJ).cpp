#include<stdio.h>
#include<math.h>
double sq(double x)
{
    return pow(x,2);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t>0)
    {
        double a,b,c,d,e,f; /* 6 edge lengths */
        double vol; /* volume */
        scanf("%lf %lf %lf %lf %lf %lf",&a,&b,&c,&d,&e,&f);
        vol  = sqrt(4*sq(a)*sq(b)*sq(c)-sq(a)*sq(sq(b)+sq(c)-sq(f))-sq(b)*sq(sq(a)+sq(c)-sq(e))-sq(c)*sq(sq(a)+sq(b)-sq(d))+(sq(b)+sq(c)-sq(f))*(sq(c)+sq(a)-sq(e))*(sq(a)+sq(b)-sq(d)))/12;

        printf("%.4lf\n",vol);
        t--;
    }
    return 0;
}
