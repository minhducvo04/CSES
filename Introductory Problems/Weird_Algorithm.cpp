#include <bits/stdc++.h>

using namespace std;
long long n;
int main()
{
    cin >> n;
    while(n > 1){
        cout << n << " ";
        if(n % 2){
            n = n * 3 + 1;
        }
        else{
            n /= 2;
        }
        
    }
    cout << n << " ";
    return 0;
}
