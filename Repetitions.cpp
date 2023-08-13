#include <bits/stdc++.h>

using namespace std;
long long ans = 0, num = 1;
string str;
int main(){
    cin >> str;
    char cur = ' ';
    for(auto s: str + ' '){
        if(s == cur){
            num += 1;
        }
        else{
            if(num > ans){
                ans = num;
            }
            cur = s;
            num = 1;
        }
    }
    cout << ans;
    return 0;
}