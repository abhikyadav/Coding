//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of cuts.
        int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int>dp(n+1,0);
        vector<int>v={x,y,z};
        for(int i=1;i<=n;i++){
            for(auto j:v){
                if(i-j>=0&&(i-j==0||dp[i-j]))dp[i]=max(dp[i],dp[i-j]+1);
            }
        }
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends