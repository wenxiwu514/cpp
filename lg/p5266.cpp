#include <iostream>
#include <map>
using namespace std;
map<string, int> mp;
int main()
{
    int n, c, op;
    string s;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            cin >> s >> c;
            mp[s] = c;
            printf("OK\n");
        }
        else if (op == 2)
        {
            cin >> s;
            if (mp.count(s))
                printf("%d\n", mp[s]);
            else
                printf("Not found\n");
        }
        else if (op == 3)
        {
            cin >> s;
            if (mp.count(s))
            {
                printf("Deleted successfully\n");
                mp.erase(s);
            }
            else
                printf("Not found\n");
        }
        else
        {
            printf("%d\n", mp.size());
        }
    }
    return 0;
}