class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_index = 0, count = 1;
        int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[maj_index] == nums[i])
            count++;
        else
            count--;
        if (count == 0) {
            maj_index = i;
            count = 1;
        }
    }
    return nums[maj_index];
    }
};