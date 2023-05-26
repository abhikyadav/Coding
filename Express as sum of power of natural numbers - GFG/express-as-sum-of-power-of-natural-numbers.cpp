//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int solve(int num, int n ,int x, vector<vector<int>> &dp){
        if(n==0) return 1;
        if(n<0) return 0;
        
        if(pow(num,x) > n) return 0;
        
        if(dp[num][n] != -1) return dp[num][n];
        
        int pick = 0;
        if(n-pow(num,x) >= 0){
            pick = solve(num+1,n-pow(num,x),x,dp);
        }
        int notpick = solve(num+1,n,x,dp);
        
        return dp[num][n]=(pick + notpick) % (int)(1e9+7);
    }
    int numOfWays(int n, int x)
    {
        // code here
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,x,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends