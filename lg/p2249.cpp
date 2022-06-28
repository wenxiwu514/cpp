#include <iostream>

using namespace std;

int a[1000100], n, m, k;
int binsearch(int l, int r, int x)
{
    while (l <= r)
    {
        int mid = l + (r - l >> 1);
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return a[l] == x ? l : -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &k);
        printf("%d ", binsearch(1, n, k));
    }
    return 0;
}