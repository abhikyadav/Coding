//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool good(int x, vector<int> &nums, int k) {
    long long s = 0, cnt = 0, n = nums.size();
    for(int i=0; i<n; i++) {
        s += nums[i];
        if(s >= x) s = 0, cnt++;
    }
    return cnt >= k + 1;
}

int maxSweetness(vector<int>& sweetness, int N, int K) {
    int s = 0, e = 1e9, ans;
    while(s <= e) {
        int m = (s + e) / 2;
        if(good(m, sweetness, K)) s = m + 1, ans = m;
        else e = m - 1;
    }
    return ans;
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends