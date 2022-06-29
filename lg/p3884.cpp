#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;

int h[N], e[N], ne[N], idx;

void insert(int x, int y)
{
    e[idx] = y;
    ne[idx] = h[x];
    h[x] = idx++;
}
int dfs1(int x)
{
    int p = 1;
    if (h[x] == -1)
        return 1;
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int k = dfs1(e[i]);
        if (k > p)
            p = k;
    }
    return p + 1;
}
int main()
{
    int n;
    cin >> n;
    int a, b;
    memset(h, -1, sizeof(h));
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        insert(a, b);
        insert(b, a);
    }
    int c, d;
    scanf("%d%d", &c, &d);
    cout << dfs1(1) << endl;
    return 0;
}

// TODO