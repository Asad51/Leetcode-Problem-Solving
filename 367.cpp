#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
     	int i = 1;
     	while (num > 0) {
         	num -= i;
         	i += 2;
     	}
    	return num == 0;
 	}
};

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	Solution s;
	if(s.isPerfectSquare(num))
		cout<<"true"<<"\n";
	else
		cout<<"false"<<"\n";
	
	return 0;
}
