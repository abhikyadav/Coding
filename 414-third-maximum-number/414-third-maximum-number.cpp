class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        //map<int ,int> mp;
        int n = nums.size();
        int maxi = 0;
        int idx =n-1,i;
        while(idx>=0)
        {
            maxi++;
            i = idx-1;
            while(i>=0 && nums[i]==nums[idx])
            {
                i--;
            }
            if(i==-1)
            {
                return nums[n-1];
            }
            idx = i;
            if(maxi==2)
            {
                return nums[idx];
            }
        }
        return -1;
        
    }
};