/**
 * You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. 
 * Grid cells are connected horizontally/vertically (not diagonally). 
 * The grid is completely surrounded by water, and there is exactly one island 
 * (i.e., one or more connected land cells). The island doesn't have "lakes" 
 * (water inside that isn't connected to the water around the island). 
 * One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. 
 * Determine the perimeter of the island.
 *
 * input: [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]], [[0,1]]
 * output: 16, 4
 */



#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int islandPerimeter(vector< vector <int> >& grid) {
        int count = 0;
        for(int i=0; i<grid.size(); i++){
        	for(int j=0; j<grid[i].size(); j++){
        		if(grid[i][j]==1){
        			if(i==0 || grid[i-1][j]==0)
        				count++;
        			if(i==grid.size()-1 || grid[i+1][j]==0)
        				count++;
        			if(j==0 || grid[i][j-1]==0)
        				count++;
        			if(j==grid[i].size()-1 || grid[i][j+1]==0)
        				count++;
        		}
        	}
        }
        return count;
    }
};

int main(int argc, char const *argv[])
{
	int n,m, a;
	vector< vector<int> > grid;
	vector<int>tmp;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		tmp.clear();
		for(int j=0; j<m; j++){
			cin>>a;
			tmp.push_back(a);
		}
		grid.push_back(tmp);
	}	
	Solution s;
	cout<<s.islandPerimeter(grid)<<endl;
	return 0;
}