class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n =grid[0].size();
        int count =0;
        int result = -1;
        queue<vector<int>> q;
        vector<vector<int>> dir={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]>0)
                {
                    count++;
                }
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            int sz = q.size();
            result++;
            for(int i=0; i<sz; i++)
            {
                vector<int> curr = q.front();
                count--;
                q.pop();
                for(int j=0; j<4; j++)
                {
                    int x = curr[0]+dir[j][0];
                    int y= curr[1]+dir[j][1];
                    if(x>=m || x<0 || y>=n || y<0 || grid[x][y]!=1)
                    {
                        continue;
                    }
                    grid[x][y]=2;
                    q.push({x,y});
                }
            }
        }
        if(count==0)
            return max(0,result);
        return -1;
    }
};