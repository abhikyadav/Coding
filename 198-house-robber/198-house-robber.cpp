class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        {
            return 0;
        }
        if(n==1)
        {
            return nums[0];
        }
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        int i =2;
        while(i<n)
        {
            dp[i]  =max((dp[i-2]+nums[i]), dp[i-1]);
            i++;
        }
        return dp[n-1];
    }
};