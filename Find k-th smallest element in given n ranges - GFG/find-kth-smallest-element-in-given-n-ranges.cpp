//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    vector<vector<int>> merge(vector<vector<int>> &range){
        vector<vector<int>> v;
        int n = range.size();
        sort(range.begin(),range.end());
        int st =  range[0][0] , end = range[0][1];
        for(int i=1;i<n;i++){
            int newst = range[i][0],newend=range[i][1];
            if(st<=newst && end>=newend) continue;
            else if(end>=newst){
                end = newend;
            }
            else{
                v.push_back({st,end});
                st = newst;
                if(newend>end) end = newend;
            }
        }
        v.push_back({st,end});
        return v;
    }
    vector<int> kthSmallestNum(int n, vector<vector<int>>&range, int q, vector<int>queries){
        //Write your code here
        vector<vector<int>> v = merge(range);
        // for(auto i:v){
        //     cout <<  i[0] << " " << i[1] << endl;
        // }
        int sz = v.size();
        vector<int> presum(sz,0);
        presum[0]=v[0][1]-v[0][0]+1; 
        for(int i=1;i<sz;i++) presum[i] = presum[i-1] + v[i][1] - v[i][0] + 1;
        // for(int i:presum) cout << i << " ";
        // cout << endl;
        vector<int> ans(q,-1);
        for(int i=0;i<q;i++){
            int idx = lower_bound(presum.begin(),presum.end(),queries[i])-presum.begin();
            //cout << presum[idx] << endl;
            if (idx >= sz) continue;  
            if(presum[idx]<queries[i]) continue;
            if (idx >= sz || presum[idx] < queries[i]) continue;  
            int left = queries[i]-(idx-1>=0?presum[idx-1]:0);
            //cout << left << endl;
            if(idx>=0 && v[idx][0]+left-1<=v[idx][1]) ans[i] = v[idx][0]+left-1;
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
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends