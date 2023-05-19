//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int groupSize, vector<int> &hand) 
    {
        map <int,int> mp;
        
        for (auto it: hand)
        {
            mp[it]++;
        }
        
        int prev;
        
        while(!mp.empty())
        {
            prev = mp.begin()->first;
            
            for (int i=prev; i<prev+groupSize; i++)
            {
                if (mp.find(i)==mp.end())
                    return false;
                
                if (mp[i]==1)
                    mp.erase(i);
                else
                    mp[i]--;
            }
        }
        return true;
        
        
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends