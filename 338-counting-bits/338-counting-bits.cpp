class Solution {
public:
        int helper(uint32_t n) {
        int result =0;
        while(n)
        {
            if(n%2!=0)
            {
                result+=n%2;
            }
            n =n>>1;
        }
        return result;
    }
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0; i<=n; i++)
        {
            ans.push_back(helper(i));
        }
        return ans;
    }
};