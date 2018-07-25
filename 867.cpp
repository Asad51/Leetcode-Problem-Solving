#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector< int > > transpose(vector< vector< int > >& A) {
        int n = A.size(), m = A[0].size();
        vector< vector< int > > res;
        vector< int > tmp;
        for(int i = 0; i<m; i++){
        	tmp.clear();
        	for(int j = 0; j<n; j++)
        		tmp.push_back(A[j][i]);
        	res.push_back(tmp);
        }
        return res;
    }	
};

int main(int argc, char const *argv[])
{
	int n, m, c;
	cin>>n>>m;
	vector< vector< int > > A, B;
	vector< int > tmp;
	for(int i=0; i<n; i++){
		tmp.clear();
		for(int j=0; j<m; j++){
			cin>>c;
			tmp.push_back(c);
		}
		A.push_back(tmp);
	}

	Solution s;
	B = s.transpose(A);
	for(int i=0; i<B.size(); i++){
		for(int j=0; j<B[i].size(); j++)
			cout<<B[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
