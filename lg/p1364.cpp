#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4 + 10, M = 2 * N;
int h[N], e[M], ne[M], w[M], idx, n, ans = 0x3f3f3f3f, id, siz[N], f[N];
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs2(int u, int fa, int dep)
{
    siz[u] = w[u];
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] != fa)
        {
            dfs2(e[i], u, dep + 1);
            siz[u] += siz[e[i]];
        }
    }
    f[1] += w[u] * dep;
}

void dfs3(int u, int fa)
{
    f[u] = f[fa] + siz[1] - 2 * siz[u];
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] != fa)
        {
            dfs3(e[i], u);
        }
    }
    ans = min(ans, f[u]);
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int qq, a, b;
        scanf("%d%d%d", &qq, &a, &b);
        w[i] = qq;
        if (a)
        {
            add(i, a);
            add(a, i);
        }
        if (b)
        {
            add(i, b);
            add(b, i);
        }
    }
    ans = 0, id = 1;
    dfs2(1, 0, 0);
    ans = f[1];
    for (int i = h[1]; i != -1; i = ne[i])
    {
        dfs3(e[i], 1);
    }
    printf("%d", ans);
    return 0;
}
