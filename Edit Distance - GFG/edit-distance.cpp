//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int solve(string &s,string &t,int i,int j,vector<vector<int>>&dp)
    {
        if(i<0) return j+1;
        
        if(j<0) return i+1;
        
        if(dp[i][j]!= -1) return dp[i][j];
        
        if(s[i]==t[j])
        {
            return dp[i][j]= solve(s,t,i-1,j-1,dp);
          }
        else{
        int deleted= solve(s,t,i-1,j,dp);
        int insert= solve(s,t,i,j-1,dp);
        int replace= solve(s,t,i-1,j-1,dp);
        
        return dp[i][j]= 1+min({deleted,insert,replace});
        }
   }
    int editDistance(string s, string t) {
        // Code here
         int n= s.length();
        int m= t.length();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
         return solve(s,t,n-1,m-1,dp);
     }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends