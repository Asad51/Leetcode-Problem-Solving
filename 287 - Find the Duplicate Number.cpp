/**
 * Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
 * prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
 * find the duplicate one.
 * Note:
 * You must not modify the array (assume the array is read only).
 * You must use only constant, O(1) extra space.
 * Your runtime complexity should be less than O(n2).
 * There is only one duplicate number in the array, but it could be repeated more than once.
 *
 * input: [1,1], [2,2,2,2,2],[1,2,3,4,2]
 * output: 1,2,2
 */




#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
        	int tmp = abs(nums[i]);
        	if(nums[tmp-1]<0)
        		return tmp;
            nums[tmp-1] = -1 * nums[tmp-1];
        }
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
	cout<<s.findDuplicate(nums)<<endl;
	return 0;
}
