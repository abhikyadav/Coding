class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        int sz = s.size();
        int i=0,j=0;
        int count[26]={0};
        while(i<sz)
        {
            count[s[i]-'a']++;
            i++;
        }
        while(j<t.size())
            {
                count[t[j]-'a']--;
            if(count[t[j]-'a']<0)
        {
            return false;
        }
                j++;
            }
        return true;
    }
};