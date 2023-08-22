#include <bits/stdc++.h>
using namespace std;

long long sum, m, ans = 2e10 + 1;
long long n;
vector <long long> col;

// void BS(vector <long long> list, long long val){
//     if(list.back() < val){
//         for(int i = 0; i < list.size(); i++){
//             vector <long long> temp = list;
//             temp.erase(temp.begin() + i);
//             cout << val << " " << i << endl;
//             for(long long j : temp){
//                 cout << j << "\n";
//             }
//             cout << "\n";
//             if(!past.count(temp)){
//                 past.insert(temp);
//                 // cout << "DOING: " << sum << " AND "<< val << " + " << i << " = "<< sum - 2 * (val + i) << " " << (-1 * ans) << endl;
//                 BS(temp, val - list[i]);
//             }
//         }
//     }
//     else{
//         cout << val << " " << list.back() << endl;
//         int mid, left = 0, right = list.size() - 1;
//         while(left < right){
//             mid = (left + right) / 2;
//             if(list[mid] < val){
//                 left = mid + 1;
//             }
//             else{
//                 right = mid;
//             }
//         }
//         ans = min(ans, val - list[left]);
//         past.insert(list);
//         for(long long i : list){
//             vector <long long> temp = list;
//             temp.erase(temp.begin() + left);
//             past.insert(temp);
//         }
//         // cout << list[left] << " " << list[mid] <<  " " << list[right];
//     }
// }

void DP(int id, long long val){
    if(id != col.size() - 1){
        if(sum - (val + col[id]) * 2 >= -1 * ans){
            ans = min(ans, abs(sum - (val + col[id]) * 2));
            DP(id + 1, val + col[id]);
        }
        DP(id + 1, val);
    }
}

int main() {
    sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> m;
        col.push_back(m);
        sum += m;
    }
    ans = abs(sum - m * 2);
    // sort(col.begin(), col.end());
    // cout << col.front() << " " << col.back() << endl;
    // BS(col, 18);
    // BS(col, sum / 2);
    DP(0, 0);
    cout << ans;
    return 0;
}