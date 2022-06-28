#include <iostream>
#include <set>

using namespace std;

set<int> s;
int a[50010];

int main()
{
    int t, n, m;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        s.clear();
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &m);
            if (!s.count(m))
            {
                a[j++] = m;
                s.insert(m);
            }
        }
        for (int i = 0; i < j; i++)
            printf("%d ", a[i]);
        puts("");
    }
    return 0;
}