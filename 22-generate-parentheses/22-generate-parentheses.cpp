class Solution {
public:
   vector<string> result;
    void helper(int open, int close, int n, string curr)
    {
        cout<<n;
        if(curr.length()==2*n)
        {
            result.push_back(curr);
            return;
        }
        if(open<n)
        {
            helper(open+1, close, n, curr+"(");
        }
        if(close<open)
        {
            helper(open,close+1,n,curr+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        helper(0,0,n,"");
        return result;
    }
};