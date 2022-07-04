#include <iostream>

using namespace std;
int a[100010], n, q;

int bs1(int l, int r, int x)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    if (a[l] == x)
        return l;
    else
        return -1;
}

int bs2(int l, int r, int x)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    if (a[l] == x)
        return l;
    else
        return -1;
}
int main()
{
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    while (q--)
    {
        int x;
        scanf("%d", &x);
        int qq = 1;
        int x1 = bs1(0, n - 1, x);
        int x2 = bs2(0, n - 1, x);
        printf("%d %d\n", x1, x2);
    }
    return 0;
}