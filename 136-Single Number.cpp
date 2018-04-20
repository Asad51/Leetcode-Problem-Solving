/**
 * Given an array of integers, every element appears twice except for one. Find that single one.
 * Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
 */


/**
 * Another solution:
 * The trick is: A^B^A=B
 * class Solution {
	public:
    	int singleNumber(vector<int>& nums) {
        	if(nums.empty()) return 0;
        	int first = nums[0];
        	for(int i = 1; i<nums.size();i++) {
            	first = first ^ nums[i];
        	}
        	return first;
    	}
	};
 */


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); ){
        	if(nums[i]==nums[i+1]){
        		i += 2;
        	}
        	else{
        		return nums[i];
        	}
        }
    }
};

int main(int argc, char const *argv[])
{
	int n, a;
	vector<int>nums;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		nums.push_back(a);
	}
	Solution s;
	cout<<s.singleNumber(nums)<<"\n";
	return 0;
}