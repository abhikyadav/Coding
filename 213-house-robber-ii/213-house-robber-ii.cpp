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
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        if(n==3)
        {
            return max(nums[2],max(nums[0],nums[1]));
        }
        int dp[n],i;
        memset(dp,0,n);
        dp[0] = nums[0];
        dp[1] = max(dp[0], nums[1]);
        for(i = 2; i<=n-1; i++)
        {
            dp[i] = max((dp[i-2]+nums[i]), dp[i-1]);
        }
        int l = dp[n-2];
        memset(dp,0,n);
        dp[1]= nums[1];
        dp[2] = max(dp[1],nums[2]);
        for(i=3;i<n;i++)
        {
            dp[i]=max((dp[i-2]+nums[i]), dp[i-1]);
        }
        return max(l,dp[n-1]);        
    }
};