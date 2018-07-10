#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word[0]>='A' && word[0]<='Z'){
        	bool isUpper = false, isLower = false;

        	for(int i=1; i<word.size(); i++){
        		if(word[i]>='A' && word[i]<='Z')
        			isUpper = true;
        		else
        			isLower = true;
        	}
        	if(isUpper && isLower)
        		return false;
        }
        else{
        	for(int i=1; i<word.size(); i++){
        		if(word[i]>='A' && word[i]<='Z')
        			return false;
        	}
        }
        return true;
    }
};

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	Solution ss;
	cout<<ss.detectCapitalUse(s)<<endl;
	return 0;
}
