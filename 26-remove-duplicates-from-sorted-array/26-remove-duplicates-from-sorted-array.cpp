class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =nums.size();
        int count =0;
        for(int i =0; i<n; i++)
        {
            if(nums[i]!=nums[count])
            {
                count++;
                nums[count] = nums[i];
            }
        }
        return count+1;
    }
};