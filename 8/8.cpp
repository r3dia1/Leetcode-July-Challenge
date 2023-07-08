#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    long long putMarbles(vector<int>& v, int k) {
        priority_queue<int>pq1;
        priority_queue<int, vector<int>, greater<int>>pq2;

        for(int i=0;i<v.size()-1;i++){
            pq1.push(v[i]+v[i+1]);
            pq2.push(v[i]+v[i+1]);
            if(pq1.size()>k-1){
                pq1.pop();
                pq2.pop();
            }
        }

        long long int ans1=0, ans2=0;

        while(!pq1.empty()){
            ans1 += pq1.top();
            ans2 += pq2.top();
            pq1.pop();
            pq2.pop();
        }
        
        return ans2-ans1;
    }
};

int main()
{
    Solution test;
    vector<int> v = {1,3,5,1};
    int ans = test.putMarbles(v, 2);
    cout << "ans = " << ans << endl;
}