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
public:
    int depth = 0, ans = 100001;
    void dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            ans = 0;
            return;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            depth++;
            ans = min(ans, depth);
            depth--;
            return;
        }

        if(root->left != NULL )
        {
            depth++;
            dfs(root->left);
            depth--;
        }

        if(root->right != NULL)
        {
            depth++;
            dfs(root->right);
            depth--;
        }
        return;
    }
    int minDepth(TreeNode* root) {
        dfs(root);
        return ans;
    }
};