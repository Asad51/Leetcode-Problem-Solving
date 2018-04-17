/**
 * ou're now a baseball game point recorder.
 * Given a list of strings, each string can be one of the 4 following types:
 * Integer (one round's score): Directly represents the number of points you get in this round.
 * "+" (one round's score): Represents that the points you get in this round are the sum of the last two valid round's points.
 * "D" (one round's score): Represents that the points you get in this round are the doubled data of the last valid round's points.
 * "C" (an operation, which isn't a round's score): Represents the last valid round's points you get were invalid and should be removed.
 * Each round's operation is permanent and could have an impact on the round before and the round after.
 * You need to return the sum of the points you could get in all the rounds.
 *
 * input: ["5","2","C","D","+"], ["5","-2","4","C","D","9","+","+"]
 * output: 30, 27
 */


/**
 * We can solve this problem different ways
 * using stack, vector, linkedlist
 */



#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
    	int sum = 0, f = 0, s = 0;
    	vector<int>nums;
        for(int i=0; i<ops.size(); i++){
        	
        	if(ops[i]=="D"){
        		f = nums.back()*2;
        	}
        	else if(ops[i]=="C"){
        		sum -= nums.back();
        		nums.pop_back();
        		continue;
        	}
        	else if(ops[i]=="+"){
        		f = nums[nums.size()-1] + nums[nums.size()-2];
        	}
        	else{
        		istringstream iss(ops[i]);
        		iss >> f;
        	}
        	sum += f;
        	nums.push_back(f);
        }
        return sum;
    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	string a;
	vector<string>ops;
	for(int i=0; i<n; i++){
		cin>>a;
		ops.push_back(a);
	}

	Solution s;
	cout<<s.calPoints(ops)<<endl;
	return 0;
}
