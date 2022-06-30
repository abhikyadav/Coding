class Solution {
public:
    int getSum(int a, int b) {
        if(a==0)
        {
            return b;
        }
        if(b==0)
        {
            return a;
        }
        if(a<0 && b<0)
        {
            for(int i=b;i<0;i++)
        {
            a--;
        }
        }
            if(a<0 && b>0)
        {
                int temp = a;
                a=b;
                b=temp;
            for(int i=b;i>0;i++)
        {
            a++;
        }
        }
        if(a>0 && b<0)
        {
            for(int i=b;i<0;i++)
        {
            a--;
        }
        }
            else
            {
              for(int i=0;i<b;i++)
        {
            a++;
        } 
            }
        return a;
    }
};