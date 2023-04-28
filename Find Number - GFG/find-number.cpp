//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    long findNumber(long N) {
        long v[] = { 9, 1, 3, 5, 7 };
        long ans = 0;
        while (N > 0) {
            ans = ans * 10 + v[(N % 5)];
            if (N % 5 == 0) {
                N = N / 5;
                N--;
            }
            else
                N /= 5;
        }
        queue<long> q;
        while (ans > 0) {
            q.push(ans % 10);
            ans /= 10;
        }
        while (!q.empty()) {
            ans = ans * 10 + q.front();
            q.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends