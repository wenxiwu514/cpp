#include <bits/stdc++.h>
using namespace std;
const int nn = 5e5 + 5;
const int dep = 20;
int deep[nn], n, m, father[nn][dep], s;
int la[nn], pre[nn << 1], Begin[nn << 1], End[nn << 1];
int cnt;
inline void make_line(int x, int y)
{
    cnt++;
    pre[cnt] = la[x];
    la[x] = cnt;
    Begin[cnt] = x;
    End[cnt] = y;
}
inline void cheshu(int k, int fa)
{
    father[k][0] = fa;
    for (int i = la[k]; i; i = pre[i])
    {
        if (End[i] != fa)
        {
            cheshu(End[i], k);
        }
    }
}
inline void build()
{
    for (int j = 1; j < s; j++)
        for (int i = 1; i <= n; i++)
            father[i][j] = father[father[i][j - 1]][j - 1];
}
inline void init_deep(int k)
{
    if (father[k][0] == 0)
    {
        deep[k] = 0;
    }
    else
    {
        deep[k] = deep[father[k][0]] + 1;
    }
    for (int i = la[k]; i; i = pre[i])
    {
        if (End[i] != father[k][0])
            init_deep(End[i]);
    }
    return;
}
inline int up(int v, int p)
{
    for (int i = 0; i < s; i++)
        if (p & (1 << i))
            v = father[v][i];
    return v;
}
inline int get_lca(int x, int y)
{
    if (deep[x] < deep[y])
        swap(x, y);
    x = up(x, deep[x] - deep[y]);
    if (x == y)
        return y;
    for (int i = s; i >= 0; i--)
        if (father[x][i] != father[y][i] && father[x][i] != 0 && father[y][i] != 0)
        {
            x = father[x][i];
            y = father[y][i];
        }
    return father[x][0];
}
inline int big_lca(int x, int y, int z, int &ans)
{ //本程序核心函数
    int root[3];
    root[0] = get_lca(x, y);
    root[1] = get_lca(y, z);
    root[2] = get_lca(x, z);
    if (root[0] == root[1] && root[1] == root[2])
    {
        ans = root[0];
        return (deep[x] - deep[root[0]]) + (deep[y] - deep[root[0]]) + (deep[z] - deep[root[0]]);
    }
    if (root[0] == root[1] && root[1] != root[2])
    {
        ans = root[2];
        return (deep[x] - deep[root[2]]) + (deep[y] - deep[root[0]]) + (deep[z] - deep[root[2]]) + (deep[root[2]] - deep[root[0]]);
    }
    if (root[0] != root[1] && root[1] == root[2])
    {
        ans = root[0];
        return (deep[x] - deep[root[0]]) + (deep[y] - deep[root[0]]) + (deep[z] - deep[root[2]]) + (deep[root[0]] - deep[root[1]]);
    }
    if (root[0] == root[2] && root[1] != root[2])
    {
        ans = root[1];
        return (deep[x] - deep[root[2]]) + (deep[y] - deep[root[1]]) + (deep[z] - deep[root[1]]) + (deep[root[1]] - deep[root[2]]);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; (1 << i) <= n; i++)
        s++;
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        make_line(x, y);
        make_line(y, x);
    }
    cheshu(1, 0);
    build();
    init_deep(1);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z, ans, d;
        scanf("%d %d %d", &x, &y, &z);
        d = big_lca(x, y, z, ans);
        printf("%d %d\n", ans, d);
    }
    return 0;
}