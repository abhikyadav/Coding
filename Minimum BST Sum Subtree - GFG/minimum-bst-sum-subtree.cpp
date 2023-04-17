//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }

    Node *buildTree(string s) {
        if (s.length() == 0 || s[0] == 'N') return NULL;

        // Create the root of the tree
        vector<string> str;
        istringstream iss(s);
        for (string s; iss >> s;) str.push_back(s);
        Node *root = new Node(stoi(str[0]));

        // Push the root to the queue
        queue<Node*> q;
        q.push(root);

        // Starting from the second element
        int i = 1;
        while (q.size() > 0 && i < str.size()) {

            // Get and remove the front of the queue
            Node *currNode = q.front();
            q.pop();

            // Get the current node's value from the string
            string currVal = str[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));
                // Push it to the queue
                q.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= str.size()) break;

            currVal = str[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                q.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node *root) {
        if (root == NULL) return;
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minSubtreeSumBST(int target, Node *root) {
        int maxVal, minVal, sum, ans = -1;
        solve(root, maxVal, minVal, sum, ans, target);
        return ans;
    }
    
    // Returns length of the subtree if BST else returns -1
    int solve(Node* root, int& maxVal, int& minVal, int& sum, int& ans, int target) {
        if(!root) {
            sum = 0;
            return 0;
        }
        int lmax, rmax, lmin, rmin, lsum, rsum;
        int llen = solve(root -> left, lmax, lmin, lsum, ans, target);
        int rlen = solve(root -> right, rmax, rmin, rsum, ans, target);
        
        // BST check
        if(llen == -1 || rlen == -1) return -1;
        if(llen > 0 && lmax >= root -> data) return -1;
        if(rlen > 0 && rmin <= root -> data) return -1;
        
        maxVal = rlen > 0 ? rmax : root -> data;
        minVal = llen > 0 ? lmin : root -> data;
        sum = lsum + rsum + root -> data;
        int len = llen + rlen + 1;
        if(sum == target && (ans == -1 || ans > len)) ans = len;
        return len;
    }
};

//{ Driver Code Starts.


int main(){
    
    int t;
    cin>>t;
    while(t--){
        int target;
        cin>>target;
        string str;
        getline(cin,str);
        getline(cin,str);
        Node node(0);
        Node *root = node.buildTree(str);
        Solution ob;
        int res = ob.minSubtreeSumBST(target, root);
        cout<<res<<endl;
    }
    return 0;
}
// } Driver Code Ends