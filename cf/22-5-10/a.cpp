#include<iostream>
#include<algorithm>
using namespace std;
string s;


int main(){
    int t,n,k;
    scanf("%d", &t);
    while(t--){
        cin >> s;
        if(int(s[0] + s[1] + s[2]) == int(s[3] + s[4] + s[5]))
            puts("YES");
        else puts("NO");
    }
    return 0;
}