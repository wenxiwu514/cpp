#include<iostream>

using namespace std;
string s;
int main(){
    int t,n,l;
    scanf("%d", &t);
    while(t--){
        cin >> s;
        l = s.length();
        if(l == 1)
            printf("1\n");
        else{
            int flag1 = 0, flag2 = 0;
            for(int i = 0; s[i]; i++, flag2++){
                if(s[i] == '1')
                    flag1 = i;
                else if(s[i] == '0'){
                    flag2 = i;
                    break;
                }
            }
            if(flag2 == l) flag2 = l-1;
            printf("%d\n", flag2 - flag1 + 1);
        }
    }
    return 0;
}