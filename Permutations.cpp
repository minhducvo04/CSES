#include <bits/stdc++.h>

using namespace std;
long long n;
int main(){
    cin >> n;
    if( n <= 3 && n != 1 ){
        cout << "NO SOLUTION";
    }
    else{
        for(int i = 0; i < n / 2; i++ ){
            cout << i * 2 + 2 << " ";
        }
        for(int i = 0; i < (n + 1) / 2; i++ ){
            cout << i * 2 + 1 << " ";
        }
    }
    return 0;
}