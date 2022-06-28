#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[1000][1000];
int ll[555], rr[1000];
int main(){
    int t, n, m;
    scanf("%d", &t);
    while(t--){
        memset(a, 0, sizeof(a));
        memset(ll, 0, sizeof(ll));
        memset(rr, 0, sizeof(rr));
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++)
                scanf("%d", &a[i][j]);
        }
        for(int i = 0; i < m + n - 1; i ++){
            for(int j = 0; j < m + n - 1; j ++){
                ll[i] += a[j][m+n-1-j];
                printf("%d ", ll[i]);
            }
        }
        printf("\n");
        for(int i = 1 - m; i < n; i ++){
            for(int j = 0; j < m + n - 1; j ++){
                ll[i+500] += a[j][j - i];
                printf("%d ", ll[i+500]);
            }
        }
        printf("\n");
    }
    return 0;
}