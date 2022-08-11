class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || k<=0)
        {
            return;
        }
        vector<int> numscopy(n,0);
        for(int i=0; i<n; i++)
        {
            numscopy[i]=nums[i];
        }
    for(int i=0; i<nums.size(); i++)
    {
        nums[(i+k)%n]=numscopy[i];
    }
    }
};