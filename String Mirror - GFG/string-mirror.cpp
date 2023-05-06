//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    string stringMirror(string str){
        // Code here
        if(str.size()>1 and str[0]==str[1])return str.substr(0,1)+str.substr(0,1);
        int idx;
        for(int i=1;i<str.size();i++){
            if(str[i]>str[i-1]){
                idx=i-1;break;
            }
        }
        string p=str.substr(0,idx+1);
        string x=p;
        reverse(x.begin(),x.end());
        return p+x;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends