class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,string> mp = {{1,"I"},{5,"V"},{10,"X"},{50,"L"},{100,"C"},{500,"D"},{1000,"M"}};
        int x=1;
        string ans = "";
        while(num>0)
        {
            int d=num%10;
            d*=x;
            while(d>0)
            {
                if(mp.find(d)!=mp.end())
                {
                    ans = mp[d]+ans;
                    d=0;
                }
                else if(mp.find(d+x)!=mp.end())
                {
                    ans = mp[x] + mp[d+x] +ans;
                    d=0;
                }
                else
                {
                    ans = mp[x]+ans;
                    d-=x;
                }
            }
            num/=10;
            x*=10;
        }
        return ans;
    }
};