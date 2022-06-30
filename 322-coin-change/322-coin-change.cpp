class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int dp[amount+1];
        dp[0]=0;
        for(int i=1;i<=amount;i++)
        {
            dp[i]= INT_MAX;
        }
        //int ans = 0;
        for(int i=1;i<=amount;i++)
        {
            for(int j=0; j<n; j++)
        {
           if(coins[j]<=i)
        {
            int ans = dp[i-coins[j]];
               if(ans!=INT_MAX && ans+1<dp[i])
               {
                   dp[i] = ans +1;
               }
        } 
        }
        }
        return dp[amount]==INT_MAX?-1:dp[amount];
        
    }
};