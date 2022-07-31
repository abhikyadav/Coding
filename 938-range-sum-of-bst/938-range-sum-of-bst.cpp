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
    int value=0;
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==NULL)
        {
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty()==false)
        {
             TreeNode* curr = q.front();
             q.pop();
            if((curr->val)<=high && (curr->val)>=low)
            {
               value+=curr->val;
            
            }
            if(curr->left!=NULL && curr->val>low)
            {
                q.push(curr->left);
            }
            if(curr->right!=NULL && curr->val<high)
            {
                q.push(curr->right);
            }
        }
        return value;
    }
};