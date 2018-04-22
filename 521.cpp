/**
 * Given a group of two strings, you need to find the longest uncommon subsequence of 
 * this group of two strings. The longest uncommon subsequence is defined as the 
 * longest subsequence of one of these strings and this subsequence should not be 
 * any subsequence of the other strings.
 * A subsequence is a sequence that can be derived from one sequence by deleting 
 * some characters without changing the order of the remaining elements. Trivially, 
 * any string is a subsequence of itself and an empty string is a subsequence of any string.
 * The input will be two strings, and the output needs to be the length of the 
 * longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
 *
 * Input: "aba", "cdc"
 * Output: 3
 */


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size() != b.size())
        	return max(a.size(), b.size());
        if(a != b)
        	return b.size();
        return -1;
    }
};

int main(int argc, char const *argv[])
{
	string s1, s2;
	cin>>s1>>s2;
	Solution s;
	cout<<s.findLUSlength(s1, s2)<<endl;
	return 0;
}