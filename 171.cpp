#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        map<char, int> mp;
        int sum = 0;
        for(int i=0; i<26; i++){
            mp.insert(make_pair('A'+i, i+1));
        }
        for(int i=0, j=s.size()-1; i<s.size()-1; i++, j--){
        	sum = sum + (s[i]-'A'+1)*pow(26, j);
        }
        sum = sum + mp.find(s[s.size()-1])->second;
        return sum;
    }
};


int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	Solution ss;
	cout<<ss.titleToNumber(s)<<endl;

	return 0;
}