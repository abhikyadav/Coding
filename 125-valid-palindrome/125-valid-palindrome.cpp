class Solution {
public:
    bool isPalindrome(string s) {
       transform(s.begin(),s.end(),s.begin(),::tolower);
        int n = s.size();
        string t ="";
        for(int i=0; i<n; i++)
        {
            if(iswalnum(s[i]))
            {
                t+=s[i];
            }
        }
        string str = t;
        reverse(str.begin(),str.end());
        return t==str;
    }
};