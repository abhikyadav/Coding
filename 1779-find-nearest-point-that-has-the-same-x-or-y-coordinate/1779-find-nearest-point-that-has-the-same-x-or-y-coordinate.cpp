class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int ret = -1;
        int min = INT_MAX;
        
        for(int i = 0; i < points.size(); i++)
        {
            if(points[i][0] == x || points[i][1] == y)
            {
                int mdistance = abs(points[i][0] - x) + abs(points[i][1] - y);
                if(mdistance < min)
                {
                    min = mdistance;
                    ret = i;
                }
            }
        }
        
        return ret;
    }

};