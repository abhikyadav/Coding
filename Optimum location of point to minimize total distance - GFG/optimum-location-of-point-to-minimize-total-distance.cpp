//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    double findTotalDistance(tuple<int, int, int> &l, vector<pair<int,int>> &p, int n, double x){
        double a= get<0>(l);
        double b = get<1>(l);
        double c = get<2>(l);
        double y = -1*(c + (a*x))/b;
        double distance = 0;
        for(auto &e : p){
            double x1 = e.first;
            double y1 = e.second;
            distance += sqrt((x1 - x)*(x1 - x) + (y1 - y)*(y1 - y));
        }
        return distance;
    }
    
    
    
    double findOptimumCost(tuple<int,int,int>l, vector<pair<int,int>>p, int n){
	    double low = -1e6;
	    double high = 1e6;
	    double eps = 1e-6;
	    while(high - low > eps){
	        double x1 = low + (high - low)/3;
	        double x2 = high - (high - low)/3;
	        double d1 = findTotalDistance(l, p, n, x1);
	        double d2 = findTotalDistance(l, p, n, x2);
	        if(d1 > d2){
	            low = x1;
	        }
	        else if(d1 < d2){
	            high = x2;
	        }
	        else{
	            low = x1;
	            high = x2;
	        }
	    }
	    return (findTotalDistance(l, p, n, low));
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    tuple<int,int,int>line;
	    int a, b, c;
	    cin >> a >> b >> c;
	    line = make_tuple(a, b, c);
	    int n;
	    cin >> n;
	    vector<pair<int,int>>points;
	    for(int i = 0 ; i < n; i++){
	        int x, y;
	        cin >> x >> y;
	        points.push_back({x, y});
	    }

	    Solution ob;
	    double ans = ob.findOptimumCost(line, points, n);

	    cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

// } Driver Code Ends