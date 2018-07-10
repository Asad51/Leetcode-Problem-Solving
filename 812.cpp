#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    double largestTriangleArea(vector< vector<int> >& points) {
        int n = points.size();
        double mx = 0;
        for(int i=0; i<n; i++){
        	for(int j=0; j<n; j++){
        		for(int k=0; k<n; k++){
        			mx = max(mx, 0.5*abs(points[i][0]*points[j][1] + points[j][0]*points[k][1] + points[k][0]*points[i][1] - points[i][0]*points[k][1] - points[j][0]*points[i][1] - points[k][0]*points[j][1]));
        		}
        	}
        }
        return mx;
    }
};

int main(int argc, char const *argv[])
{
	vector< vector<int> > points;
	int x, y;
	int n;
	cin>>n;
	points.resize(n);
	for(int i=0; i<n; i++){
		cin>>x>>y;
		points[i].push_back(x);
		points[i].push_back(y);
	}

	Solution s;
	cout<<s.largestTriangleArea(points)<<endl;
	return 0;
}