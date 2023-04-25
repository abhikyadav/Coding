//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats){
        int ct=0,ans=0;
        bool fl=false;
        for(int i=0;i<m;i++)
        {
            if(seats[i]==1)
            {
                if(fl==false)
                ct-=1;
                else
                ct-=2;
                if(ct<0)
                {
                    ct=0;
                    continue;
                }
                if(ct%2==0)
                ans+=ct/2;
                else
                ans+=ct/2+1;
                ct=0;
                fl=true;
            }
            else
            ct++;
        }
        if(fl!=false)
                ct-=1;
                if(ct<0)
                ct=0;
                if(ct%2==0)
                ans+=ct/2;
                else
                ans+=ct/2+1;
        if(ans>=n)
        return 1;
        return 0;
        // Write your code here.
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends