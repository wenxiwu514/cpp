#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N];
int m, n;
int binsearch(int x)
{
    int l = 0, r = m - 1;
    while (l <= r)
    {
        int mid = l + r >> 1;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (l == 0)
        return abs(x - a[0]);
    else if (l == m)
        return abs(x - a[m - 1]);
    else
        return min(abs(a[l] - x), abs(x - a[l - 1]));
}
int main()
{

    scanf("%d%d", &m, &n);
    for (int i = 0; i < m; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);
    sort(a, a + m);
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += binsearch(b[i]);
    printf("%d", sum);
    return 0;
}