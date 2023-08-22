#include <bits/stdc++.h>
using namespace std;

// vector <vector <int>> val;
const int N = 1e6;
vector <int> val, col;
// int cntS[N] , cntE[N];
map <int, int> cntS, cntE;
int n, m, k, inp, ans = 0, check = 0;
set <int> temp;

int BS_UP(int l, long long search){
    int mid, left = l, right = val.size() - 1;
    if(search <= val[left]){
        // cout << "CHECK UP 1: " << search << " -> " << " " << left << " " << val[left] << endl;
        // cout << left << endl;
        return left;
    }
    if(search >= val[right]){
        // cout << "CHECK UP 2: " << search << " -> " << " " << right << " " <<  val[right] << endl;
        // cout << right << endl;
        return right;
    }
    // while(val[right] > search){
    while(left < right && left >= 0){
        mid = (left + right) / 2;
        if(val[mid] < search){
            // save = mid;
            // cout << "DOING " << left << " " << mid << " " << right << " " << val[left] << " " << val[mid] << " " << val[right] << endl;
            left = mid + 1;
        }
        else{ 
            // cout << "DOING " << mid << endl;
            right = mid - 1;
        }
    }
        // if(val[save - 2] < search && val[save - 1] > search && save > 1){
        //     cout << "YEAH :" << val[save] << endl;
        //     save--;
        //     break;
        // }
    //     right = save - 1;
    //     left = 0;
    // }
    // if(save == -1){
    //     cout << "CHECK UP 3: " << search - k << " -> " << " " << val[left] << " " << val[right] << endl;
    //     cout << left << endl;
    //     return left;
    // }
    // cout << search << " : " << left << " -> " << val[left] << endl;
    while(val[left] < search && left < val.size() - 1){
        left++;
        // cout << search << " : " << left << " -> " << val[left] << endl;
    }
    if(left >= val.size()){
        left = val.size() - 1;
    }
    while(val[left] == val[left - 1] && left > l){
        left--;
    }
    // cout << "CHECK UP 4: " << search << " -> " << " " << left << " " << val[left] << endl;
    // cout << save << endl;
    return left;
}

int main() {
    int cnt = 0, pos = 0;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        cin >> inp;
        temp.insert(inp);
        if(cntS.count(inp) == 0){
            cntS[inp] = 0;
        }
        // val.push_back(inp);
        cntS[inp]++;
    }
    // cout << temp.size() << endl;
    copy(temp.begin(), temp.end(), back_inserter(val));
    temp.clear();
    // sort(val.begin(), val.end());
    for(int i = 0; i < m; i++){
        cin >> inp;
        temp.insert(inp);
        if(cntE.count(inp) == 0){
            cntE[inp] = 0;
        }
        // col.push_back(inp);
        cntE[inp]++;
        // if((inp - val[0] + k) * (val[val.size() - 1] + k - inp) >= 0){
        // cout << val[BS_UP(inp - k)] << " " << inp - k << " ||| " << val[BS_DOWN(inp + k)] << " " << inp + k << endl;
        // if(val[BS_UP(inp - k)] >= inp - k && val[BS_DOWN(inp + k)] <= inp + k && val[BS_UP(inp - k)] <= val[BS_DOWN(inp + k)]){
            // cout << s[BS_UP(inp - k)] << " " << e[BS_DOWN(inp + k)] << endl;
            // s[BS_UP(inp - k)] += 1;
            // e[BS_DOWN(inp + k)] += 1;
            // cout << inp << "-> " << val[BS_UP(inp - k)] << " at " << BS_UP(inp - k) << ": " << s[BS_UP(inp - k)] << ", " << val[BS_DOWN(inp + k)] << " at " <<BS_DOWN(inp + k) << ": " << e[BS_DOWN(inp + k)] << endl;
        // }
        // BS_DOWN(inp + k);
        // BS_UP(inp - k);
    }
    // cout << temp.size() << endl;
    copy(temp.begin(), temp.end(), back_inserter(col));
    // sort(col.begin(), col.end());
    // for(auto j : val){
    //     cout << " " << j << " ";
    // }
    // cout << endl;
    // for(auto j : col){
    //     cout << " " << j << " ";
    // }
    // cout << endl;
    // int start = -1, end;
    // set <int> rep;
    for(int i = 0; i < m; i++){
        check = BS_UP(pos, col[i] - k);
        // cout << check << ": " << val[check] << endl;
        if(cntE[col[i]] == 1){
            if(val[check] >= col[i] - k && val[check] <= col[i] + k && check >= pos && check < val.size()){
                if(cntS[val[check]] == 1){
                    pos = check + 1;
                }
                else{
                    // cout << val[check] << " " << cntS[val[check]] << endl;
                    pos = check;
                    cntS[val[check]]--;
                }
                cnt++;
            }
        }
        else{
            while(cntE[col[i]] > 0 && cntE[col[i]] >= cntS[val[check]] && val[check] >= col[i] - k && val[check] <= col[i] + k && check >= pos && check < val.size()){
                // cout << "LOOP: " << check << ": " << val[check] << endl;
                // if(start == -1){
                //     start = val[check];
                // }
                // rep.insert(val[check]);
                cnt += cntS[val[check]];
                cntE[col[i]] -= cntS[val[check]];
                check++;
                pos = check;
                // end = val[check];
            }
            // if()
            if(cntE[col[i]] > 0 && val[check] >= col[i] - k && val[check] <= col[i] + k && check >= pos && check < val.size()){

                    // rep.insert(val[check]);
                    cnt += cntE[col[i]];
                    cntS[val[check]] -= cntE[col[i]];
                    pos = check;
                    // end = val[check];
                    // if(start == -1){
                    //     start = val[check];
                    // }
                // }
            }
        }
        // }
    }
    // cout << start << " -> " << cntS[start] << endl;
    // cout << end << " -> " << cntS[end] << endl;
    // for(int i : rep){
    //     cout << i << " ";
    // }
    // for(int i = 0; i < n; i++){
    //     check += s[i];
    //     // cout << i << " " << check << endl;
    //     if(check > 0){
    //         ans++;
    //     }
    //     // if(ans >= e[i]){
    //     // cout << " " << e[i] << " " << ans << endl;
    //     cnt += min(e[i], ans);
    //     check -= min(e[i], check);
    //     ans = max(0, ans - e[i]);
    //     // cout << i << " " << cnt << " " << ans << " " << check << " " << s[i] << " " << e[i] << endl;
    // }
    // long long sum = 0;
    // for(int i : numS){
    //     cout << i << " -> " << s[i] << " and " << e[i] << endl;
    //     sum += min(s[i], e[i]);
    // }
    cout << cnt;
    return 0;
}