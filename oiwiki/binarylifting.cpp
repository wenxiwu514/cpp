#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int a[N];
int go[70][N];
int sum[70][N];

int modadd(int a, int b)
{
    return (a + b >= mod) ? a + b - mod : a + b;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        go[0][i] = i + k % n + 1;
        sum[0][i] = a[i];
    }
    int logn = 31 - __builtin_clz(n);
    for (int i = 1; i <= logn; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            go[i][j] = go[i - 1][go[i - 1][j]];
            sum[i][j] = modadd(sum[i - 1][j], sum[i - 1][go[i - 1][j]]);
        }
    }
    long long m;
    scanf("%lld", &m);

    int ans = 0;
    int curx = 1;
    for (int i = 0; m; ++i)
    {
        if (m & (1 << i))
        { // 参见位运算的相关内容，意为 m 的第 i 位是否为 1
            ans = modadd(ans, sum[i][curx]);
            curx = go[i][curx];
            m ^= 1ll << i; // 将第 i 位置零
        }
    }

    printf("%d\n", ans);
}