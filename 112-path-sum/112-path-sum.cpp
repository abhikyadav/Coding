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
   bool hasPathSum(TreeNode* root, int targetSum) {
        
        // traverse down add to running sum, bail if greater than target
        bool found = false;
        
        bfs(root, 0, targetSum, found);
        
        return found; 
    }
private:
    
    void bfs(TreeNode* node, int runningSum, int targetSum, bool& isFound){
        
        if(isFound == true|| node == nullptr){ return; }
        
        runningSum += node->val;
        
        if(node->left == nullptr && node->right == nullptr){            
            
            if(runningSum == targetSum){ isFound = true; }
        }
        
        bfs(node->left, runningSum, targetSum, isFound);
        bfs(node->right, runningSum, targetSum, isFound);
    }
    
};