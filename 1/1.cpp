class Solution {
public:
    int distribution[8]; // distribution[i]: The # of cookies that i-th person get.
    int distributeCookies(vector<int>& cookies, int k) {

        // Using binary search method to reduce dfs's branches.
        int left = 1;
        int right = 0;
        for(int i = 0; i < cookies.size(); i++)
            right = right + cookies[i];
        
        while(left < right)
        {
            // Reset the distribution result
            for(int i=0; i<k; i++)
                distribution[i] = 0;

            // mid represent the ceiling of cookies each person can get
            int mid = left + (right-left)/2;

            // Using dfs to check if the ceiling is possible.
            // If it's possible than we can make the ceiling lower.
            // Else loose the ceiling
            if(dfs(cookies, k, mid, 0))
                right = mid;
            else
                left = mid + 1;
        }
        reutrn right;
    }

    bool dfs(vector<int>& cookies, int k, int ceiling, int cookie_idx)
    {
        // Check if the distribution is finish
        if(cookie_idx == cookies.size())
            return true;

        for(int i=0; i<k; i++)
        {
            // Check if it's legal for i-th person to get the current cookie.
            if(distribution[i] + cookies[cookie_idx] > ceiling)
                continue;
            
            distribution[i] += cookies[cookie_idx];
            
            // Go recursion to check the next cookie's distribution.
            if(dfs(cookies, k, ceiling, cookie_idx+1))
                return true;
            
            // Cause the distribution illegal so give the cookie to other people.
            distribution[i] -= cookies[cookie_idx];
        }

        // Can't find match distribution to the ceiling
        return false;
    }
};