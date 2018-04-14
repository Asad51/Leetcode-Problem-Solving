#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int tmp;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i=0, j=0;
        for(; i<nums1.size() && j<nums2.size(); ){
        	if(nums1[i]==nums2[j]){
        		res.push_back(nums2[j]);
        		i++;
        		j++;
        	}
        	else if(nums1[i]>nums2[j])
        		j++;
        	else
        		i++;
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	int n1, n2, a;
	vector<int>nums1, nums2, res;
	cin>>n1>>n2;
	for(int i=0; i<n1; i++){
		cin>>a;
		nums1.push_back(a);
	}
	for(int i=0; i<n2; i++){
		cin>>a;
		nums2.push_back(a);
	}

	Solution s;
	res = s.intersect(nums1, nums2);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<endl;
	}

	return 0;
}