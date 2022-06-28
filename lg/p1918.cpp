#include <iostream>
#include <map>
using namespace std;
map<int, int> mp;
int main()
{
    int n, m, k;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        mp[k] = i;
    }
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &k);
        printf("%d\n", mp[k]);
    }
    return 0;
}

// bin_search
// #include <iostream>
// #include <algorithm>
// using namespace std;

// typedef pair<int, int> PII;

// PII p[100100];

// bool cmp(PII a, PII b)
// {
//     return a.first < b.first;
// }

// int binsearch(int l, int r, int k)
// {
//     while (l <= r)
//     {
//         int mid = l + r >> 1;
//         if (p[mid].first < k)
//             l = mid + 1;
//         else
//             r = mid - 1;
//     }
//     return p[l].first == k ? p[l].second : 0;
// }
// int main()
// {
//     int n;
//     scanf("%d", &n);
//     for (int i = 0; i < n; i++)
//     {
//         scanf("%d", &p[i].first);
//         p[i].second = i + 1;
//     }
//     sort(p, p + n);
//     int m;
//     scanf("%d", &m);
//     while (m--)
//     {
//         int k;
//         scanf("%d", &k);
//         printf("%d\n", binsearch(0, n - 1, k));
//     }
//     return 0;
// }