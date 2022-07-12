// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    struct meeting
    {
        int start;
        int end;
        int pos;
    };
     bool comparator(struct meeting m1, meeting m2)
     {
         if(m1.end < m2.end)
         {
             return true;
         }
         else if(m1.end > m2.end)
         {
             return false;
         }
         else if(m1.pos < m2.pos)
         {
            return false; 
         }
         
     }
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        int count=1;
        vector<vector<int>> meetings;
        for(int i=0; i<n; i++){
            meetings.push_back({start[i],end[i]});
        }
        
        sort(meetings.begin(),meetings.end());
        
        int low=meetings[0][1];
        for(int i=1; i<n ; i++){
            if(meetings[i][0]>low){
                count++;
                low=meetings[i][1];
            }
            else{
                low=min(low,meetings[i][1]);
            }
        }
        
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends