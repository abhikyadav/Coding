class Solution {
public:
    void rec(int i, int n, int k, vector<vector<int>> &ans, vector<int> &curr)
    {
        if(curr.size()==k)
        {
            ans.push_back(curr);
            return;
        }
        else
        {
            for(int j=i; j<=n; j++)
            {
                curr.push_back(j);
                rec(j+1, n, k, ans, curr);
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        rec(1,n,k,ans,curr);
        return ans;
    }
};