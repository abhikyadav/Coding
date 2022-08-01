class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();
        if(m==0)
        {
            return 0;
        }
        if(n<m)
        {
            return -1;
        }
        if(n==m)
        {
            for(int i=0; i<n; i++)
            {
                   if(haystack[i] != needle[i])
                   {
                       return -1;
                   }
            }
            return 0;
        }
        else if(n>m)
        {
            int j=0;
            for(int i=0; i<(n-m+1); i++)
            {
                for( j=0; j<m; j++)
                {
                    if(haystack[i+j]==needle[j])
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
                if(j==m)
                {
                    return i;
                }
            }
        }
        return -1;
    }
};