#include <bits/stdc++.h>
using namespace std;

int fa[100010], ans[100010], n, m;
char col[100010];

int find(int x)
{
    if (fa[x] != x)
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x, int y)
{
    fa[find(x)] = find(y);
}

int main()
{
    scanf("%d%d", &n, &m);
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        cin >> col[i];
    }

    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (col[a] == col[b])
        {
            merge(a, b);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        char c;
        cin >> a >> b >> c;
        if (find(a) == find(b) && col[a] != c)
            ans[++cnt] = 0;
        else
            ans[++cnt] = 1;
    }
    for (int i = 1; i <= cnt; i++)
        printf("%d", ans[i]);
    return 0;
}