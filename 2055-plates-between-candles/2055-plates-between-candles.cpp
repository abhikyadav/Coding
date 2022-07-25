class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> v;
        
        for(int i=0; i<s.size(); ++i){
            if( s[i]=='|'){
                v.emplace_back(i);
            }
        }
        vector<int> ans;
        for(auto i: queries){
            if( i[0]==i[1] || i[1]-i[0]==1){
                ans.emplace_back(0);
                continue;
            }
            int st = lower_bound(v.begin(), v.end(),i[0]) - v.begin();
            int e = upper_bound(v.begin(), v.end(), i[1]) - v.begin();
            
            --e;
            int count =  (v[e]-v[st]+1)- (e-st+1);
            count = count<0? 0: count;
            ans.emplace_back( count);
        }
        return ans;
    }
};