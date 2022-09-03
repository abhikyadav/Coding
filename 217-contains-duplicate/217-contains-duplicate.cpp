class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++)
        {
            if(mp[nums[i]]==1)
            {
                return true;
            }
            else
            {
                mp[nums[i]]++;
            }
        }
        return false;
    }
};