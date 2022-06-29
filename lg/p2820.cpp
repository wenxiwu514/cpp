#include <iostream>
#include <cstring>

const int N = 5010, M = 200010;

int g[N][N], idx, n, m, dist[N];
bool st[N];

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        if (dist[t] == 0x3f3f3f3f)
            return 0x3f3f3f3f;
        res += dist[t];
        for (int j = 1; j <= n; j++)
        {
            dist[j] = std::min(dist[j], g[t][j]);
        }
        st[t] = 1;
    }
    return res;
}
int main()
{
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        g[x][y] = std::min(g[x][y], z);
        g[y][x] = std::min(g[y][x], z);
        sum += z;
    }
    int a = prim();
    std::cout << sum - a << std::endl;
    return 0;
}