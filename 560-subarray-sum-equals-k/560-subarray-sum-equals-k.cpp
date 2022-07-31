class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int prefixsum =0;
        int value =0;
        for(int i=0; i<n; i++)
        {
            prefixsum+=nums[i];
            if(prefixsum==k)
            {
                value++;
            }
            if(mp.find(prefixsum-k)!=mp.end())
            {
                value=value+mp[prefixsum-k];
            }
            mp[prefixsum]++;
        }
        return value;
    }
};