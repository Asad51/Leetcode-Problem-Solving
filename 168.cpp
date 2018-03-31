#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        map <int, char> sheet;
        for(int i=0; i<26; i++){
        	sheet.insert(make_pair(i+1, 'A'+i));
        }
        int rem = 0;
        string s = "";
        while(n!=0){
        	rem = n%26;
            n = n/26;
            if(rem==0){
                rem = 26;
                n = n-1;
            }
        	s = s + sheet.find(rem)->second;
        }
        reverse(s.begin(), s.end());
        return s;
    }
};

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	Solution ss;
	cout<<ss.convertToTitle(num)<<endl;
	return 0;
}