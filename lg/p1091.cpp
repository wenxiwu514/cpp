#include <iostream>
#include <cstring>

using namespace std;

int a[111], n, uu[111], dd[111];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        uu[i] = 1;
        dd[i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (a[i] > a[j])
            {
                uu[i] = max(uu[i], uu[j] + 1);
            }
        }
    }
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[i] > a[j])
            {
                dd[i] = max(dd[i], dd[j] + 1);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        res = max(res, uu[i] + dd[i] - 1);
    }
    cout << n - res;
    return 0;
}