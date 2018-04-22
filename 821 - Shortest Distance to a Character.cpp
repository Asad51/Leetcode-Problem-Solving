/**
 * Given a string S and a character C, return an array of integers representing the 
 * shortest distance from the character C in the string.
 *
 * input: S = "loveleetcode", C = 'e'
 * output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]
 */


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int>res, cpos;
        int min_dist;
        for(int i=0; i<S.size(); ++i){
        	if(S[i]==C){
        		cpos.push_back(i);
        	}
        }

        for(int i=0; i<S.size(); ++i){
        	if(binary_search(cpos.begin(), cpos.end(), i)){
        		min_dist = 0;
        	}
        	else{
        		int p1,p2;
        		p1 = lower_bound(cpos.begin(), cpos.end(), i) - cpos.begin();
        		p2 = upper_bound(cpos.begin(), cpos.end(), i) - cpos.begin();
        		if(p1==0)
        			min_dist = cpos[p2] - i;
        		else if(p2>=cpos.size())
        			min_dist = i - cpos[p1-1];
        		else{
        			min_dist = min(abs(cpos[p2] - i), abs(i - cpos[p1-1]));
        		}

        	}

        	res.push_back(abs(min_dist));
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	string s;
	char ch;
	cin>>s>>ch;
	vector<int>res;
	Solution ss;

	res = ss.shortestToChar(s, ch);
	for(int i=0; i<res.size(); ++i){
		cout<<res[i]<<endl;
	}

	return 0;
}
