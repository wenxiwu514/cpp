#include<iostream>

using namespace std;
int a[33];
int main(){
    int t,n;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &a[i]);
        }
        int flag = 0;
        if(n == 1) flag = 0;
        else{
            if(a[n-1] == 0) flag = -1;
            else{
                for(int i = n-2; i>=0; i--){
                    while(a[i]>=a[i+1]&&a[i]){
                        a[i] /= 2;
                        flag += 1;
                    }
                    if((a[i]==0)&&(i!=0)){
                        flag = -1;
                        break;
                    }
                }
            }
        }
        printf("%d\n", flag);
    }
    return 0;
}