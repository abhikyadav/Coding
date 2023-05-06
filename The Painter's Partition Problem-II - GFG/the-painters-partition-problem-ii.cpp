//{ Driver Code Starts
// driver code

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    bool minofmax(int m,int arr[],int k,int n){
        int p=1;
        int pa=0;
        for(int i=0;i<n;i++){
            if(arr[i]>m) return false;
            if(arr[i]+pa>m){
                p++;
                pa=arr[i];
            }
            else pa+=arr[i];
        }
        if(p<=k) return true;
        return false;
        
    }
    long long minTime(int arr[], int n, int k)
    {
        // code here
        // return minimum time
        int ma=INT_MIN;
        long long  s=0;
        for(int i=0;i<n;i++){
            s+=arr[i];
            ma=max(ma,arr[i]);
        }
        long long  l=ma;
        long long  h=s;
        long long  ans=-1;
        while(l<=h){
            int m=(l+h)/2;
            if(minofmax(m,arr,k,n)){
                ans=m;
                h=m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int k,n;
		cin>>k>>n;
		
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution obj;
		cout << obj.minTime(arr, n, k) << endl;
	}
	return 0;
}
// } Driver Code Ends