class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> freq(26,0);
        for(auto x: chars)
        {
            freq[x-'a']++;
        }
        int res=0;
        for(int i=0; i<words.size(); i++)
        {
            vector<int> v= freq;
            bool flag =true;
            for(auto ch: words[i])
            {
                v[ch-'a']--;
                if(v[ch-'a']<0)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                res+=words[i].size();
            }
        }
        return res;
    }
};