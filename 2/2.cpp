#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int ans = 0;

    //紀錄building是否保持balanced
    vector<int> check;

    //count變數代表選擇了幾個requests
    void recursive(int curr, int n, vector<vector<int>>& requests, int count) {

        //當檢查到最後一個request時，要做return
        if (curr == requests.size()) {
            //同時要檢查each building是否呈現balanced狀態
            //若是呈現balanced，則此request組合可以被納入答案
            if (all_of(check.begin(), check.end(), [](int element) { return element == 0; }))
                ans = max(ans, count);
            return;
        }
        //不納入當前request到組合裡面，直接往下一個request檢查
        recursive(curr + 1, n, requests, count);
        
        //選擇當前request納入組合
        check[requests[curr][0]]++;
        check[requests[curr][1]]--;

        //納入當前request到組合裡面，並往下一個request檢查
        recursive(curr + 1, n, requests, count + 1);

        //當前request無當前request無法讓當前組合達成balance，所以不採用
        check[requests[curr][0]]--;
        check[requests[curr][1]]++;
    }

    int maximumRequests(int n, vector<vector<int>>& requests) {
        check.resize(n);
        recursive(0, n, requests, 0); 
        return ans;
    }
};

int main(){
    //vector<vector<int>> requests{{1,2},{1,2},{2,2},{0,2},{2,1},{1,1},{1,2}};
    vector<vector<int>> requests{{0,0},{1,2},{2,1}};
    Solution a;
    int result = a.maximumRequests(3, requests);
    cout << result << endl;
}

