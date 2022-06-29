#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 510;
ll n, m, Q, dis[N][N], cro[N], to[N][N];
struct Edge
{
    ll c, id;
} pro[N];
inline ll read()
{
    ll s = 0, w = 1;
    char ch;
    ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            w = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        s = s * 10 + ch - '0', ch = getchar();
    return s * w;
}
bool cp(Edge a, Edge b) { return a.c == b.c ? a.id < b.id : a.c < b.c; }
int main()
{
    scanf("%lld%lld%lld", &n, &m, &Q);
    for (ll i = 1; i <= n; i++)
        scanf("%lld", &pro[i].c), pro[i].id = i;
    sort(pro + 1, pro + 1 + n, cp);
    for (ll i = 1; i <= n; i++)
        cro[pro[i].id] = i;
    for (ll i = 1; i <= n; i++)
        for (ll j = 1; j <= n; j++)
            dis[i][j] = to[i][j] = 1e11;
    for (ll i = 1; i <= n; i++)
        to[i][i] = 0;
    for (ll i = 1, x, y, z; i <= m; i++)
    {
        scanf("%lld%lld%lld", &x, &y, &z);
        x = cro[x];
        y = cro[y];
        to[x][y] = min(to[x][y], z);
        to[y][x] = to[x][y];
    }
    for (ll k = 1; k <= n; k++)
        for (ll i = 1; i <= n; i++)
            for (ll j = 1; j <= n; j++)
            {
                to[i][j] = min(to[i][j], to[i][k] + to[k][j]);
                dis[i][j] = min(to[i][j] + max(pro[i].c, max(pro[j].c, pro[k].c)), dis[i][j]);
            }
    for (ll i = 1, ax, ay; i <= Q; i++)
    {
        scanf("%lld%lld", &ax, &ay);
        ax = cro[ax];
        ay = cro[ay];
        printf("%lld\n", dis[ax][ay]);
    }
    return 0;
}