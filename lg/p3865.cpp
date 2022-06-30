#include <iostream>

using namespace std;

const int N = 100010, K = 17;

int a[N], st[N][K + 1], lg[N + 1];
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}

void pre(int n)
{
    lg[1] = 0;
    for (int i = 2; i <= N; i++)
        lg[i] = lg[i >> 1] + 1;
    for (int i = 0; i < n; i++)
        st[i][0] = a[i];
    for (int j = 1; j <= K; j++)
    {
        for (int i = 0; i + (1 << j) <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        a[i] = read();
    pre(n);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        l = read() - 1;
        r = read() - 1;
        int j = lg[r - l + 1];
        printf("%d\n", max(st[l][j], st[r - (1 << j) + 1][j]));
    }
    return 0;
}