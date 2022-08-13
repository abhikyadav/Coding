class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n  =arr1.size();
        int m = arr2.size();
        vector<int> ans;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++)
        {
            mp[arr1[i]]++;
        }
        for(int i=0; i<m; i++)
        {
            while(mp[arr2[i]]>0)
            {
                ans.push_back(arr2[i]);
                mp[arr2[i]]--;
            }
        }
        for(int i=0; i<mp.size(); i++)
        {
            while(mp[i]>0)
            {
                ans.push_back(i);
                mp[i]--;
            }
        }
        return ans;
    }
};