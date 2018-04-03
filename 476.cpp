#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        string s = "";
        int rem, tmp;
        char bit;
        bool isInitZero = true;
        while(num!=0){
        	tmp = num;
        	rem = abs(num%2 - 1);
        	bit = rem + 48;
        	num = num/2;
        	
        	s = s + bit;
        }

        int siz = s.size();
        int res = 0;
        for(int i=siz-1; i>=0; i--){
        	int b = s[i] - 48;
        	res = res + b*pow(2, i);
        }
        return res;
    }
};


int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	Solution s;

	cout<<s.findComplement(num)<<endl;
	return 0;
}