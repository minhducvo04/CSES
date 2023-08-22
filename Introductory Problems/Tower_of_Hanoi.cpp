#include <bits/stdc++.h>
using namespace std;

string s = "";

int move(int num, int from, int temp, int to){
    int val = 0;
    if(num > 1){
        val += move(num - 1, from, to, temp);
        val += move(1, from, temp, to);
        val += move(num - 1, temp, from, to);
    }
    else{
        s += to_string(from) + " " + to_string(to) + "\n";
        return 1;
    }
    return val;
}

int main() {
    long long n;
    cin >> n;
    cout << move(n, 1, 2, 3) << endl;
    cout << s;
    return 0;
}
