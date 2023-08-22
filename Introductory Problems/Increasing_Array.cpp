#include <bits/stdc++.h>

using namespace std;
long long n, m, start, ans = 0;
int main(){
    cin >> n;
    cin >> start;
    for( int i = 0; i < n - 1; i++ ){
        cin >> m;
        ans += start - min(m, start);
        start = max(m, start);
    }
    cout << ans;
    return 0;
}
