class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low =0;
        int high = height.size()-1;
        int res =0;
        while(low < high)
        {
            res = max(res, min(height[low],height[high])*(high-low));
            if(height[low]<=height[high])
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return res;
    }
};