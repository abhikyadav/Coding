class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int,int> mp;
        for(int i=0; i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        vector<int> vec;
        for(int j =1; j<=nums.size(); j++)
        {
            if(mp[j]>=2)
            {
                vec.push_back(j);
            }
        }
        return vec;
    }
};