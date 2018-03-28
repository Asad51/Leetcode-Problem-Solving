#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i+=2){
          sum = sum + min(nums[i], nums[i+1]);
        }
        return sum;
    }
};

int main(int argc, char const *argv[]) {
  vector<int> nums;
  int n, a;
  cin>>n;
  for(int i=0; i<2*n; i++){
    cin>>a;
    nums.push_back(a);
  }
  Solution ss;
  cout<<ss.arrayPairSum(nums)<<endl;
  return 0;
}
