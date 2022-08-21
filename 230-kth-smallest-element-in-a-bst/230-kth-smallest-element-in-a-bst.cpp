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
    vector<int> ans;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    int kthSmallest(TreeNode* node, int k) {
        stack<TreeNode*>st;
        while (node || !st.empty()) {
            while (node!=0) {
                st.push(node);
                node=node->left;
            }
            
            node = st.top();
            st.pop();
            
            if (--k == 0) 
                return node->val;
            node = node->right;
        }
        return -1;
    }
};