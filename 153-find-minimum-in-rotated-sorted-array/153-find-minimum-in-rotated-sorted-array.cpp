class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int min= nums[0], count=0;
        for(int i=1; i<n; i++)
        {
            if(min>nums[i])
            {
                min = nums[i];
                break;
            }
            count++;
        }
        cout<<count++;
        return min;
    }
};