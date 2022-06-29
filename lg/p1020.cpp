#include <iostream>
#include <cstring>
using namespace std;
int a[1000000], f[1000000], s[1000000];
int main()
{
    int i = 0, ans = 0;
    cin.tie(0);
    while (cin >> a[++i])
        ;
    for (int j = 1; j <= i; j++)
    {
        f[j] = 1;
        int l = 0, r = ans + 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (s[mid] >= a[j])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        f[j] = l + 1;
        s[f[j]] = a[j];
        ans = max(ans, f[j]);
    }
    cout << ans << endl;
    ans = 0;
    memset(s, 0, sizeof(s));
    for (int j = 1; j <= i; j++)
    {
        f[j] = 1;
        int l = 0, r = ans + 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (s[mid] < a[j])
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        f[j] = l + 1;
        s[f[j]] = a[j];
        ans = max(ans, f[j]);
    }
    cout << ans << endl;
    return 0;
}