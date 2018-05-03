#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isVowel(char ch){
        string s = "AEIOUaeiou";
        return binary_search(s.begin(), s.end(), ch);
    }
    string toGoatLatin(string S) {
        char pre;
        string res = "";
        vector<string>words;
        words = split(S, ' ');
        for(int i=0; i<words.size(); i++){
            pre = words[i][0];
            if(isVowel(pre)){
                res = res + words[i] + "ma";
            }
            else{
                char tmp = words[i][0];
                for(int j=1; j<words[i].size(); j++){
                    res = res + words[i][j];
                }
                res = res + tmp + "ma";
            }
            for(int j=0; j<=i; j++){
                res = res + 'a';
            }
            if(i!=words.size()-1)
                res = res + ' ';
        }
        return res;
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

int main(){
    string s;
    getline(cin, s);
    Solution ss;
    cout<<ss.toGoatLatin(s)<<endl;
    return 0;
}
