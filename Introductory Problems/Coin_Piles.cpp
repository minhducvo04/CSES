#include <bits/stdc++.h>

using namespace std;
long long n, m, t;

int main(){
    cin >> t;
    for(long long i = 0; i < t; i++){
        cin >> n >> m;
        if((n + m) % 3 == 0 && n != 0 && m != 0 && (n - 1) / m < 2 && (m - 1) / n < 2){
            cout << "YES" << endl;
        }
        else{
            if(!(n || m))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
    return 0;
}
