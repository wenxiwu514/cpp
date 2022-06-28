#include <iostream>
#include <set>
using namespace std;

int get_hash(string s)
{
    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res = (long long)(res * 131 + s[i]) % 0x3f3f3f3f;
    return res;
}
int main()
{
    int n;
    set<int> s1;
    scanf("%d", &n);
    while (n--)
    {
        string s;
        cin >> s;
        s1.insert(get_hash(s));
    }
    printf("%d", s1.size());
    return 0;
}