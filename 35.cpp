#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index;
        index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();

        return index;
    }
};

int main(int argc, char const *argv[])
{
	int n;
	vector<int>nums;
	int target;
	cin>>n;
	int a;
	for(int i = 0; i<n; i++){
		cin>>a;
		nums.push_back(a);
	}
	cin>>target;
	Solution s;
	cout<<s.searchInsert(nums, target)<<"\n";
	return 0;
}
