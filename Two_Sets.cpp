#include <bits/stdc++.h>

using namespace std;
long long n;


int main(){
    cin >> n;
    if(n % 4 == 0 || n % 4 == 3){
        cout << "YES" << endl;
        cout << (n + 1) / 2 << endl;
        for(int i = 1 + n / 4; i <= n * 3 / 4; i++){
            cout << i << " ";
        }
        cout << endl << n / 2 << endl;
        if(n % 2 == 0){
            for(long long i = 1; i <= n / 4; i++){
                cout << i << " ";
            }
        }
        else{
            for(long long i = 1; i <= n / 4; i++){
                cout << i << " ";
            }
        }
        for(long long i = n + 1 - (n + 1) / 4; i <= n; i++){
            cout << i << " ";
        }
        cout << endl;
    }
    else{
        cout << "NO";
    }
    return 0;
}