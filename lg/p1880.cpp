#include <iostream>
#include <cstring>
using namespace std;

int a[222], f1[222][222], f2[222][222], s[222], n;
inline int ddd(int l, int r) { return s[r] - s[l - 1]; }

int main()
{
    scanf("%d", &n);
    memset(f1, 0x3f, sizeof(f1));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
        s[i] = s[i - 1] + a[i];
        f1[i][i] = 0;
    }
    for (int i = n + 1; i <= 2 * n; i++)
    {
        s[i] = s[i - 1] + a[i];
        f1[i][i] = 0;
    }
    for (int i = 2; i <= n; i++)
    { // 合并几堆石子
        for (int j = 1; j <= n * 2 - i; j++)
        {
            for (int k = j; k < j + i - 1; k++)
            {
                f1[j][j + i - 1] = min(f1[j][j + i - 1], f1[j][k] + f1[k + 1][j + i - 1] + ddd(j, j + i - 1));
                f2[j][j + i - 1] = max(f2[j][j + i - 1], f2[j][k] + f2[k + 1][j + i - 1] + ddd(j, j + i - 1));
            }
        }
    }
    int mi = 0x3f3f3f3f, mx = 0;
    for (int i = 1; i <= n; i++)
    {
        mi = min(mi, f1[i][i + n - 1]);
        mx = max(mx, f2[i][i + n - 1]);
    }
    printf("%d\n%d\n", mi, mx);
    return 0;
}