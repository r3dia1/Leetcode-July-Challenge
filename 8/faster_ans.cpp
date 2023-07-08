class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        vector<long long> partition(n - 1); // Store score increment for a partition
        for(int i = 1; i < n; i++)
            partition[i - 1] = weights[i] + weights[i - 1];
        sort(partition.begin(), partition.end()); 
        long long ans = 0;
        for(int i = 0; i < k - 1; i++)
            ans += partition[n - 2 - i] - partition[i];
        return ans;
    }
};