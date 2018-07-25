#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binaryGap(int N) {
    	vector<char>bits;
    	while(N){
    		char ch = (N%2) + 48;
    		//cout<<ch<<endl;
    		bits.push_back(ch);
    		N /= 2;
    	}
    	int mx = 0, c = 0;
    	for(int i=bits.size()-2; i>=0; i--){
    		if(bits[i]=='1'){
    			mx = max(mx, c+1);
    			c = 0;
    		}
    		else
    			c++;
    	}
    	return mx;
    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.binaryGap(n)<<endl;
	return 0;
}