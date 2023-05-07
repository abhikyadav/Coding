//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


// } Driver Code Ends
//User function Template for C++


#define mod 1000000007

class Solution{
    public:
    
    
    int solve(vector<int> &arr, int i)
    {
        int x=i;
        int count=1;
        while(arr[x]!=-1)
        {
            count++;
            int y=arr[x]-1;
            arr[x]=-1;
            x=y;
        }
        return count;
    }
    
    int rearrange_array(vector<int> arr){
        vector<int>ans;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]!=-1)
            {
                int x=arr[i] - 1;
                arr[i]=-1;
                int fans = solve(arr,x);
                ans.push_back(fans);
            }
        }
        
        while(ans.size()>1)
        {
            long long x=ans.back();
            ans.pop_back();
            long long y=ans.back();
            ans.pop_back();
            long long z= (x*y)/(__gcd(x,y));
            z=z%mod;
            ans.push_back((int)z);
        }
        return (int)(ans[0]);
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        int ans = obj.rearrange_array(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends