class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int i =0;
        while(i<s.size())
        {
            string w;
            while(s[i]==' ')
            {
                i++;
            }
            while(i<s.size() && s[i]!=' ')
            {
                w.push_back(s[i]);
                i++;
            }
            i++;
            if(w.empty()==false)
            {
                ans = w+' '+ans;
            }
        }
        ans.pop_back();
        return ans;
    }
};