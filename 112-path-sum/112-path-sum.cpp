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
   bool pathsum(TreeNode* root, int sum, int target){
        if(root==NULL){
            return false;
        }
        
        if(root->left==NULL and root->right==NULL){
            sum = sum + root->val;
            
            if(sum==target) return true;
            else return false;
        }
        
        return pathsum(root->left, sum+root->val, target) or pathsum(root->right, sum+root->val, target);
    }
    
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return pathsum(root, 0, targetSum);
    }
    
};