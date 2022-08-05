class Solution {
public:
    void dfs(vector<vector<int>> &image, int sr, int sc, int oldc, int newc)
{
    if(sr<0 || sr>image.size()-1 || sc<0 || sc>image[0].size()-1||image[sr][sc]==newc)
    {
        return;
    }
    if(oldc==image[sr][sc])
    {
        image[sr][sc] = newc;
        dfs(image, sr+1, sc,oldc,newc);
        dfs(image, sr, sc+1,oldc,newc);
        dfs(image, sr-1, sc,oldc,newc);
        dfs(image, sr, sc-1,oldc,newc);
    }
}
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldc = image[sr][sc];
        dfs(image,sr,sc,oldc,color);
        return image;
    }
};