class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        
        int a=0;
        
        for(int i=0; i<size; i++) {
            if(nums[i]!=0) {
                swap(nums[i], nums[a]);
                a++;
            }
        }
    }
};