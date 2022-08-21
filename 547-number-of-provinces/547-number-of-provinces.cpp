class Solution {
public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &vis)
    {
        vis[node]=1;
        for(int i=0; i<adj[node].size(); i++)
        {
            if(adj[node][i]==1 && !vis[i])
            {
                 dfs(i,adj,vis);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V= isConnected.size();
        vector<int> vis(V,0);
        int res =0;
        for(int i=0; i<V; i++)
        {
            if(vis[i]==0)
            {
                dfs(i,isConnected,vis);
                res+=1;
            }
        }
        return res;
    }
};