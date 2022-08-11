class Solution {
public:
    int climbStairs(int n) {
        int first =1; int second =2;
        if(n==1)
        {
            return first;
        }
        if(n==2)
        {
            return second;
        }
        int third =0;
        for(int i=3; i<=n; i++)
        {
            third = second + first;
            first =second;
            second = third;
        }
        return third;
    }
};