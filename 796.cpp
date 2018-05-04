/**
 * We are given two strings, A and B.
 * A shift on A consists of taking string A and moving the leftmost character 
 * to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' 
 * after one shift on A. Return True if and only if A can become B after some 
 * number of shifts on A.
 *
 * input: abcde, cdeab, output:true
 * input: abcde, abced, output:false
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()==B.size())
        	return (A+A).find(B) != string::npos;
       	return false;
    }
};

int main(int argc, char const *argv[])
{
	string a, b;
	cin>>a;
	cin>>b;
	Solution s;
	if(s.rotateString(a, b))
		cout<<"true\n";
	else
		cout<<"false\n";
	return 0;
}
