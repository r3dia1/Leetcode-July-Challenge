#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ans = 0;
    void dfs(vector<int>& nums, vector<int>& subarray, int curnum, int del)
    {
        //cout << "curnum = " << curnum << endl;
        if(curnum == nums.size())
        {
            if(ans < subarray.size())
                    ans  = subarray.size();
            subarray.clear();
            return;
        }

        if(curnum == del)
            dfs(nums, subarray, curnum + 1, del);
        else
        {
            if(nums[curnum] == 1)
            {
                subarray.push_back(1);
                /*for(auto iter : subarray)
                    cout << iter<< " ";
                cout << endl;*/
            }
            else
            {
                if(ans < subarray.size())
                    ans  = subarray.size();
                
                subarray.clear();
            }

            dfs(nums, subarray, curnum + 1, del);
        }
        
        return;
    }

    int longestSubarray(vector<int>& nums) {
        vector<int> subarray;
        for(int i=0; i<nums.size(); i++)
        {
            dfs(nums, subarray, 0, i);
            //cout << "ans = " << ans << endl;
            //cout << endl;
        }

        return ans;
    }
};

int main()
{
    Solution test;
    vector<int> nums={1, 1, 0, 1};
    test.longestSubarray(nums);
}