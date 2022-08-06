class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(auto i:intervals){
            if(ans.back()[1]<i[0]){
                ans.push_back(i);
            }
            else{
                ans.back()[1]=max(ans.back()[1],i[1]);
            }
        }
        return ans;
    }
};