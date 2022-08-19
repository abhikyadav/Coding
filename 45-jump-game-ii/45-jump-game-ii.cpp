class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int curMax = 0; // to mark the last element in a level
        int level = 0, i = 0;
        while (i <= curMax) { 
            int furthest = curMax; // to mark the last element in the next level
            for (; i <= curMax; i++) {
                furthest = max(furthest, nums[i] + i);
                if (furthest >= nums.size() - 1) return level + 1;
            }
            level++;
            curMax = furthest;
        }
        return -1;
    }
};