#include <bits/stdc++.h>

using namespace std;
long long n;
const long long C = 1e9 + 7;

long long pow(long long m){
    if(m == 1){
        return 2;
    }
    else if(m == 0){
        return 1;
    }
    else{
        long long val = pow(m / 2);
        return (val * val * pow(m % 2)) % C;
    }
}

int main(){
    cin >> n;
    cout << pow(n);
    return 0;
}