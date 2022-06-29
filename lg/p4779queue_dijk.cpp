#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1e5 + 10, M = 2 * N;
typedef pair<int, int> PII;
int h[N], e[M], w[M], ne[M], idx, n, m, s, dist[N];
bool st[N];
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a];
    h[a] = idx++;
}

void dijkstra(int x)
{
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> p;
    p.push({0, x});
    while (p.size())
    {
        PII t = p.top();
        p.pop();

        int dd = t.first, vv = t.second;
        if (st[vv])
            continue;
        st[vv] = true;

        for (int i = h[vv]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[vv] + w[i])
            {
                dist[j] = dist[vv] + w[i];
                p.push({dist[j], j});
            }
        }
    }
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &s);
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", dist[i]);
    }
    return 0;
}