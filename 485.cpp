#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxn = 0, count = 0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==1){
                count++;
                if(count>maxn){
                    maxn = count;
                }
            }
            else{
                count = 0;
            }
        }
        return maxn;
    }
};

int main(int argc, char const *argv[]) {
    vector<int> nums;
    int n, a;
    cin>>n;
    for(int i=0; i<n; i++){
      cin>>a;
      nums.push_back(a);
    }
    Solution ss;
    cout<<ss.findMaxConsecutiveOnes(nums)<<endl;
    return 0;
}
