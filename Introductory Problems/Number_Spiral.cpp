#include <bits/stdc++.h>

using namespace std;
long long n, m, ans, t;

long long run(long long big, long long small, long long r){
    // cout << "DOING" << big << " " << small << " " << r << endl;
    if(big % 2 == r){
        return big * big + 1 - small;
    }
    else{
        return (big - 1) * (big - 1) + small;
    }
}

int main(){
    cin >> t;
    for(long long i = 0; i < t; i++){
        cin >> n >> m;
        if(max(n, m) == n){
            cout << run(n, m, 0) << endl;
        }
        else{
            cout << run(m, n, 1) << endl;
        }
    }
    return 0;
}
