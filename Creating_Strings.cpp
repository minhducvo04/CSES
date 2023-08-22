#include <bits/stdc++.h>
using namespace std;

string s = "", str;
set <string> check, finish;

void add(string now, string future){
    if(now.size() < str.size()){
        for(int i = 0; i < future.size(); i++){
            // cout << "DOING: " << now << " " << future[i] << " " << check.count(now + future[i]) << endl;
            if(!check.count(now + future[i])){
                check.insert(now + future[i]);
                string f = future;
                add(now + future[i], f.erase(i, 1));
            }
        }
    }
    else{
        s += now + "\n";
        finish.insert(now);
        check.insert(now);
    }
}

int main() {
    cin >> str;
    sort(str.begin(), str.end());
    add("", str);
    cout << finish.size() << endl;
    cout << s;
    return 0;
}