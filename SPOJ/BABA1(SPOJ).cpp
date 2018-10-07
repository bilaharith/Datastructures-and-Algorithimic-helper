#include<bits/stdc++.h>
#include<cmath>
using namespace std;

//  limit for float comparison
#define eps 1e-6

// Utility method to get area of right angle triangle,
// given base and hypotenuse
double getArea(double base, double hypotenuse)
{
    double height = sqrt(hypotenuse*hypotenuse - base*base);
    return 0.5 * base * height;
}

// Prints base and height of triangle using hypotenuse
// and area information
void printRightAngleTriangle(double hypotenuse, int area)
{
    double hsquare = pow(hypotenuse,2);

    // maximum area will be obtained when base and height
    // are equal (= sqrt(h*h/2))
    double sideForMaxArea = sqrt(hsquare / 2.0);
    double maxArea = getArea(sideForMaxArea, hypotenuse);

    // if given area itself is larger than maxArea then no
    // solution is possible
    if (area > maxArea)
    {
        cout << -1;
        return;
    }

    double low = 0.0;
    double high = sideForMaxArea;
    double base;

    // binary search for base
    while (abs(high - low) > eps)
    {
        base = (low + high) / 2.0;
        if (getArea(base, hypotenuse) >= area)
            high = base;
        else
            low = base;
    }

    // get height by pythagorean rule
    double height = sqrt(hsquare - base*base);
    if(base<height)
        printf("%.6lf %.6lf %.6lf",base,height,hypotenuse);
    else
        printf("%.6lf %.6lf %.6lf",height,base,hypotenuse);
}

// Driver code to test above methods
int main()
{
    int t;cin>>t;
    while(t--)
    {
     double h,a;cin>>h>>a;

    printRightAngleTriangle(h, a);
    }

    return 0;
}
