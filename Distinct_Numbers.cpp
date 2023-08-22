#include <bits/stdc++.h>
using namespace std;

set <int> val;
int n, m;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        val.insert(m);
    }
    cout << val.size();
    return 0;
}
