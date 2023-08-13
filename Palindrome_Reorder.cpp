#include <bits/stdc++.h>

using namespace std;
string A[26];

int main(){
    string str, ch = "", val = "";
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        A[str[i] - 'A'].push_back(str[i]);
    }
    for(int i = 0; i < 26; i++){
        if(A[i].size() % 2){
            char c = 'A' + i;
            ch += c;
        }
    }
    if(ch.size() >= 2){
        cout << "NO SOLUTION";
    }
    else{
        val = ch;
        for(int i = 0; i < 26; i++){
            str = A[i].substr(0, A[i].size() / 2);
            val = str + val + str;
        }
        cout << val;
    }
    return 0;
}