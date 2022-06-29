#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 22;

int a[N], b[N][N], f[N], q[N];

void dfs(int x)
{
    if (q[x])
        dfs(q[x]);
    printf("%d ", x);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%d", &b[i][j]);
    int ans = 0, index = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = a[i];
        for (int j = 1; j < i; j++)
        {
            if (b[j][i] && f[i] < f[j] + a[i])
            {
                f[i] = f[j] + a[i];
                q[i] = j;
            }
        }
        if (f[i] > ans)
        {
            ans = f[i];
            index = i;
        }
    }
    dfs(index);
    cout << endl
         << ans << endl;
    return 0;
}