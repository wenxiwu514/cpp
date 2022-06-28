#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[150100];
int b[150010];


int cmp1(int a,int b)
{
    return b<a;
}

int find_first_larger_than_k(int a[], int n, int k){
    int l = 0, r = n - 1;
    while(l < r){
        int mid = (l + r) >> 1;
        if(a[mid] >= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main(){
    int t, n, q;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &q);
        for(int i = 1; i <= n; i ++){
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1, cmp1);
        // for(int i = 1; i <= n; i ++){
        //     printf("%d ", a[i]);
        // }
        for(int i = 1; i <= n; i ++){
            b[i] = b[i - 1] + a[i];
        }
        while(q--){
            int query;
            scanf("%d", &query);
            int ans = find_first_larger_than_k(b , n + 1, query);
            if(ans == n && b[n] < query) ans = -1;
            printf("%d\n", ans);
        }
    }
    return 0;
}