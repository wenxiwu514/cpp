#include <iostream>
#include <set>

using namespace std;
set<int> s;
int main()
{
    int n, a, b, res;
    cin >> n;
    while (n--)
    {
        scanf("%d%d", &a, &b);
        if (a == 1)
        {
            if (s.count(b))
                printf("Already Exist\n");
            else
                s.insert(b);
        }
        else
        {
            if (s.empty())
                printf("Empty\n");
            else
            {
                auto lb = s.lower_bound(b);
                if (lb == s.begin())
                    res = *lb;
                else if (lb == s.end())
                    res = *(--lb);
                else
                {
                    int c = *lb;
                    int d = *(--lb);
                    res = (c - b) < (b - d) ? c : d;
                }
                printf("%d\n", res);
                s.erase(res);
            }
        }
    }
    return 0;
}