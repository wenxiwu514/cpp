#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int f[N][25], d[N], dis[N], T, n, m, tot, t, ver[2 * N], ne[2 * N], head[N];
queue<int> q;
void add(int x, int y)
{
    ver[++tot] = y;
    ne[tot] = head[x];
    head[x] = tot;
}
int lca(int x, int y)
{
    if (d[x] > d[y])
        swap(x, y);
    for (int i = t; i >= 0; i--)
        if (d[f[y][i]] >= d[x])
            y = f[y][i];
    if (x == y)
        return x;
    for (int i = t; i >= 0; i--)
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}
int dist(int a, int b) { return dis[a] + dis[b] - 2 * dis[lca(a, b)]; }
int main()
{
    scanf("%d%d", &n, &m);
    t = (int)(log(n) / log(2)) + 1;
    for (int i = 1; i <= n; i++)
        head[i] = d[i] = 0;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    q.push(1);
    d[1] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = ne[i])
        {
            int y = ver[i];
            if (d[y])
                continue;
            d[y] = d[x] + 1;
            dis[y] = dis[x] + 1;
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
                f[y][j] = f[f[y][j - 1]][j - 1];
            q.push(y);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if (dist(x1, y1) + dist(x2, y2) >= dist(x1, x2) + dist(y1, y2))
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}