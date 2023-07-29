class Solution {
public:
    vector<vector<bool>> cache_exist;
    vector<vector<int>> cache;
    int getScore(int left, int right, vector<int> nums)
    {
        if(left == right)
            return nums[left];
        
        if(cache[left][right] != INT_MAX/1000)
            return cache[left][right];

        int pick_leftScore = nums[left] - getScore(left + 1, right, nums);
        int pick_rightScore = nums[right] - getScore(left, right - 1, nums);

        cache[left][right] = max(pick_leftScore, pick_rightScore);
        return cache[left][right];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        cache.resize(n, vector<int>(n, INT_MAX/1000));
        int res = getScore(0, n-1, nums);
        if(res >= 0)
            return true;
        else
            return false;
    }
};