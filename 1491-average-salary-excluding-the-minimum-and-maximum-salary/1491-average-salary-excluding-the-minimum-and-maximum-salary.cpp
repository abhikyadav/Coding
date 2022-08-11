class Solution {
public:
    double average(vector<int>& salary) {
        int maxi= INT_MIN;
        int mini = INT_MAX;
        double avg = 0;
        int n = salary.size();
        for(int i=0; i<salary.size(); i++)
        {
            avg +=salary[i];
            if(maxi<salary[i])
            {
                maxi=salary[i];
            }
            if(mini>salary[i])
            {
                mini = salary[i];
            }
        }
        avg = avg-mini-maxi;
        return (avg/(n-2));
    }
};