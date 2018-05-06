/**
 * In a string S of lowercase letters, these letters form consecutive groups of the same character.
 * For example, a string like S = "abbxxxxzyy" has the groups "a", "bb", "xxxx", "z" and "yy".
 * Call a group large if it has 3 or more characters. 
 * We would like the starting and ending positions of every large group.
 * The final answer should be in lexicographic order.
 */


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int> > largeGroupPositions(string S) {
        vector< vector<int> >res;
        vector<int>tmp;
        int i=0, j=0;
        for(; i<S.size(); i++){
        	while(j<S.size() && S[i]==S[j]){
        		i++;
        	}
        	if(i-j>=3){
        		tmp.push_back(j);
        		tmp.push_back(i-1);
        		res.push_back(tmp);
        	}
        	j = i;
        	tmp.clear();
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	vector< vector<int> > groups;
	Solution ss;
	groups = ss.largeGroupPositions(s);
	for(int i=0; i<groups.size(); i++){
		for(int j=0; j<groups[i].size(); j++)
			cout<<groups[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}