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
    TreeNode* sortedArrayToBS(vector<int> &arr,int start,int end)
    {
        if (start > end)
            return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    TreeNode *root = new TreeNode(arr[mid]);
 
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBS(arr, start,
                                    mid - 1);
 
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBS(arr, mid + 1, end);
 
    return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
        {
            return NULL;
        }
        int n =nums.size();
        int start=0;
        int end = n-1;
        return sortedArrayToBS(nums, start, end);
    }
};