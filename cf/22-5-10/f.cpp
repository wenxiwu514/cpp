#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int a[200100];
int b[200010];




int main(){
    int t, n, k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n; i ++){
            scanf("%d", &a[i]);
        }
        sort(a, a + n);

        int n1 = unique(a, a + n) - a;
        for(int i = 0; i < n; i ++){
            printf("%d ", a[i]);
        }
    }
    return 0;
}