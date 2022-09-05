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
// bool isValidBST(TreeNode* root) {
//         TreeNode* prev = NULL;
//         return validate(root, prev);
//     }
    // bool validate(TreeNode* node, TreeNode* &prev) {
    //     if (node == NULL) return true;
    //     if (!validate(node->left, prev)) return false;
    //     if (prev != NULL && prev->val >= node->val) return false;
    //     prev = node;
    //     return validate(node->right, prev);
    // }
    vector<int> vec;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root)
    {
        if(root==NULL)
        {
            return true;
        }
        inorder(root);
        int n = vec.size();
        for(int i=0; i<n-1; i++)
        {
            if(vec[i]>=vec[i+1])
            {
                return false;
            }
        }
        return true;
        
    }
};