#include <iostream>

using namespace std;

double bs(double x)
{
    int l = -100, r = 100;
    while (r - l > 1e-8)
    {
        int mid = (l + r) / 2;
        if (mid * mid * mid > x)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}
int main()
{
    double x;
    cin >> x;
    printf("%.6lf", bs(x));
    return 0;
}