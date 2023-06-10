//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define ll long long

// } Driver Code Ends

class Solution
{
public:
    void reverse(int i, int j, int arr[])
    {
        if (i < j)
            std::reverse(arr + i, arr + j);
    }
    void merge(int l, int mid, int r, int arr[])
    {
        int i = l, j = mid + 1;
        while (i <= mid and arr[i] < 0)
            i++;

        while (j <= r and arr[j] < 0)
            j++;

        reverse(i, mid + 1, arr);
        reverse(mid + 1, j, arr);
        reverse(i, j, arr);
    }
    void mergeSort(int l, int r, int arr[])
    {
        if (l < r)
        {
            int mid = (l + r) / 2;
            mergeSort(l, mid, arr);
            mergeSort(mid + 1, r, arr);
            merge(l, mid, r, arr);
        }
    }
    void Rearrange(int arr[], int n)
    {
        mergeSort(0, n - 1, arr);
    }
};

//{ Driver Code Starts.
void Rearrange(int arr[], int n);

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        long long j=0;
        Solution ob;
        ob.Rearrange(arr, n);
      
        for (int i = 0; i < n; i++) 
            cout << arr[i] << " "; 
        cout << endl;  
    }
    return 0; 
} 
// } Driver Code Ends