#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;

const int N = 3e5 + 5;

int t, n, a[N], premax[N], premin[N], sufmax[N], sufmin[N];
int maxp[N], minp[N], smax[N], smin[N];

int ans = 0;

void getans(int x, int y, bool f)
{
    if (x == 1)
    {
        if ((premax[y] == a[y] && premin[y] == a[x]) || (premax[y] == a[x] && premin[y] == a[y]))
        {
            ans++;
            return;
        }
    }
    if (y == n)
    {
        if ((sufmax[x] == a[x] && sufmin[x] == a[y]) || (sufmax[x] == a[y] && sufmin[x] == a[x]))
        {
            ans++;
            return;
        }
    }
    if (y == n && x == 1)
    {
        if (premax[y] == a[y])
        {
            getans(1, minp[y], 1);
            ans++;
        }
        else if (premax[y] == a[x])
        {
            getans(minp[y], y, 1);
            ans++;
        }
        else
        {
            getans(1, maxp[y], 0);
            getans(maxp[y], y, 0);
        }
    }
    else
    {
        if (f)
        {
            if (x == 1)
            {
                int place = maxp[y];
                ans++;
                getans(1, place, 0);
            }
            else if (y == n)
            {
                int place = smax[x];
                ans++;
                getans(place, y, 0);
            }
        }
        else
        {
            if (x == 1)
            {
                int place = minp[y];
                ans++;
                getans(1, place, 1);
            }
            else if (y == n)
            {
                int place = smin[x];
                ans++;
                getans(place, y, 1);
            }
        }
    }
}

int main()
{
    memset(premin, 0x3f, sizeof premin);
    memset(sufmin, 0x3f, sizeof sufmin);
    scanf("%d", &t);
    while (t--)
    {
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if (n == 1)
        {
            printf("0\n");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > premax[i - 1])
            {
                premax[i] = a[i];
                maxp[i] = i;
            }
            else
            {
                premax[i] = premax[i - 1];
                maxp[i] = maxp[i - 1];
            }
            if (a[i] < premin[i - 1])
            {
                premin[i] = a[i];
                minp[i] = i;
            }
            else
            {
                premin[i] = premin[i - 1];
                minp[i] = minp[i - 1];
            }
        }
        for (int i = n; i >= 1; i--)
        {
            if (a[i] > sufmax[i + 1])
            {
                sufmax[i] = a[i];
                smax[i] = i;
            }
            else
            {
                sufmax[i] = sufmax[i + 1];
                smax[i] = smax[i + 1];
            }
            if (a[i] < sufmin[i + 1])
            {
                sufmin[i] = a[i];
                smin[i] = i;
            }
            else
            {
                sufmin[i] = sufmin[i + 1];
                smin[i] = smin[i + 1];
            }
        }
        getans(1, n, 1);
        printf("%d\n", ans);
        for (int i = 1; i <= n + 1; i++)
        {
            premax[i] = sufmax[i] = 0;
            premin[i] = sufmin[i] = 2e9;
            maxp[i] = minp[i] = smax[i] = smin[i] = 0;
        }
    }
    return 0;
}