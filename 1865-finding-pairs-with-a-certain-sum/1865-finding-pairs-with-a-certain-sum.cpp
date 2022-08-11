class FindSumPairs {
public:
    vector<int> b;
    map<int,int> first;
    unordered_map<int,int>second;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        b = nums2;
        for(int x : nums2)second[x]++;
        for(int x : nums1)first[x]++;
    }
    
    void add(int index, int val) {
        second[b[index]]--;
        b[index]+=val;
        second[b[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto it = first.begin(); it != first.end() && it->first<tot ; it++)
        if(second.count(tot-it->first)) ans += it->second * second[tot-it->first];
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */