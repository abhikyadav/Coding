class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        vector<vector<int>>ans;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            long long int fixed1 = k-arr[i];
            for(int j=i+1;j<n;j++){
                long long int fixed2 = fixed1-arr[j];
                int l = j+1;
                int h = n-1;
                while(l<h){
                    if(arr[l]+arr[h]>fixed2) h--;
                    else if(arr[l]+arr[h]<fixed2) l++;
                    else{
                        vector<int>quad(4,0);
                        quad[0]=arr[i];quad[1]=arr[j];quad[2]=arr[l];quad[3]=arr[h];
                        ans.push_back(quad);
                        //duplicates
                        while(l<h && arr[l]==quad[2])l++;
                        while(l<h && arr[h]==quad[3])h--;
                    }
                }
                while(j<n-1 && arr[j]==arr[j+1])j++;
            }
            while(i<n-1 && arr[i]==arr[i+1]) i++;
        }
        return ans;
    }
};