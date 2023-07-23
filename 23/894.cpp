/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    unordered_map<int, vector<TreeNode*>> dp;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        // FBT node總數不為偶數
        if(n % 2 == 0)
            return {};

        // 若是總node數 = n的FBTs已經被建立過，則直接回傳建立結果，不需要再建立一次。
        if(dp.find(n) != dp.end())
            return dp[n];

        // 若是node總數為1則建立dp[1]的結果，並回傳
        if(n == 1)
        {
            TreeNode* temp = new TreeNode(0);
            dp[1].push_back(temp);
            return dp[1];
        }

        // 此陣列用來儲存總node數 = n的FBTs
        vector<TreeNode*> ret;
        
        // 當node總數為n時的情況為: 左子樹的node總數可能有:1 ~ n-1個，同時右子樹可能有: n-1 ~ 0個
        for(int i=1; i<n; i+=2)
        {
            // 在建立完總node數為n時，左子樹和右子樹的所有可能陣列後
            // 用窮舉法去建立node數為n的的所有FBT組合
            for(auto l: allPossibleFBT(i))
                for(auto r: allPossibleFBT(n-i-1))
                {
                    // 此temp可以視為所有可能FBT的個別root
                    TreeNode* temp = new TreeNode(0);

                    // 指向選定的left subFBT & right subFBT
                    temp -> left = l;
                    temp -> right = r;
                    ret.push_back(temp);
                }
        }

        //儲存建立完成後的結果到dp裡面，以供之後使用，並回傳結果
        dp[n] = ret;
        return dp[n];
    }
};