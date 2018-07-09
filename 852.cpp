#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int sz = A.size();
        for(int i = 1; i<sz; i++)
        {
        	if(A[i]<A[i-1])
        		return i-1;
        }
        return sz-1;
    }
};

int main(int argc, char const *argv[])
{
	int n, m;
	cin>>n;
	vector<int> a;
	for(int i=0; i<n; i++){
		cin>>m;
		a.push_back(m);
	}
	Solution s;
	cout<<s.peakIndexInMountainArray(a)<<"\n";
	return 0;
}
