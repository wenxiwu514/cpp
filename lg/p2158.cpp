#include <cstdio>
using namespace std;
#define f(a, b, c, d) for (int a = b, c = d; a <= c; a++)
int ans(int n)
{
    if (n == 1)
        return 0;
    int prime[40010] = {0}, cnt = 0, fc[40010] = {0}, phi[40010] = {0};
    phi[1] = 1;
    f(i, 2, I, n - 1)
    {
        if (fc[i] == 0)
        {
            prime[++cnt] = i;
            fc[i] = i;
            phi[i] = i - 1;
        }
        f(j, 1, J, cnt) if (prime[j] * i > n || prime[j] > fc[i]) break;
        else
        {
            fc[prime[j] * i] = prime[j];
            if (prime[j] < fc[i])
                phi[prime[j] * i] = (prime[j] - 1) * phi[i];
            else
                phi[prime[j] * i] = prime[j] * phi[i];
        }
        phi[i] += phi[i - 1];
    }
    return (phi[n - 1] << 1 | 1);
}
int main()
{
    int n;
    scanf("%d", &n);
    printf("%d", ans(n));
    return 0;
}