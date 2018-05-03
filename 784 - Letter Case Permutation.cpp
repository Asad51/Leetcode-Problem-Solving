/**
 * Given a string S, we can transform every letter individually to be lowercase or 
 * uppercase to create another string.  
 * Return a list of all possible strings we could create.
 * Input: S = "a1b2"
 * Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
 */


/**
 * Another Solution
 * 
 * class Solution {
    void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};
 */



#include "bits/stdc++.h"
using namespace std;

class Solution {
    vector<string>res;
    int n;
public:
    vector<string> letterCasePermutation(string S) {
    	n = S.size();
        generateString(S, 0);
        return res;
    }
    
    void generateString(string s, int i){
        if(i>=n){
        	res.push_back(s);
            return;
        }

        char ch = s[i];
        if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z')){
        	s[i] = toLowerCase(s[i]);
        	generateString(s, i+1);
        	s[i] = toUpperCase(s[i]);
        	generateString(s, i+1);
        }
        else{
        	generateString(s, i+1);
        }
        s[i] = ch;
    }

    char toUpperCase(char ch){
    	if(ch>='a' && ch<='z')
    		return ch - 32;
    	return ch;
    }

    char toLowerCase(char ch){
    	if(ch>='A' && ch<='Z')
    		return ch + 32;
    	return ch;
    }
};


int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	Solution ss;
	vector<string>res;
	res = ss.letterCasePermutation(s);
	for(int i=0; i<res.size(); i++)
		cout<<res[i]<<endl;
	return 0;
}
