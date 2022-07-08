class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        int product = 1, i;

        for(i = 0; i < nums.size(); i++){
            answer.push_back(product);
            product *= nums[i];
        }

        product = 1;
        for(i = nums.size() - 1; i >= 0; i--){
            answer[i] *= product;
            product *= nums[i];
        }

        return answer;
//         int n= nums.size();
//         int ans;
//         vector<int> vect;
//         for(int i =0;i<n;i++)
//         {    ans =1;
//             for(int j =0;j<n;j++)
//             {
//                 if(i==j)
//                 {
//                     continue;
//                 }
//                 else
//                 {
//                     ans= ans*nums[j];
//                 }
//             }
         
 
//         vect.push_back(ans);
//         }
//         return vect;
    }
};