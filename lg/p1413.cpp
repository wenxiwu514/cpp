#include <iostream>

using namespace std;

int g[101][101], c, r, f[101][101];

int dfs(int x, int y)
{
    if (f[x][y])
        return f[x][y];
    int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    int res = 1;
    int md = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && g[nx][ny] < g[x][y])
        {
            md = max(md, dfs(nx, ny));
        }
    }
    f[x][y] = md + res;
    return res + md;
}
int main()
{
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &g[i][j]);
        }
    }
    int res = 0, t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            t = dfs(i, j);
            res = max(res, t);
        }
    }
    cout << res;
    return 0;
}