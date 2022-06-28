#include <iostream>

using namespace std;

const int N = 1010;
int p[N], s[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

bool merge(int x, int y)
{
    if (find(y) == find(x))
        return false;
    p[find(y)] = find(x);
    return true;
}
int main()
{
    int n, m, a, b, t;
    while (true)
    {
        scanf("%d%d", &n, &m);
        if (!n)
            break;
        t = n - 1;
        for (int i = 1; i <= n; i++)
            p[i] = i;
        while (m--)
        {
            scanf("%d%d", &a, &b);
            if (merge(a, b))
                t--;
        }
        printf("%d\n", t);
    }
    return 0;
}