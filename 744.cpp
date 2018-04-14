#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
    	int up = upper_bound(letters.begin(), letters.end(), target) - letters.begin();
        if(up >=letters.size())
        	return letters[0];
        else
        	return letters[up];
    }
};

int main(int argc, char const *argv[])
{
	vector<char>let;
	char target, ch;
	int n;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>ch;
		let.push_back(ch);
	}

	cin>>target;
	Solution s;
	cout<<s.nextGreatestLetter(let, target)<<endl;
	return 0;
}
