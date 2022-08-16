class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int mx = INT_MIN;
        for(int i=0; i<accounts.size(); i++)
        {
            int ans=0;
            for(int j=0; j<accounts[0].size(); j++)
            {
                ans+=accounts[i][j];
            }
            if(ans>mx)
            {
                mx=ans;
            }
                
        }
        return mx;
    }
};