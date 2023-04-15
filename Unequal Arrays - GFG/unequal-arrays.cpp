//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    long long solve(int N, vector<int> &A, vector<int> &B) {
        // code here
        // Authored By: Vasanth Reddy
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        vector<vector<int>> arr(2);
        for(int i=0;i<N;i++){
            arr[(2 + A[i]%2)%2].push_back(A[i]);
        }
        long long neg = 0,pos = 0;
        for(int i=N-1;i>=0;i--){
            if(arr[(2 + B[i]%2)%2].empty()) return -1;
            int x = arr[(2 + B[i]%2)%2].back();
            arr[(2 + B[i]%2)%2].pop_back();
            if(x >= B[i]){
                neg += (x - B[i])/2;
            }
            else pos += (B[i] - x)/2;
        }
        return neg == pos ? pos : -1;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        
        vector<int> B(N);
        Array::input(B,N);
        
        Solution obj;
        long long res = obj.solve(N, A, B);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends