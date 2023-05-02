//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n, vector<string>& arr){
        unordered_map<string, int> counts;
        for(string s : arr){
            counts[s]++;
        }
        for(string s : arr){
            reverse(s.begin(), s.end());
            counts[s]++;
        }
        for(auto it : counts){
            if(it.second % 2 == 1){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends