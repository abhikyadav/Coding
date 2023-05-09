//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    void Permute(string S, vector<string> &ans, int i = 0)
    {
        if(i == S.length() - 1)
        {
            ans.push_back(S);
            return;
        }
        
        for(int k = i; k < S.length(); k++)
        {
            swap(S[k],S[i]);
            Permute(S,ans,i+1);
            swap(S[k],S[i]);
        }
    }
    
	public:
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> Result;
		    Permute(S, Result, 0);
		    sort(Result.begin(),Result.end());
		    Result.erase(unique(Result.begin(),Result.end()),Result.end());
		    return Result;
		    
		}
};


//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends