struct Segment {
    int start = -1;
    int end = -1;
    bool complete = false;
    int64_t startSum = 0;
    int64_t endSum = 0;
    int64_t maxSum = 0;
};

ostream & operator << (ostream & os, Segment const& s) {
	return os << s.maxSum;
}


void combine(Segment const& s1, Segment const& s2, Segment& ret) {
    ret.end = s2.end != -1 ? s2.end : s1.end;
    ret.start = s1.start != -1 ? s1.start : s2.start;
    ret.complete = s1.complete && s2.complete;
    
    bool connect = s1.end == s2.start;
    ret.startSum = s1.complete && connect ? s1.maxSum + s2.startSum : s1.startSum;
    ret.endSum = s2.complete && connect ? s1.endSum + s2.maxSum : s2.endSum;
    
    ret.maxSum = max(s1.maxSum, s2.maxSum);
    if (connect) {
        ret.maxSum = max(ret.maxSum, s1.endSum + s2.startSum);
    }
}

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<vector<Segment>> levels;
        levels.push_back(vector<Segment>(n));
        
        for (int i = 0; i < n; ++i) {
            levels[0][i].start = i;
            levels[0][i].end = i + 1;
            levels[0][i].complete = true;
            levels[0][i].startSum = nums[i];
            levels[0][i].endSum = nums[i];
            levels[0][i].maxSum = nums[i];
        }
        
        while (levels.back().size() > 1) {
            if (levels.back().size() % 2 == 1) {
                levels.back().push_back(Segment());
            }
            levels.push_back(vector<Segment>());
            vector<Segment>& next = levels.back();
            vector<Segment>& prev = levels[levels.size() - 2];
            
            for (int i = 0; i < prev.size(); i += 2) {
                Segment seg;
                combine(prev[i], prev[i + 1], seg);
                next.push_back(seg);
            }
        }
        
        vector<long long> ret; 
        for (int q: removeQueries) {
            levels[0][q] = Segment();
            for (int level = 1; level < levels.size(); ++level) {
                q /= 2;
                combine(levels[level - 1][2 * q], levels[level - 1][2 * q + 1], levels[level][q]);
            }
            ret.push_back(levels.back().front().maxSum);
        }
        return ret;
    }
};