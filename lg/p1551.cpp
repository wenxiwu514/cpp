#include <iostream>

using namespace std;
const int N = 5010;

int a[N];

int find(int x)
{
    if (a[x] != x)
        a[x] = find(a[x]);
    return a[x];
}

bool query(int x, int y)
{
    if (find(x) == find(y))
        return true;
    else
        return false;
}
int main()
{
    int n, m, p, u, uu;
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (m--)
    {
        scanf("%d%d", &u, &uu);
        a[find(uu)] = find(u);
    }
    while (p--)
    {
        scanf("%d%d", &u, &uu);
        if (query(u, uu))
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}