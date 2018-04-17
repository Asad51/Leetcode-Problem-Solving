/**
 * Given a n x n matrix where each of the rows and columns are sorted in ascending order, 
 * find the kth smallest element in the matrix.
 * Note that it is the kth smallest element in the sorted order, not the kth distinct element.
 *
 * input: {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}}
 * output: 13
 */

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int kthSmallest(vector< vector<int> >& matrix, int k) {
        int siz = matrix.size();
        vector<int>tmp;
        for(int i=0; i<siz; i++){
        	for(int j=0; j<siz; j++){
        		tmp.push_back(matrix[i][j]);
        	}
        }
        sort(tmp.begin(), tmp.end());

        return tmp[k-1];
    }
};

int main(int argc, char const *argv[])
{
	int n, k, a;
	cin>>n>>k;
	vector< vector<int> >matrix;
	vector<int>tmp;
	for(int i=0; i<n; i++){
		tmp.clear();
		for(int j=0; j<n; j++){
			cin>>a;
			tmp.push_back(a);
		}
		matrix.push_back(tmp);
	}

	Solution s;
	cout<<s.kthSmallest(matrix, k)<<endl;
	return 0;
}