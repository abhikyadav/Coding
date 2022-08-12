class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int dif,maxi=0,mini=prices[0];
           for(int j=0;j<prices.size();j++)
           {   
               mini= min(mini,prices[j]);
               dif=prices[j]-mini;
                maxi=max(dif,maxi);
               
           }
        return maxi;
    }
};