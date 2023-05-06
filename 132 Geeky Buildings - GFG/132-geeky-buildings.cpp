//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
public:
		bool recreationalSpot(int arr[], int n){

		multiset<int> se;
		
		for(int i=1;i<n;i++)se.insert(arr[i]);
		
		int first=arr[0];
	
		for(int i=1;i<n-1;i++)
		{
		    
		    auto tim=se.lower_bound(arr[i]);
		    
		    se.erase(tim);    
		    
		    if(arr[i]>first)
		    {  
		        auto tom=se.upper_bound(first);
		      
		        if(tom!=se.end()&&arr[i]>(*tom))
		            return true;
		        
		    }
		    else
		       first=min(first,arr[i]);
		       
		    
		}
		
		return false;
	}
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
		    cin>>arr[i];
		Solution ob;
		if(ob.recreationalSpot(arr, n))
		    cout<<"True"<<endl;
		else
		    cout<<"False"<<endl;
	}
	return 0;
}
// } Driver Code Ends