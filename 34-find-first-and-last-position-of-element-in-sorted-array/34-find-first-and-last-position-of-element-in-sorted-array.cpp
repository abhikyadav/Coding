class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int Tleft = find(nums, target);
        if(Tleft==nums.size()||nums[Tleft]!=target)
        {
            return {-1,-1};
        }
        return {Tleft, find(nums,target+1, Tleft )-1};
    }
    int find(vector<int> nums, int target, int left=0)
    {
        int right = nums.size()-1;
        while(left<=right)
        {
            int mid = (left+right)/2;
            if(target>nums[mid])
            {
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return left;
    }
};