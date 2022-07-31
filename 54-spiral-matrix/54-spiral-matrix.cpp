class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int r = matrix.size();
        int c = matrix[0].size();
        int top =0;
        int bottom = r-1;
        int left =0;
        int right = c-1;
        int v=0;
        while(left<=right && top<=bottom)
        {
            if(v==0)
            {
                for(int i=left; i<=right;i++)
                {
                    res.push_back(matrix[top][i]);
                }
                v=1;
                top++;
            }
            else if( v==1)
            {
                for(int i= top; i<=bottom; i++)
                {
                    res.push_back(matrix[i][right]);
                }
                v=2;
                right--;
            }
            else if(v==2)
            {
                for(int i=right; i>=left;i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                v=3;
                bottom--;
            }
            else if(v==3)
            {
                for(int i=bottom; i>=top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                v=0;
                left++;
            }
        }
        return res;
    }
};