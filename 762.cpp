/**
 * Given two integers L and R, find the count of numbers in the range [L, R] (inclusive) 
 * having a prime number of set bits in their binary representation.
 * (Recall that the number of set bits an integer has is the number of 1s 
 * present when written in binary. 
 * For example, 21 written in binary is 10101 which has 3 set bits. Also, 1 is not a prime.)
 *
 * input: 6,10
 * output: 4
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
    	int count = 0;
    	for(int i=L; i<=R; i++){
    		if(isPrime(countSetBits(i)))
    			count++;
    	}
    	return count;
    }

    int countSetBits(int n)
	{
    	int count = 0;
    	while (n)
    	{
      		n &= (n-1) ;
      		count++;
    	}
    	return count;
    	//return  __builtin_popcount (n);
	}

    bool isPrime(int n){
      	if(n==2)
        	return true;
      	if(n<=1 || n%2==0)
        	return false;
      	for(int i=3; i<=sqrt(n); i+=2)
        	if(n%i==0)
          	return false;
      	return true;
	}
};

int main(int argc, char const *argv[])
{
	int l, r;
	cin>>l>>r;
	Solution s;
	cout<<s.countPrimeSetBits(l, r)<<endl;
	return 0;
}
