class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        int res=nums[0];
        vector<int> dp;
        dp.push_back(nums[0]);
        deque<int> dq;
        dq.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(i>k && dq.front()==dp[i-k-1])dq.pop_front();
            int cur = max(nums[i],dq.front()+nums[i]);
            dp.push_back(cur);
            while(dq.size()>0 && dq.back()<cur)dq.pop_back();
            dq.push_back(cur);
            res=max(res,cur);
        }
        return res;
    }
        
};