#include <iostream>
#include <cstring>
using namespace std;

inline int read()
{
    char c = getchar();
    int x = 0, f = 1;
    for (; !isdigit(c); c = getchar())
        if (c == '-')
            f = -1;
    for (; isdigit(c); c = getchar())
        x = x * 10 + c - 48;
    return x * f;
}

const int N = 5e5 + 10, M = 2 * N;

int h[N], e[M], ne[M], idx, d[M], p[M][22];

void add(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}

void dfs(int u, int f)
{
    d[u] = d[f] + 1;
    p[u][0] = f;
    for (int i = 1; (1 << i) <= d[u]; i++)
        p[u][i] = p[p[u][i - 1]][i - 1];
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int v = e[i];
        if (v != f)
            dfs(v, u);
    }
}

int lca(int a, int b)
{
    if (d[a] < d[b])
        swap(a, b);
    for (int i = 20; i >= 0; i--)
        if (d[p[a][i]] >= d[b])
            a = p[a][i];
    if (a == b)
        return a;
    for (int i = 20; i >= 0; i--)
        if (p[a][i] != p[b][i])
            a = p[a][i], b = p[b][i];
    return p[a][0];
}
int main()
{
    memset(h, -1, sizeof h);
    int a, b, c, x, y;
    a = read();
    b = read();
    c = read();
    for (int i = 1; i < a; i++)
    {
        x = read();
        y = read();
        add(x, y);
        add(y, x);
    }
    dfs(c, 0);
    for (int i = 1; i <= b; i++)
    {
        x = read();
        y = read();
        printf("%d\n", lca(x, y));
    }
    return 0;
}