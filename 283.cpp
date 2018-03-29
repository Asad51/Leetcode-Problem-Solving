#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int siz = nums.size();
        vector<int>non_zero, zero;
        for(int i=0; i<siz; i++){
        	if(nums[i]==0){
        		zero.push_back(0);
        	}
        	else{
        		non_zero.push_back(nums[i]);
        	}
        }
        nums.clear();
        for(int i=0; i<non_zero.size(); i++){
        	nums.push_back(non_zero[i]);
        }
        for(int i=0; i<zero.size(); i++){
        	nums.push_back(0);
        }
        for(int i=0; i<siz; i++){
        	cout<<nums[i]<<" ";
        }
    }
};

int main(int argc, char const *argv[])
{
	vector<int> nums;
	int n, a;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		nums.push_back(a);
	}
	Solution s;
	s.moveZeroes(nums);
	return 0;
}