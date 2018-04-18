/**
 * Given an integer array with even length, where different numbers 
 * in this array represent different kinds of candies. 
 * Each number means one candy of the corresponding kind. 
 * You need to distribute these candies equally in number to brother and sister. 
 * Return the maximum number of kinds of candies the sister could gain
 *
 * input: [1,1,2,2,3,3], [1,1,2,3], [1,2,3,4]
 * output: 3,2,2
 */


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        set<int>cs;
        cs.insert(candies.begin(), candies.end());
        int s1 = candies.size()/2;
        int s2 = cs.size();
        if(s2 > s1)
        	return s1;
        return s2;
    }
};

int main(int argc, char const *argv[])
{
	int n, a;
	cin>>n;
	vector<int>cans;
	for(int i=0; i<n; i++){
		cin>>a;
		cans.push_back(a);
	}
	Solution s;
	cout<<s.distributeCandies(cans)<<endl;
	return 0;
}
