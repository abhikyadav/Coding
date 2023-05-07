//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class TrieNode{
    public:
    TrieNode*children[26];
    bool isEnd;
    int count;

    TrieNode(){
        for(int i=0;i<26;i++){
            children[i]=nullptr;
        }
        isEnd=false;
        count=0;
    }
};
class Solution
{
    public:
        void insert(TrieNode *root, string word){
            if (word.length() == 0) {
                root->isEnd = true;
                return;
            }
            
            int index=word[0]-'a';
            TrieNode*child;

            //present
            if(root->children[index]!=nullptr){
                child=root->children[index];
            }
            //absent
            else{
                child=new TrieNode();
                root->children[index]=child;
            }
            root->count++;
            root->isEnd=true;
            insert(child,word.substr(1));
        }
    
    
    string search(TrieNode *root, string &word){
        string res = "";
        
        for(int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            if(root->children[idx]->count == 1)
            {
                res += word[i];
                break;
            }
            res += word[i];
            root = root->children[idx];
        }
        return res;
    }
    
    
    vector<string> findPrefixes(string arr[], int n)
    {
        TrieNode *root = new TrieNode();

        vector<string> ans;

        for(int i=0; i<n; i++){
           insert(root,arr[i]);
        }
        
        for(int i=0; i<n; i++){
            ans.push_back(search(root,arr[i]));
        }
        
        return ans;
    }
    
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        string arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
            
        Solution ob;
        vector<string> ans = ob.findPrefixes(arr, n);
        
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] <<" ";


        cout << "\n";

    }

    return 0;
}

// } Driver Code Ends