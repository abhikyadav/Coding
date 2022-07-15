class Solution {
public:
    void backtrack(vector<vector<int>> &output, vector<int> &current, vector<int> &candidates, int remain, int start){
    if(remain < 0)
        return;
    else if(remain == 0)output.push_back(current);
    else {
        for(int i=start;i<candidates.size();i++){
            if (i != start && candidates[i] == candidates[i-1]) {
            continue;
            }
            if(candidates[i]<= remain)
            {
            current.push_back(candidates[i]);
            backtrack(output, current, candidates, remain - candidates[i], i+1);
            current.pop_back();
            }
        }
    }
}
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(output, current, candidates, target, 0);
        return output;
    }
};