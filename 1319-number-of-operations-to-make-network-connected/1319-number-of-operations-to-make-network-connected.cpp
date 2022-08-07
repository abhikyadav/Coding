class Solution {
public:
    void dfs(vector<vector<int>> &adj, vector<bool> &vis, int src)
    {
        vis[src]=true;
        for(auto i: adj[src])
        {
            if(vis[i]==false)
            {
                dfs(adj,vis,i);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto v: connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        int components =0;
        for(int i=0; i<n; i++)
        {
            if(vis[i]==false)
            {
                dfs(adj,vis,i);
                components++;
            }
        }
        return components-1;
        
    }
};