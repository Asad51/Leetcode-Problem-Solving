#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for(int i=0; i<str.size(); i++){
        	if(str[i]>='A' && str[i]<='Z')
        		str[i] = str[i] + 32;
        }
        return str;
    }
};

int main(int argc, char const *argv[])
{
	string s;
	cin>>s;
	Solution ss;
	cout<<ss.toLowerCase(s)<<"\n";
	return 0;
}
