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
    bool check(TreeNode *root, int targetSum){
        if(root == NULL and targetSum != 0) return false;
        if(root == NULL and targetSum == 0) return true;
        if(root->right ==  NULL) return check(root->left, targetSum - root->val);
        if(root->left ==  NULL) return check(root->right, targetSum - root->val);
        return check(root->left, targetSum - root->val) ||  check(root->right, targetSum - root->val);
    }
    
public:
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if( root == NULL )
            return(false);

        if(root -> left == NULL && root -> right == NULL)
            return(root -> val == targetSum );
        
        if(hasPathSum(root -> left, targetSum - root -> val))
            return(true);
        
        if(hasPathSum(root -> right, targetSum - root -> val))
            return(true);
        
        return(false);
    }
};