#include "bits/stdc++.h"
using namespace std;

class Solution {
    vector<int>visited;
    int target;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int s = nums.size();
        int sum = 0;
        for(int i=0; i<s; i++){
        	sum += nums[i];
        }
        if(k<=0 || sum%k != 0)
        	return false;
        visited.clear();
        for(int i=0; i<s; i++)
            visited.push_back(0);
        target = sum/k;
        return canPartition(nums, 0, k, 0, 0);
    }

    bool canPartition(vector<int>& nums, int i, int k, int sum, int count){
        if(k==1)
            return true;
        if(sum==target && count>0)
            return canPartition(nums, 0, k-1, 0, 0);
        for(int j=0; j<nums.size(); j++){
            if(!visited[j]){
                visited[j] = 1;
                if(canPartition(nums, j+1, k, sum + nums[j], count + 1))
                    return true;
                visited[j] = 0;
            }
        }
        return false;
    }
};

int main(int argc, char const *argv[])
{
	int n, a, k;
	cin>>n>>k;
	vector<int>nums;
	for(int i=0; i<n; i++){
		cin>>a;
		nums.push_back(a);
	}
	Solution s;
	cout<<s.canPartitionKSubsets(nums, k)<<"\n";
	return 0;
}
