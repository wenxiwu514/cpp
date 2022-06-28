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
        scanf("%d%d", &n, &m);
        memset(ll, 0, sizeof(ll));
        memset(rr, 0, sizeof(rr));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < m; j ++){
                scanf("%d", &a[i][j]);
                ll[i + j] += a[i][j];
                rr[i - j + 250] += a[i][j];
            }
        }

        int ld = 0, rd = 1 - m;
        for(int i = 0; i < n + m - 1; i ++){
            // printf("%d ", ll[i]);
            if(ll[i] > ll[ld])
                ld = i;
        }
        // puts("");
        for(int i = 1 - m; i < n; i ++){
            // printf("%d ", rr[i + 250]);
            if(rr[i+250] > rr[rd+250])
                rd = i;
        }
        // puts("");
        // printf("%d\n", ll[ld] + rr[rd+250]);
        int sum = 0;
        int x = 0, y = 0;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < m; j ++){
                int ttt = ll[i + j] + rr[i - j + 250] - a[i][j];
                if(ttt> sum){
                    sum = ttt;
                }
            }
        printf("%d\n", sum);
    }
    return 0;
}