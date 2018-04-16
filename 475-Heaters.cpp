/**
 * Winter is coming! Your first job during the contest is to design a standard heater with fixed warm radius
 * to warm all the houses. Now, you are given positions of houses and heaters on a horizontal line, find out 
 * minimum radius of heaters so that all houses could be covered by those heaters.
 * So, your input will be the positions of houses and heaters seperately, 
 * and your expected output will be the minimum radius standard of heaters.
 *
 * input: {[1,2,3],[2]}, {[1,2,3,4],[1,4]}
 * output: 1, 1
 */



#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
    	sort(heaters.begin(), heaters.end());
    	long int count = 0, rad = 0, max_rad = 0, pos1, pos2, tmp;
        for(int i=0; i<houses.size(); i++){
        	pos1 = 0, pos2 = 0;
        	if(!binary_search(heaters.begin()+count, heaters.end(), houses[i])){
        		tmp = lower_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
        		if(tmp!=0){
        			pos1 = abs(houses[i] - heaters[tmp-1]);
        		}
        		
        		tmp = upper_bound(heaters.begin(), heaters.end(), houses[i]) - heaters.begin();
        		if(tmp<heaters.size()){
        			pos2 = abs(houses[i] - heaters[tmp]);
        		}
        		
        		if(pos1==0){
        			rad = pos2;
        		}
        		else if(pos2==0){
        			rad = pos1;
        		}
        		else{
        			rad = min(pos1, pos2);
        		}
        		max_rad = max(max_rad, rad);
        	}
        }
        return max_rad;
    }
};

int main(int argc, char const *argv[])
{
	int n, m, a;
	cin>>n>>m;
	vector<int>houses, heaters;
	for(int i=0; i<n; i++){
		cin>>a;
		houses.push_back(a);
	}
	for(int i=0; i<m; i++){
		cin>>a;
		heaters.push_back(a);
	}
	Solution s;
	cout<<s.findRadius(houses, heaters)<<endl;
	return 0;
}
