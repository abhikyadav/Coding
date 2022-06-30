class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count;
    if (n == 0) 
    {
        count = 0;
    }
    else 
    {
        count = 1;
    }
    n = n & (n-1);
    
    while(n != 0) {
        n = n & (n-1);
        count++;
    }
    return count;
    }
};