class Solution {
public:
    int climbStairs(int n) {
        // int t[n+1];
        // for(int i=0;i<=n;i++) t[i]=0;
        // t[1]=1;
        // if(n>=2) t[2]=2;
        // for(int i=3;i<=n;i++){
        //      t[i] = t[i-1]+t[i-2];    
        // }
        // return t[n];
        int dp[n+1];
        dp[0]=0;
         if(n==0) return 0;
        dp[1]=1;
        if(n==1) return dp[1];
        dp[2]=2;
        if(n==2)
        {
            return dp[2];
        }
        for(int i=3; i<=n; i++)
        {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};