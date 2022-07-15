// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution {
  public:
  void backtrack(vector<vector<int>> &Out, vector<int> &curr, vector<int> &ds, int B, int S)
  {
      if(S==curr.size())
      {
          if(B==0)
          {
              Out.push_back(ds);
          }
          return;
      }
      if(curr[S]<=B)
      {
              ds.push_back(curr[S]);
              backtrack(Out, curr, ds, B-curr[S], S);
              ds.pop_back();
      }
      backtrack(Out, curr, ds, B, S+1);
  }
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int> > combinationSum(vector<int> &A, int B) {
        vector<vector<int>> output;
        int n = A.size();
        vector<int> current;
        vector<int> ds;
        unordered_set<int> h;
        for(int i= 0; i<n;i++)
        {
            h.insert(A[i]);
        }
        for(auto it:h)
    {
        current.push_back(it);
    }
        sort(current.begin(), current.end());
        backtrack(output, current, ds, B, 0);// Your code here
        return output;
    }
};

// { Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            A.push_back(x);
        }   
        int sum;
        cin>>sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
   		if(result.size()==0){
   			cout<<"Empty";
   		}
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}	  // } Driver Code Ends