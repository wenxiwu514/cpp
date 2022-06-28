#include <iostream>

using namespace std;

const int N = 1010;

long long a[N][2], b[N], f[N];

int main()
{
    int n, x1;
    scanf("%d%d", &n, &x1);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld%lld", &a[i][0], &a[i][1], &b[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = x1; j >= 0; j--)
        {
            if (j >= b[i])
                f[j] = max(f[j] + a[i][0], f[j - b[i]] + a[i][1]);
            else
                f[j] = f[j] + a[i][0];
        }
    cout << 5 * f[x1];

    return 0;
}