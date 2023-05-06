//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxLength(string s)
    {
        int open=0,close=0,ans=0,n=s.length();
        
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            open++;
            else
            close++;
            if(close==open)
            {
                int len=close+open;
                ans=max(ans,len);
            }
            if(close>open)
            open=close=0;
        }
        
        open=0,close=0;
        
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='(')
            open++;
            else
            close++;
            if(close==open)
            {
                int len=close+open;
                ans=max(ans,len);
            }
            if(open>close)
            open=close=0;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.maxLength(S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends