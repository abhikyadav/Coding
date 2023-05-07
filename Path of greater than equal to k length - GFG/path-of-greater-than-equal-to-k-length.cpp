//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
public:
    int dfs(vector<pair<int,int>> adj[], vector<bool>& vis, int i) {
        
        vis[i]=true;
        int maxsum=0;
        for(auto it:adj[i]) {
            if(!vis[it.first]) {
                int tempsum=it.second;
                tempsum+=dfs(adj,vis,it.first);
                maxsum=max(maxsum,tempsum);
            }
        }
        vis[i]=false;
        return maxsum;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here
       vector<pair<int,int>> adj[V];
       for(int i=0; i<3*E; i+=3) {
           adj[a[i]].push_back({a[i+1],a[i+2]});
           adj[a[i+1]].push_back({a[i],a[i+2]});
       }
       vector<bool> vis(V,0);
       if(dfs(adj,vis,0)>=k) {
           return true;
       }
       return false;
    } 
};




//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends