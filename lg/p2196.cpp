#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 22;

int a[N], b[N][N], f[N], q[N];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n - 1; i ++)
        for(int j = i + 1; j <= n; j ++)
            scanf("%d", &b[i][j]);
    for(int i = 1; i <= n; i ++){
        for(int j = i + 1; j <= n; j ++){
            if(b[i][j] && f[i] < f[j] + a[i])
                q[i] = j;
            f[i] = f[q[i]] + a[i];
        }
    }
    vector<int> path(1, k);
    int k = max_element(f, f + n) - f;
    while(q[k]){
        k = q[k];
        path.push_back(k);
    }
    reverse(all(path));
    for(auto i:path)
        printf("")
}