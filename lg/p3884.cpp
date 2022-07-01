#include <cstdio>
#include <algorithm>
using namespace std;
int n, ans1, ans2, depth1, depth2;
int tot, to[202], nxt[202], head[101];
int fa[101], deep[101], width[101];
void add(int x, int y)
{
    to[++tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
void dfs(int x, int pre, int step)
{
    fa[x] = pre;
    deep[x] = step;
    for (int i = head[x]; i; i = nxt[i])
    {
        int y = to[i];
        dfs(y, x, step + 1);
    }
}
void lca(int x, int y)
{
    if (deep[x] < deep[y])
    {
        swap(x, y);
        while (deep[x] > deep[y])
            x = fa[x], depth2++;
        while (x != y)
        {
            x = fa[x], y = fa[y];
            depth2++;
            depth1++;
        }
    }
    else
    {
        while (deep[x] > deep[y])
            x = fa[x], depth1++;
        while (x != y)
        {
            x = fa[x], y = fa[y];
            depth1++;
            depth2++;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++)
        width[deep[i]]++;
    for (int i = 1; i <= n; i++)
        ans1 = max(ans1, deep[i]);
    for (int i = 1; i <= n; i++)
        ans2 = max(ans2, width[i]);
    int u, v;
    scanf("%d%d", &u, &v);
    lca(u, v);
    printf("%d\n%d\n%d", ans1, ans2, depth1 * 2 + depth2);
    return 0;
}