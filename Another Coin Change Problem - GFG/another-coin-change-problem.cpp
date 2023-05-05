//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    
    int funct(int N, int k, int target, int i, int j, int val, vector<int> &coins, vector<vector<vector<int>>>& dp)
    {
        if(i<N && j==k && val == target)
        return 1;
        
        if(i==N || j>k || val>target)
        return 0;
        
        if(dp[i][j][val]!=-1)
        return dp[i][j][val];
        
        return dp[i][j][val] = (funct(N,k,target,i,j+1,val+coins[i],coins,dp)||
        funct(N,k,target,i+1,j+1,val+coins[i],coins,dp)||
        funct(N,k,target,i+1,j,val,coins,dp));
    }


    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        
        vector<vector<vector<int>>> dp(N+1,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
        return funct(N,K,target,0,0,0,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends