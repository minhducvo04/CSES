#include <bits/stdc++.h>
#include <algorithm>
#include <iterator>
using namespace std;

bool huyen[15], sac[15], row[8], col[8];
set <pair <int, int>> res;
int cnt = 0;
string str;

void DP(int now, bool hu[], bool sa[], bool ro[], bool co[]){
    for(int i = 0; i < 8; i++){
        if(!(hu[now - i + 7] || sa[now + i] || ro[now] || co[i] || res.count(make_pair(now, i)))){
            if(now < 7){
                bool copy_hu[15];
                bool copy_sa[15];
                bool copy_ro[8];
                bool copy_co[8];
                copy (hu, hu + 15, copy_hu);
                copy (sa, sa + 15, copy_sa);
                copy (ro, ro + 8, copy_ro);
                copy (co, co + 8, copy_co);
                copy_hu[now - i + 7] = true;
                copy_sa[now + i ] = true;
                copy_ro[now] = true;
                copy_co[i] = true;
                // cout << now + 1 << endl;
                // for
                DP(now + 1, copy_hu, copy_sa, copy_ro, copy_co);
            }
            else{
                cnt += 1;
            }
            // copy_hu[now - i + 7] = 
        }
        
    }
    // if(id != col.size() - 1){
    //     if(sum - (val + col[id]) * 2 >= -1 * ans){
    //         ans = min(ans, abs(sum - (val + col[id]) * 2));
    //         DP(id + 1, val + col[id]);
    //     }
    //     DP(id + 1, val);
    // }
}

int main() {
    for(int i = 0; i < 8; i++){
        cin >> str;
        for(int j = 0; j < 8; j++){
            if(str[j] == '*'){
                res.insert(make_pair(i, j));
            }
        }
    }
    DP(0, huyen, sac, row, col);
    cout << cnt;
    return 0;
}
