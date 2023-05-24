//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void solve(int ind ,string s ,  int target, vector<string> &v , string tmp , long long prev , long long result)
   {
       if(ind == s.size() )
       {
       if(result == target)
           v.push_back(tmp);
         return ;
       }
       
       string st = "";
       long long cn = 0;
       for(int i = ind ; i < s.size() ; i++)
       {
           
           if(i>ind  && s[ind]=='0') //Discard leading zeros
               break;
               
          st+=s[i];
          
           cn = 10*cn + s[i] - '0';
           
           if(ind==0)
                    solve(i + 1, s , target , v , tmp + st, cn , cn);
           else
           {
       solve(i + 1 , s , target , v , tmp+"+"+st ,  cn ,result + cn  ) ;
      
       solve(i + 1 , s , target , v , tmp+"-"+st ,  -cn ,result - cn );
     
       solve(i+ 1 , s , target , v , tmp+"*"+st ,  cn*prev , result - prev + prev*cn );
           }
       }
      
 
       
       return; 
   }
    vector<string> addOperators(string s, int target) {
        // code here
        vector<string> v;
        string tmp="";
        long long prev = 0 ; 
    
    
        solve(0,s,target , v , tmp, prev , 0);
        return v;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends