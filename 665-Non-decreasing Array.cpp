/**
 * Given an array with n integers, your task is to check if it could become non-decreasing 
 * by modifying at most 1 element.
 * We define an array is non-decreasing if array[i] <= array[i + 1] holds for every i (1 <= i < n).
 *
 * input: [4,3,2], [4,2,1], [3,4,2,3], [2,3,3,2,4]
 * output: true, false, false, true
 */



#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;
        for(int i=1; i<nums.size(); i++){
        	if(nums[i-1]>nums[i]){
        		cnt++;
        		int tmp = nums[i-1];
        		nums[i-1] = nums[i];
        		if(is_sorted(nums.begin(), nums.end()))
        			continue;
        		nums[i] = nums[i-1] = tmp;
        		if(!is_sorted(nums.begin(), nums.end()))
        			return false;
        		if(cnt>1)
        			return false;
        	}
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	int n, a;
	cin>>n;
	vector<int>nums;
	for(int i=0; i<n; i++){
		cin>>a;
		nums.push_back(a);
	}
	Solution s;
	cout<<s.checkPossibility(nums)<<endl;
	return 0;
}
