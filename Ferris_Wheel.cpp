#include <bits/stdc++.h>
using namespace std;

// vector <vector <int>> val;
// const int N = 1e6;
vector <int> val;
// int cntS[N] , cntE[N];
// map <int, int> cntS, cntE;
int n, x, temp, cnt;
set <int> done;

int BS(int l, int r, long long search){
    if(search < val[l]){
        // cout << "COMPARE: "<< search << " < " << val[l] << endl;
        return -1;
    }
    int left = l, right = r, mid = 0, save = -1;
    while(done.count(right) || save != right){
        // first = false;
        // cout << right << endl;
        save = right;
        while(left < right){
            mid = (left + right) / 2;
            if(val[mid] < search){
                left = mid + 1;
            }
            else if(val[mid] > search){
                right = mid - 1;
            }
            else{
                return mid;
            }
        }
        if(done.count(right)){
            if(right == 0){
                return -1;
            }
            right--;
        }
        if(val[right] > search){
            right--;
        }
        left = l;
    }
    // cout << "OUTPUT: " << right;
    return right;
}

int main() {
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> temp;
        val.push_back(temp);
    }
    sort(val.begin(), val.end());
    // for(int i = 0; i < 13; i++){
    //     cout << i << " -> " << BS(0, val.size() - 1, i) << " " << val[BS(0, val.size() - 1, i)] << endl;
    // }
    int pos = val.size() - 1, sum, num, l = 0, check;
    while(l <= pos){
        sum = x;
        // cout << pos << " " << val[pos] << endl;
        sum -= val[pos];
        pos--;
        // cout << sum << endl;
        // if(sum >= val[pos]){
        //     done.insert(pos);
        //     sum -= val[pos];
        //     pos--;
        //     // cout << sum << endl;
        // }
        // else{
            // num = BS(l, pos, sum);
            // cout << num << " " << val[num] << endl;
        if(sum >= val[l] && l <= pos){
            l++;
            // done.insert(num);
            // check--;
            // if(num == l && l <= pos){
            //     l++;
            //     while(done.count(l) && l <= pos){
            //         l++;
            //     }
            // }
            // // cout << sum << endl;
            // // cout << sum << " lost " << val[num] << endl;
            // sum -= val[num];
        }
        // }
        // cout << sum << endl;
        cnt++;
        // check = 2;
        // while(sum >= val[pos] && pos >= 0 && check > 0){
        //     // cout << sum << " lost " << val[pos] << endl;
        //     done.insert(pos);
        //     sum -= val[pos];
        //     pos--;
        //     check--;
        // }
        // if(pos < 0){
        //     // cout << "VAL: " << pos << endl;
        //     cnt++;
        //     break; 
        // }
        // cout << sum << ", " << l << ", " << pos << ": " << BS(l, pos, sum) << endl;
        // while(sum >= val[l] && l <= pos && check > 0){
        //     num = BS(l, pos, sum);
        //     if(num != -1){
        //         done.insert(num);
        //         check--;
        //         if(num == l && l <= pos){
        //             l++;
        //             while(done.count(l) && l <= pos){
        //                 l++;
        //             }
        //         }
        //         // cout << sum << " lost " << val[num] << endl;
        //         sum -= val[num];
        //     }
        //     else{
        //         break;
        //     }
        // } 
    }
    cout << cnt;
    // cout << BS(0, val.size() - 1, )
    return 0;
}