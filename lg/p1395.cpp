#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4 + 10, M = 2 * N;
int h[N], e[M], ne[M], idx, n, ans = 0x3f3f3f3f, id;
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
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
    dfs(1);
    memset(st, false, sizeof st);
    dfs1(id, 0);
    printf("%d %d\n", id, sum1);
    return 0;
}
