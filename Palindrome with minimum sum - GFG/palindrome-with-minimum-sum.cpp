//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumSum(string s) {
        int i =0, j = s.length()-1;
        while(i<j){
            if(s[i]!='?' && s[j]!='?'){
                if(s[i]!=s[j])
                    return -1;
            }else if(s[i]!='?'){
                s[j]=s[i];
            }else{
                s[i]=s[j];
            }
            i++;
            j--;
        }
        int res = 0, l = -1 ;
        for(int i=0;i<s.length();++i){
            if(s[i]!='?'){
                if(l==-1)
                    l=i;
                else{
                    res+=(abs(s[i]-s[l]));
                    l=i;
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        int ans = ob.minimumSum(s);
        cout << ans;
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends