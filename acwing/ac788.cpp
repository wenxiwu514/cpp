#include <iostream>

using namespace std;

int a[100010], tmp[100010];

long long merge_s(int q[], int l, int r)
{
    if (l >= r)
        return 0;
    // if (l + 1 == r)
    //     return (a[l] > a[r]) ? 1 : 0;
    int mid = (l + r) >> 1;
    long long res;
    res = merge_s(q, l, mid) + merge_s(q, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
    {
        if (q[i] <= q[j])
        {
            tmp[k++] = q[i++];
        }
        else
        {
            res += mid - i + 1;
            tmp[k++] = q[j++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = q[i++];
    }
    while (j <= r)
    {
        tmp[k++] = q[j++];
    }
    for (int i = l, j = 0; i <= r; i++, j++)
        q[i] = tmp[j];
    return res;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    cout << merge_s(a, 0, n - 1) << endl;
    return 0;
}