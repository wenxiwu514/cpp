#include <bits/stdc++.h>
#define ll long long
#define ri register
#define all(x) x.begin(), x.end()
using namespace std;
const int N = 1e5 + 1;
int n, m, fx[N], fy[N];
inline int low(int x) { return -x & x; }
struct qjc
{
    int t[N];
    inline void update(int x, int k)
    {
        for (; x <= n; x += low(x))
            t[x] += k;
    }
    inline int query(int x)
    {
        int res = 0;
        for (; x; x -= low(x))
            res += t[x];
        return res;
    }
    inline Q(int x, int y) { return query(y) - query(x - 1); }
} _x, _y;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, op, x, y, X, Y; i <= m; i++)
    {
        scanf("%d%d%d", &op, &x, &y);
        switch (op)
        {
        case 1:
            fx[x]++, fy[y]++;
            if (fx[x] == 1)
                _x.update(x, 1);
            if (fy[y] == 1)
                _y.update(y, 1);
            break;
        case 2:
            fx[x]--, fy[y]--;
            if (!fx[x])
                _x.update(x, -1);
            if (!fy[y])
                _y.update(y, -1);
            break;
        case 3:
            scanf("%d%d", &X, &Y);
            if (_x.Q(x, X) == X - x + 1 || _y.Q(y, Y) == Y - y + 1)
                puts("YES");
            else
                puts("NO");
            break;
        }
    }
    return 0;
}