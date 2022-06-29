#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 5 * N;

int h[N], e[M], ne[M], idx, n, m, dfn[N], low[N], stk[N], tt, cnt, du[N], id[N], gg, all[N];
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void targan1(int u)
{ // Tarjan's algorithm
    dfn[u] = low[u] = ++cnt;
    stk[++tt] = u;
    st[u] = true;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        if (!dfn[e[i]])
        {
            targan1(e[i]);
            low[u] = min(low[u], low[e[i]]);
        }
        else if (st[e[i]])
            low[u] = min(low[u], dfn[e[i]]);
    }

    if (dfn[u] == low[u])
    {
        ++gg;
        int cur;
        do
        {
            cur = stk[tt--];
            st[cur] = false;
            id[cur] = gg;
            all[gg]++;
        } while (cur != u);
    }
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            targan1(i);
    }
    for (int w = 1; w <= n; w++)
    {
        for (int i = h[w]; i != -1; i = ne[i])
        {
            if (id[w] != id[e[i]])
                du[id[e[i]]] = 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= gg; i++)
    {
        if (!du[i])
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}