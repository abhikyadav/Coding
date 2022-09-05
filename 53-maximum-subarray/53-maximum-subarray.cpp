class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n= nums.size();
        int max= INT_MIN;
        int min = 0;
        for(int i =0; i<n; i++)
        {
            min= min+nums[i];
            if(max<min)
            {       
                max= min;
            }
            if(min<0)
            {
                min=0;
            }
        }
        return max;
    }
};