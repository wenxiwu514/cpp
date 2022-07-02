#include <bits/stdc++.h>
using namespace std;
#define open(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#define LL long long

char S[1 << 25];
int p;
LL a, m, b, ans(1), t;

void read(LL &x, int len = 0x7f7f7f7f)
{
    x = 0;
    while (!isdigit(S[p]))
        p++;
    while (isdigit(S[p]) && len--)
        x = x * 10 + (S[p] ^ '0'), p++;
}

void Pow(LL &x, LL k)
{
    LL ans(1);
    while (k)
    {
        if (k & 1)
            ans = (ans * x) % m;
        x = (x * x) % m;
        k >>= 1;
    }
    x = ans;
}

int main()
{
    //	open( "1" );
    fread(S, 1, 1 << 25, stdin);
    read(a);
    read(m);
    while (!isdigit(S[p]))
        p++;
    while (isdigit(S[p + 16]))
    {
        Pow(ans, (LL)1e16);
        read(b, 16);
        t = a;
        Pow(t, b);
        ans = (ans * t) % m;
    }
    t = p;
    read(b);
    t = p - t;
    while (t--)
        Pow(ans, 10);
    Pow(a, b);
    ans = (ans * a) % m;
    printf("%lld\n", ans);
    return 0;
}
