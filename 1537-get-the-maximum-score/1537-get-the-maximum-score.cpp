class Solution {
public:
    int maxSum(vector<int>& A, vector<int>& B) {
        constexpr int kMod = 1e9 + 7;
        long m = A.size();
        long n = B.size();
        long long i=0,j=0,sumA=0,sumB=0,maxsum =0;
        while(i<m && j<n)
        {
            if(A[i]==B[j])
            {
                sumA += A[i];
                sumB += B[j];
                maxsum += max(sumA, sumB);
                sumA=0;
                sumB=0;
                i++;
                j++;
            }
            else if(A[i]<B[j])
            {
                sumA+=A[i];
                i++;
            }
            else
            {
                sumB+=B[j];
                j++;
            }
        }
        while(i<m)
        {
            sumA+=A[i];
            i++;
        }
        while(j<n)
        {
            sumB+=B[j];
            j++;
        }
        if(sumA>sumB)
        {
            maxsum+=sumA;
        }
        else
        {
            maxsum+=sumB;
        }
        return maxsum%kMod;
    }
};