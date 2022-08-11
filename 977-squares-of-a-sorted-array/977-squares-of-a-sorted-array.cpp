class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l =0, r=nums.size()-1;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1; i>=0; i--)
        {
            if(abs(nums[l])<abs(nums[r]))
            {
                ans[i] = nums[r]*nums[r--];
            }
            else
            {
                ans[i] = nums[l]*nums[l++];
            }
        }
       
        return ans;
    }
};