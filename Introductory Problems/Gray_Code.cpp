#include <bits/stdc++.h>
using namespace std;

long long pow(long long m){
    if(m == 1){
        return 2;
    }
    else if(m == 0){
        return 1;
    }
    else{
        long long ans = pow(m / 2);
        return (ans * ans * pow(m % 2));
    }
}

int main() {
    int n, stop = 0;
    queue <pair <string, int>> Q;
    cin >> n;
    Q.push(make_pair("", 0));
    while(stop < n){
        pair <string, int> val = Q.front();
        if(val.first.size() < n){   
            Q.pop();
            if(val.second % 2 == 0){
                Q.push(make_pair(val.first + '0', val.second));
                Q.push(make_pair(val.first + '1', val.second + 1));
            }
            else{
                Q.push(make_pair(val.first + '1', val.second + 1));
                Q.push(make_pair(val.first + '0', val.second));
            }
        }
        else{
            if(val.first.size() == n){
                stop++;
            }
        }
    }
    while(!Q.empty()){
        cout << Q.front().first << endl;
        Q.pop();
    }
    return 0;
}

