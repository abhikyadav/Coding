class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index=0; 
        int last_index = strs[0].size()-1;
        string prefix="";
        char test_char = strs[0][index];
        while(index<=last_index)
        {
            for(auto &s : strs)
            {
                if(s[index]!=test_char)
                {
                    return prefix;
                }
            }
            prefix+=test_char;
            ++index;
            test_char = strs[0][index];
        }
        return prefix;
    }
};