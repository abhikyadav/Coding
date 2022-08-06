class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        vector<pair<int, int>>cord;
        for(int i=0;i<in.size();i++) {
            cord.push_back({in[i][0],in[i][1]});
        }
        sort(cord.begin(),cord.end());
        int currentx = cord[0].first;
        int currenty = cord[0].second;
        vector<vector<int>>ans;
        for(int i=1;i<in.size();i++) {
            if(cord[i].first<=currenty) {
                currenty = max(currenty, cord[i].second);
            }
            else {
                ans.push_back({currentx,currenty});
                currentx = cord[i].first;
                currenty= cord[i].second;
            }
        }
        ans.push_back({currentx,currenty});
        return ans;
    }
};