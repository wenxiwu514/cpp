#include<iostream>
#include<algorithm>
using namespace std;
const int N = 2e5 + 10;
string s;


int main(){
    int t,n,k;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        cin >> s;
        for(int i = 0; s[i]; i ++){
            int m = s[i] - 'a';
            while(m--){
                replace(s.begin(),s.end(),s[i],char(s[i]- 1)); k --;
                if(k == 0) break;
            }
            if(k == 0) break;
        }
        cout << s << endl;
    }
    return 0;
}