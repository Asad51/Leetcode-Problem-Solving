#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int>res;
        int tmp;
        for(int i=0; i<numbers.size(); i++){
        	tmp = target - numbers[i];
        	if(binary_search(numbers.begin(), numbers.end(), tmp)){
        		res.push_back(i+1);
        		res.push_back(upper_bound(numbers.begin(), numbers.end(), tmp) - numbers.begin());
        		break;
        	}
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	vector<int>nums, res;
	int n, target, a;
	cin>>n>>target;
	for(int i=0; i<n; i++){
		cin>>a;
		nums.push_back(a);
	}

	Solution s;
	res = s.twoSum(nums, target);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<endl;
	}
	return 0;
}
