#include <iostream>

using namespace std;
int a[100010];

void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1, j = r + 1, x = a[(l + r) >> 1];
    while (i < j)
    {
        do
            i++;
        while (a[i] < x);
        do
            j--;
        while (a[j] > x);
        if (i < j)
            swap(a[i], a[j]);
    }
    quick_sort(l, j);
    quick_sort(j + 1, r);
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quick_sort(0, n - 1);
    cout << a[k - 1] << endl;
    return 0;
}