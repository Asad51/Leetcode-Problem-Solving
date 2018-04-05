#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int addDigits(int num) {
        int n = recursiveAdd(num);
        
        return n;
    }
    
    int recursiveAdd(int num){
        if(num/10==0)
            return num;
        int sum = 0, ret;
        while(num!=0){
            sum = sum + num%10;
            num = num/10;
        }
        ret = recursiveAdd(sum);
        return ret;
    }
};

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;

	Solution s;
	cout<<s.addDigits(num)<<endl;
	return 0;
}
