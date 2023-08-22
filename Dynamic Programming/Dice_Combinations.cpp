#include <bits/stdc++.h>
using namespace std;

const int N = 1e9 + 7;
int arr[1000003];
int n;
long long cnt = 0;

int DS(int val){
    arr[0] = 1;
    for(int i = 1; i <= val; i++){
        for(int j = 1; j < 7; j++){
            if(i - j >= 0){
                arr[i] = (arr[i] + arr[i - j]) % N;

            }
        }
    }

    return arr[val];
}

int main() {
    cin >> n;
    cout << DS(n);
    return 0;
}
