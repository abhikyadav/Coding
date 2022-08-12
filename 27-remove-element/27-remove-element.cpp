class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n =nums.size();
        if(n==0)
        {
            return 0;
        }
        int count=0;
        for(int i=0; i<nums.size();)
        {
            if(nums[i]==val)
            {
                nums.erase(nums.begin()+i);
                n--;
                nums.resize(n);
                continue;
            }
            i++;
        }
        return n;
        
        // if(nums.size() == 0){
        //     return 0;
        // }
        // int s = nums.size();
        // for(int i=0; i<nums.size();){
        //     if(nums[i] == val){
        //         nums.erase(nums.begin()+i);
        //         s--;
        //         nums.resize(s);
        //         continue;
        //     }
        //     i++;
        // }
        // return s;
    }
};