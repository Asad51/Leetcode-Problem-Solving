/**
 * Implement int sqrt(int x).
 * Compute and return the square root of x.
 * x is guaranteed to be a non-negative integer.
 * input: 4, 7, 9, 15
 * output: 2, 2, 3, 3
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        long int low = 1, high = x, mid, fval;
        int val = 0;
        while(low<=high){
        	mid = (high+low)/2;
        	if(mid*mid <= x){
        		val = mid;
        		low = mid + 1;
        		if((mid+1)*(mid+1) > x)
        			break;
        	}
        	else{
        		high = mid-1;
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
	cout<<s.mySqrt(num)<<endl;
	return 0;
}