#include <bits/stdc++.h>

using namespace std;
long long n;


int main(){
    cin >> n;
    for(long long i = 1; i <= n; i++){
        if(i == 1){
            cout << 0 << endl;
        }
        else if(i == 2){
            cout << 6 << endl;
        }
        else if(i == 3){
            cout << 28 << endl;
        }
        else if(i == 4){
            cout << 96 << endl;
        }
        else{
            long long val = i * i;
            // cout << ((n - 4) * (n - 4) * (n * n - 8 - 1) << endl << (n - 4) * 4 * (n * n - 6 - 1) << endl << 4 * (n * n - 4 - 1) + 8 * (n * n - 3 - 1) << endl << 4 * (n * n - 2 - 1) << endl (n - 4) * 4 * (n * n - 4 - 1)) / 2;
            cout << ((i - 4) * (i - 4) * (val - 8 - 1) + (i - 4) * 4 * (val - 6 - 1) + 4 * (val - 4 - 1) + 8 * (val - 3 - 1) + 4 * (val - 2 - 1) + (i - 4) * 4 * (val - 4 - 1)) / 2 << endl;
        }
    }
    return 0;
}
