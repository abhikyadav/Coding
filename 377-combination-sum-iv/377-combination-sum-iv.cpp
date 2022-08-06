class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
       vector<long double> dp(target+1,0);
        dp[0]=1;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<target+1;i++){
            int j=0;
            while(j<n and nums[j]<=i){
                dp[i] += dp[i-nums[j]];
                j++;
            }
        }
        return dp[target]; 
    }
};