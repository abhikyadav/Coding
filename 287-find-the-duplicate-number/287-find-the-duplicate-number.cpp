class Solution {
public:
    int findDuplicate(vector<int>& A) {
        int n = A.size();
        int count[n] ;
        for(int i= 0; i<n; i++)
        {
            count[i]=0;
        }
        for(int i =0; i<n; i++)
        {
            count[A[i]]++;
        }
        for(int i =0; i<n; i++)
        {
            if(count[i]>=2)
            {
                return i;
            }
        }
        return 0;
    }
};