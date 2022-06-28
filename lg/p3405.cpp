#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

map<int, int> m[200010];

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    while (n--)
    {
        string a, b;
        cin >> a >> b;
        int c, d;
        c = a[0] * 26 + a[1];
        d = b[0] * 26 + b[1];

        ans += m[d][c];
        if (c == d)
            ans -= m[c][d];
        m[c][d]++;
    }

    printf("%d", ans);
    return 0;
}