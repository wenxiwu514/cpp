#include <iostream>
#include <cstring>
using namespace std;
int a[333], f[333][333], s[333][333];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    memset(f, 0x3f, sizeof(f));

    for (int i = 1; i <= n; i++)
    {
        f[i][i] = 0;
        s[1][i] = s[1][i - 1] + a[i];
        for (int j = 2; j <= i; j++)
        {
            s[j][i] = s[1][i] - s[1][j - 1];
        }
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            for (int k = j; k <= j + i - 1; k++)
            {
                f[j][j + i - 1] = min(f[j][j + i - 1], f[j][k] + f[k + 1][j + i - 1] + s[j][j + i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}