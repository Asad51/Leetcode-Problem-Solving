#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int i=0; i<len; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m]>0 ? -nums[m] : nums[m];
        }

        vector<int> res;
        for(int i = 0; i<len; i++) {
            if(nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums, res;
	int n, a;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		nums.push_back(a);
	}

	Solution s;
	res = s.findDisappearedNumbers(nums);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<" ";
	}
	return 0;
}
