#include "bits/stdc++.h"
using namespace std;

int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int high = n;
        int low = 1;
        while(low<=high){
        	mid = (high-low)/2 + low;
        	int g = guess(mid);
        	if(g==0){
        		return mid;
        	}
        	else if(g==1){
        		low = mid + 1;
        	}
        	else{
        		high = mid - 1;
        	}
        }
    }
};

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;
	Solution s;
	cout<<s.guessNumber(num)<<endl;
	return 0;
}