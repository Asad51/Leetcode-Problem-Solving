/**
 * You are given two arrays (without duplicates) nums1 and nums2 
 * where nums1’s elements are subset of nums2. Find all the next greater numbers 
 * for nums1's elements in the corresponding places of nums2.
 * The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. 
 * If it does not exist, output -1 for this number.
 *
 * Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
 * Output: [-1,3,-1]
 *
 * Input: nums1 = [2,4], nums2 = [1,2,3,4]
 * Output: [3,-1]
 *
 * Input: nums1 = [1,3,5,2,4], nums2 = [6,5,4,3,2,1,7].
 * Output: [7,7,7,7,7]
 */


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
    	vector<int>res;
        for(int i=0; i<findNums.size(); i++){
        	bool isFound = false;
        	bool isGreater = false;
        	for(int j=0; j<nums.size(); j++){
        		int tmp = findNums[i];
        		if(tmp==nums[j])
        			isFound = true;
        		if(isFound && nums[j]>tmp){
        			res.push_back(nums[j]);
        			isGreater = true;
        			break;
        		}
        	}
        	if(!isGreater)
        		res.push_back(-1);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	int n1, n2, a;
	vector<int>nums1, nums2, res;
	cin>>n1>>n2;
	while(n1--){
		cin>>a;
		nums1.push_back(a);
	}

	while(n2--){
		cin>>a;
		nums2.push_back(a);
	}

	Solution s;

	res = s.nextGreaterElement(nums1, nums2);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<endl;
	}

	return 0;
}
