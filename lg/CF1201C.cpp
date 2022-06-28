#include <iostream>
#include <algorithm>

using namespace std;
long long a[200010], n, k;
int main()
{
    scanf("%d%d", &n, &k);
    for (long long i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    long long index = n >> 1, j = 0;
    long long res = a[index];
    while (index < n)
    {
        long long t = (a[index + 1] - a[index]) * (index + 1 - (n >> 1));
        index++;
        if (t + j > k)
            break;
        else
        {
            j += t;
            res += (a[index] - a[index - 1]);
        }
    }
    res += (k - j) / (index - (n >> 1));
    printf("%d ", res);
    int ssd = 1;
    return 0;
}