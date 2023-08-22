#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

vector <pair <long long, long long>> Dict;
int q;
long long s;

void BS(long long search){
    int mid, left = 0, right = Dict.size() - 1, save = 0;
    while(left < right){
        mid = (left + right) / 2;
        if(Dict[mid].first < search){
            left = mid + 1;
            save = mid;
        }
        else{
            right = mid;
        }
    }
    long long ans = Dict[save].second + (search - Dict[save].first - 1) / (save + 1);
    // ans = ans / (save + 1);
    // ans = Dict[save].second + ans - 1;
    long long pre = (search - Dict[save].first - 1)%(save + 1);
    long long more = ans;
    long long less = pre;
    while(pre < save){
        ans /= 10;
        pre++;
    }
    // cout << less << " " << save + 1 << " " << (search - Dict[save].first) / (save + 1) << " " << Dict[save].first << " " << Dict[save].second << " " << more << endl;
    cout << ans % 10 << endl;
}

int main() {
    string str  = "";
    long long val, mul;
    Dict. push_back(make_pair(0, 1));
    for(int i = 1; i < 18; i++){
        // cout << to_string(i) << endl;
        // str += to_string(i);
        if(i == 1){
            val = 9;
            mul = 10;
            // cout << val << " " << mul << endl;
        }
        else{
            val = val + mul * i * 9;
            mul *= 10;
            // cout << val << " " << mul << endl;
        }
        Dict.push_back(make_pair(val, mul));
    }
    // for(int i = 0; i < Dict.size(); i++){
    //     cout << Dict[i].first << " " << Dict[i].second << endl;
    // }
    cin >> q;
    for(int i = 0; i < q; i++){
        cin >> s;
        BS(s);
    }
    return 0;
}
