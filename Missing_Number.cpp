#include <bits/stdc++.h>

using namespace std;
long long n, m;
int main(){
    long long s, sum = 0;
    cin >> n;
    s = ((n + 1)*n)/2;
    for(int i = 0; i < n - 1; i++){
        cin >> m;
        sum += m;
    }
    cout << s - sum;
    return 0;
}