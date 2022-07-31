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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp = root;
        if(temp==NULL)
        {
            return NULL;
        }
        
        invertTree(temp->left);
        invertTree(temp->right);
            TreeNode* dummy= temp->left;
            temp->left = temp->right;
            temp->right= dummy;
        return root;
    }
};