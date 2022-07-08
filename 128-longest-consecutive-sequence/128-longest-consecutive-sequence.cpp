class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int mx = INT_MIN;
        // int count =0;
        // for(int i =0; i<nums.size(); i++)
        // {
        //     //int ans = nums[i];
        //     if((nums[i]+1)==nums[i+1])
        //     {
        //         count++;
        //         mx = max(mx,count);
        //     }
        //     if(nums[i]+1!=nums[i+1])
        //     {
        //         count=0;
        //         mx = max(mx,count);
        //     }
        // }
        // return count;
        if (nums.empty()) {
            return 0;
        }
        unordered_map<int, int> hash;
        int ans{1};
        for (const auto& i : nums) {
            if (!hash[i]) {
                hash[i] = 1;
                int leftbound{hash[i - 1]}, rightbound{hash[i + 1]}; // Get neighbor info.
                hash[i - leftbound] = hash[i + rightbound] = 1 + leftbound + rightbound; // Update left and right bound info.
                ans = max(ans, 1 + leftbound + rightbound);
            }
        }
        return ans;
    }
};