#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int c=0;
        for(int i=0; i<bits.size(); i++){
        	if(bits[i]==0){
        		c++;
        	}
            else{
                c = 0;
                i++;
            }
        }
        
        return c;
    }
};


int main(int argc, char const *argv[])
{
	int n,a;
	vector<int> bits;
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		bits.push_back(a);
	}
	Solution ss;
	cout<<ss.isOneBitCharacter(bits)<<endl;

	return 0;
}