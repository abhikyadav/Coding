class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==1)
        {
            return cost[0];
        }
        int dp[n];
        dp[0]=cost[0];
        dp[1]=cost[1];
        int i=2;
        while(i<n)
        {
            dp[i]=min(dp[i-1],dp[i-2])+cost[i];
            i++;
        }
        return min(dp[i-1],dp[i-2]);
    }
};