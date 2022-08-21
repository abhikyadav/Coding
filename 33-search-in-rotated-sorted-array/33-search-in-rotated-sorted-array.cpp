class Solution {
public:
    int search(vector<int>& nums, int t) {
        int l = 0;
        int h = nums.size()-1;
        
        while(l <= h) {
            int mid = (l+h)/2;
            
            if(nums[mid] == t) return mid;
            // lo to mid sorted
            else if(nums[l] <= nums[mid]) {
                if(t >= nums[l] and t < nums[mid]) {
                    h = mid-1;
                }else l = mid+1;
            }
            // mid to hi sorted
            else if(nums[h] >= nums[mid]) {
                if(t > nums[mid] and t <= nums[h]){
                    l = mid+1;
                }else h = mid-1;
            }
        }
        return -1;
    }
};