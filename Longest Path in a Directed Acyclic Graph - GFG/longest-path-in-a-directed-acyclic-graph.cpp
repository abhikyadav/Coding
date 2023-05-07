//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
       vector <int> maximumDistance(vector<vector<int>> edges,int v,int e,int src)
      {
            // code here
            //using bellman ford algorithm
            vector<int>dist(v,INT_MIN);
            dist[src]=0;
            for(int i=0;i<=v;i++){
                for(int j=0;j<edges.size();j++){
                    int u=edges[j][0];
                    int v=edges[j][1];
                    int wt=edges[j][2];
                    if(dist[u]!=INT_MIN &&(dist[u]+wt>dist[v])){
                        dist[v]=dist[u]+wt;
                    }
                }
            }
            //check for negative cycle 
            bool flag=0;
            for(int j=0;j<e;j++){
                    int u=edges[j][0];
                    int v=edges[j][1];
                    int wt=edges[j][2];
                    if(dist[u]!=INT_MIN &&(dist[u]+wt>dist[v])){
                        flag=1;
                    }
            }
            if(flag==0){
                return dist;
            }
            else{
                return {-1};
            }
      }
};

//{ Driver Code Starts.

int main() {
  
    int t;
    cin>>t;
    while(t--)
    {

        int v,e;
        cin>>v>>e;
     
        int src;
        cin>>src;
        vector<vector<int>> edges(e,vector<int> (3));
        for(auto &j:edges)
          cin>>j[0]>>j[1]>>j[2];

        Solution s;
        vector <int> ans=s.maximumDistance(edges,v,e,src);
        for(auto j:ans)
        {
            if(j==INT_MIN)
              cout<<"INF ";
            else
              cout<<j<<" ";
        }
        cout<<endl;
    } 
    return 0;
 
}
// } Driver Code Ends