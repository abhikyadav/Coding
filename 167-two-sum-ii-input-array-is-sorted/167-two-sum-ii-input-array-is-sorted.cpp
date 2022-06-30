class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> vec;
        int n = numbers.size();
        int l = 0;
        int r = n-1;
        while(l<n)
        {
            if((numbers[r])==(target-numbers[l]))
            {
                vec.push_back(l+1);
                vec.push_back(r+1);
                return vec;
            }
            if(target<(numbers[l]+numbers[r]))
            {
                r--;
            }
            if(target>(numbers[l]+numbers[r]))
            {
                l++;
            }
        }
        return vec;
    }
};