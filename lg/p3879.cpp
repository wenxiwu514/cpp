#include <bits/stdc++.h>

using namespace std;

map<string, set<int>> mp;

int main()
{
    int n, m;
    string s;
    scanf("%d", &n);
    for (int j = 1; j <= n; j++)
    {
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            cin >> s;
            mp[s].insert(j);
        }
    }
    scanf("%d", &n);
    while (n--)
    {
        cin >> s;
        for (auto in : mp[s])
            printf("%d ", in);
        puts("");
    }
    return 0;
}