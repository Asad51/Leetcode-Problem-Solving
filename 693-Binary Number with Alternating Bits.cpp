/**
 * Given a positive integer, check whether it has alternating bits: 
 * namely, if two adjacent bits will always have different values.
 *
 * input: 5, 7, 11, 10
 * output: true, false, false, true
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
    	int prev = -1, pres;
        while(n!=0){
        	pres = n%2;
        	if(pres==prev)
        		return false;
        	prev = pres;
        	n = n/2;
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.hasAlternatingBits(n)<<endl;
	return 0;
}
