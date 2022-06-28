#include<iostream>
#include<algorithm>
using namespace std;
int a[55];
const int N = 1e7+10;

int main(){
    int t,n,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        int min_ = 1e9;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            min_ = min(min_, a[i]);
        }
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += a[i] - min_;
        }
        printf("%d\n", sum);
    }
    return 0;
}