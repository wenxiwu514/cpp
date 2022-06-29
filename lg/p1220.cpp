#include <iostream>
#include <cstring>

using namespace std;
int d[55], p[55], n, x, f[55][55][2];

int cal(int i, int j, int l, int r)
{
    return (d[j] - d[i]) * (p[l] + p[n] - p[r - 1]);
}
int main()
{
    scanf("%d%d", &n, &x);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &d[i], &p[i]);
        p[i] += p[i - 1];
    }
    memset(f, 0x3f, sizeof(f));
    f[x][x][0] = f[x][x][1] = 0;
    for (int i = x; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            f[i][j][0] = min(f[i + 1][j][0] + cal(i, i + 1, i, j + 1), f[i + 1][j][1] + cal(i, j, i, j + 1));
            f[i][j][1] = min(f[i][j - 1][0] + cal(i, j, i - 1, j), f[i][j - 1][1] + cal(j - 1, j, i - 1, j));
        }
    }
    cout << min(f[1][n][0], f[1][n][1]);
    return 0;
}