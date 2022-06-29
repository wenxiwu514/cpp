#include <iostream>

using namespace std;

int a[301], f[101][101], s[301][301], n, k;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        a[i] = a[i + n] = k;
    }
    int md = 0;
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = i - 1; i - j < n && j >= 1; j--)
        {
            for (int k = j; k < i; k++)
                s[j][i] = max(s[j][i], s[j][k] + s[k + 1][i] + a[j] * a[k + 1] * a[i + 1]);
            md = max(md, s[j][i]);
        }
    }
    cout << md;
    return 0;
}