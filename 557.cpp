#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string>words;
        words = split(s, ' ');
        string reverseStr = "";
        for(int i=0; i<words.size(); i++){
        	reverse(words[i].begin(), words[i].end());
        	if(i==0){
        		reverseStr = words[i];
        	}
        	else
        		reverseStr = reverseStr + " " + words[i];
        }

        return reverseStr;
    }

    vector<string> split(string str, char delim){
    	string s = "";
    	vector<string> sp;
    	for(int i=0; i<str.size(); i++){
    		if(str[i] == delim){
                sp.push_back(s);
                s = "";
    		}
    		else{
    			s = s + str[i];
    		}
    	}
        sp.push_back(s);
    	return sp;
    }
};

int main(int argc, char const *argv[])
{
	string s;
	getline(cin,s);
	Solution ss;
	cout<<ss.reverseWords(s)<<endl;
	return 0;
}
