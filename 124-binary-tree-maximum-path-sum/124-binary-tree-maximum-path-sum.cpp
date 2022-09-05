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
    int maxPathSum(TreeNode* root) {
        int maxpath = INT_MIN;
        dfs(root,maxpath);
        return maxpath;
    }
    
    int dfs(TreeNode* root, int &maxpath)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left = max(dfs(root->left, maxpath),0);
        int right = max(dfs(root->right, maxpath),0);
        int currpath = root->val+left+right;
        maxpath = max(currpath, maxpath);
        return root->val+max(left,right);
    }
};