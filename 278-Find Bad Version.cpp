/**
 * You are a product manager and currently leading a team to develop a new product.
 *  Unfortunately, the latest version of your product fails the quality check. 
 *  Since each version is developed based on the previous version, all the versions after a bad version are also bad.
 *  Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, 
 *  which causes all the following ones to be bad.
 *  You are given an API bool isBadVersion(version) which will return whether version is bad. 
 *  Implement a function to find the first bad version. You should minimize the number of calls to the API.
 */


#include "bits/stdc++.h"
using namespace std;

bool isBadVersion(int version){
	if(version <= 7)
		return false;
	return true;
}

class Solution {
public:
    int firstBadVersion(int n) {
        long int high = n, low = 1, mid, val;
        while(low<=high){
        	mid = (high+low)/2;
        	if(isBadVersion(mid)){
        		val = mid;
        		high = mid - 1;
        	}
        	else{
        		low = mid + 1;
        	}
        }

        return val;
    }
};

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	Solution s;
	cout<<s.firstBadVersion(num)<<endl;
	return 0;
}