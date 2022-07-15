class Solution {
public:
    void helper(vector<vector<int>>&s,int index,vector<int>output,vector<int>nums,bool pre)
    {
        if(index>=nums.size())
        {
            
             s.push_back(output);
            return ;
        }
        helper(s,index+1,output,nums,false);
        if(index>0 && nums[index]==nums[index-1] && !(pre))
            return ;
        int e=nums[index];
        output.push_back(e);
        helper(s,index+1,output,nums,true);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>output;
        vector<vector<int>>s;
        int index=0;
        helper(s,index,output,nums,false);
        
        
        return s;
    }
};