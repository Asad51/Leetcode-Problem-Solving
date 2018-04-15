#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int arrangeCoins(int n) {
        int arrangeCoins(int n) {
        if(n < 1)
            return 0;
        for(int i = 1; ;i++){
            n -= i;
            if(n < 0)
                return i-1;
        }
    }
    }
};

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	Solution s;
	cout<<s.arrangeCoins(num)<<"\n";
	return 0;
}