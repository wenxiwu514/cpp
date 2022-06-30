#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx, n, ans = 0x3f3f3f3f, id, siz[N], d[N], f[N];
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs2(int u)
{
    siz[u] = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (!d[e[i]])
        {
            d[e[i]] = d[u] + 1;
            dfs2(e[i]);
            siz[u] += siz[e[i]];
        }
    }
}

void dfs3(int u, int fa)
{
    f[u] = f[fa] + n - 2 * siz[u];
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (e[i] != fa)
        {
            dfs3(e[i], u);
        }
    }
}
int dfs(int u)
{
    st[u] = true;
    int sz = 0, sum = 0;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (!st[e[i]])
        {
            int k = dfs(e[i]);
            sz = max(sz, k);
            sum += k;
        }
    }
    sz = max(sz, n - sum - 1);
    if (sz < ans)
    {
        ans = sz;
        id = u;
    }
    else if (sz == ans && u < id)
    {
        id = u;
    }
    return sum + 1;
}
int sum1 = 0;
int dfs1(int u, int d)
{

    st[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (!st[e[i]])
        {
            sum1 += dfs1(e[i], d + 1);
        }
    }
    return d;
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    ans = 0, id = 1;
    d[1] = 1;
    dfs2(1);
    for (int i = 1; i <= n; i++)
        ans += d[i];
    ans -= n;
    f[1] = ans;
    for (int i = h[1]; i != -1; i = ne[i])
    {
        dfs3(e[i], 1);
    }
    for (int i = 2; i <= n; i++)
    {
        if (f[i] < ans)
        {
            ans = f[i];
            id = i;
        }
    }

    printf("%d %d", id, ans);
    return 0;
}
