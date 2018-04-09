#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s;
        vector<int>res;
        set<int>:: iterator it;
        sort(nums1.begin(), nums1.end());
        for(int i=0; i<nums2.size(); i++){
            if(binary_search(nums1.begin(), nums1.end(), nums2[i]))
                s.insert(nums2[i]);
        }
        
        for(it=s.begin(); it!=s.end(); it++){
            res.push_back(*it);
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	int n1, n2, a;
	cin>>n1>>n2;
	vector<int>v1, v2, res;
	for(int i=0; i<n1; i++){
		cin>>a;
		v1.push_back(a);
	}

    for(int i=0; i<n2; i++){
        cin>>a;
        v2.push_back(a);
    }

	Solution ss;
	res = ss.intersection(v1, v2);
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
	return 0;
}