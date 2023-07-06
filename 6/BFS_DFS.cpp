#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool flag = false;
    vector<int> continuous_check;
    int minSubArrayLen(int target, vector<int>& nums) {
        // Using binary search method to reduce dfs's branches.
        int left = 0;
        int right = nums.size();
        int sum;
        int count;
        
        while(left <= right)
        {
            sum = 0;
            count = 0;
            continuous_check.clear();
            int mid = left + (right-left)/2;
            //cout << "mid = " << mid << endl;

            if(dfs(target, nums, mid, 0, sum, count))
            {
                right = mid;
                if(right == left)
                    break;
            }
            else
                left = mid + 1;
        }
        if(flag == false)
            return 0;
        
        return right;
    }

    bool dfs(int target, vector<int> nums, int limit, int curn, int& sum, int& count)
    {
        cout << "sum = " << sum << endl;
        cout << "current number = " << curn << endl;
        cout << "check array = ";
        for(auto it: continuous_check)
            cout << it << " ";
        cout << endl;

        if(curn == nums.size())
        {
            //cout << "end\n";
            if(sum >= target && count <= limit)
            {
                cout << "Found!\n";
                return true;
            }
            else
                return false;
        }
        
        if((curn != 0) && (continuous_check[curn-1] == 1))
        {
            continuous_check.push_back(1);

            sum += nums[curn];
            count += 1;
            if(sum >= target && count <= limit)
            {
                flag = true;
                cout << "Found!\n";
                return true;
            }

            // cout << "1\n";
            if(dfs(target, nums, limit, curn + 1, sum, count))
                return true;

            continuous_check.pop_back();
            sum -= nums[curn];
            count -= 1;

            return false;
        } 
        else
        {
            continuous_check.push_back(0);

            // cout << "0\n";
            if(dfs(target, nums, limit, curn + 1, sum, count))
                return true;

            continuous_check.pop_back();
            continuous_check.push_back(1);

            sum += nums[curn];
            count += 1;
            if(sum >= target && count <= limit)
            {
                flag = true;
                //cout << "Found!\n";
                return true;
            }

            // cout << "1\n";
            if(dfs(target, nums, limit, curn + 1, sum, count))
                return true;

            continuous_check.pop_back();
            sum -= nums[curn];
            count -= 1;

            return false;
        }
    }
};

int main()
{
    Solution test;
    vector<int> nums = {2,3,1,2,4,3};
    int result = test.minSubArrayLen(7, nums);
    cout << "ans = " << result << endl;
}