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
    int height(TreeNode* root, int *value)
    {
        TreeNode* temp = root;
        int lh=0;
        int rh =0;
        int ld=0,rd=0;
        if(temp==NULL)
        {
            *value=0;
            return 0;
        }
        ld = height(temp->left, &lh);
        rd = height(temp->right, &rh);
        *value = max(lh,rh)+1;
        return max(lh+rh, max(ld,rd));
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int value =0;
        int h = height(root,&value);
        return h;
    }
};