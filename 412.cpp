#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string>res;
        for(int i=1; i<=n; i++){
        	if(i%3==0 && i%5==0)
        		res.push_back("FizzBuzz");
        	else if(i%3==0)
        		res.push_back("Fizz");
        	else if(i%5==0)
        		res.push_back("Buzz");
        	else{
        		ostringstream s;
        		s << i;
        		res.push_back(s.str());
        	}
        }

        return res;
    }
};

int main(int argc, char const *argv[])
{
	int num;
	cin>>num;

	Solution s;
	vector<string>res;
	res = s.fizzBuzz(num);
	for(int i=0; i<res.size(); i++)
		cout<<res[i]<<endl;
	return 0;
}
