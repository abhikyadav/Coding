//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int isPossible(int r, int c, string s){
        map<char,int>mp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='U'){
                    mp['U']++;
                    if(mp['D']!=0)
                    mp['D']--;
                }
                
                if(s[i]=='D'){
                    mp['D']++;
                    if(mp['U']!=0)
                    mp['U']--;
                }
                if(s[i]=='R'){
                    mp['R']++;
                    if(mp['L']!=0)
                    mp['L']--;
                }
                
                if(s[i]=='L'){
                    mp['L']++;
                    if(mp['R']!=0)
                    mp['R']--;
                }
            if(mp['R']>=c or mp['L']>=c)return 0;
            if(mp['U']>=r or mp['D']>=r)return 0;
        }
        
            return 1;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.isPossible(n, m, s)<<endl;
    }
    return 0;
}
// } Driver Code Ends