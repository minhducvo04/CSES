#include <bits/stdc++.h>

using namespace std;
long long n, m = 5, ans = 0;

int main(){
    cin >> n;
    while(m <= n){
        ans += n / m;
        m *= 5;
    }
    cout << ans;
    return 0;
}