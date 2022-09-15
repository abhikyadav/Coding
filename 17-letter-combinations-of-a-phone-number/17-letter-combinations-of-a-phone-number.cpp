class Solution {
public:
vector<string> letterCombinations(string digits) {
    
        vector<string> phone={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
    if(digits.empty())
        return {};
    
        queue<string> q;
        vector<string> ans;
        
        q.push("");
        
        while(!q.empty())
        {
            string curr = q.front();
            q.pop();
            
            if(curr.length()==digits.length())
                ans.push_back(curr);
            else{
                string s = phone[digits[curr.length()] - '0'];
                for(auto x: s)
                    q.push(curr + x);
            }
            
        }
        return ans;
    }
};