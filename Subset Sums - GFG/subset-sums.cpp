// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void sumSubset(vector<int>& res,vector<int>& arr,int idx,int sum)
{
    if(idx==arr.size())
    {
        res.push_back(sum);
        return;
    }
    
    sumSubset(res,arr,idx+1,sum);
      sumSubset(res,arr,idx+1,sum+arr[idx]);
    
}


   vector<int> subsetSums(vector<int> arr, int N)
   {
       // Write Your Code here
       vector<int>ans;
       int sum=0;
       
       sumSubset(ans,arr,0,0);
       
       
       return ans;
       
   }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends