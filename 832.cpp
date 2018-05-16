#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector< vector<int> > flipAndInvertImage(vector<vector<int> >& A) {
        int n = A.size();
        for(int i=0; i<n; i++){
            reverse(A[i].begin(), A[i].end());
            int m =A[i].size();
            for(int j=0; j<m; j++){
                if(A[i][j]==1)
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            }
        }
        
        return A;
    }
};

int main(int argc, char const *argv[])
{
	vector< vector<int> > a, b;
	vector<int>t;
	int n, m, p;
	cin>>n>>m;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>p;
			t.push_back(p);
		}
		a.push_back(t);
		t.clear();
	}

	Solution s;
	b = s.flipAndInvertImage(a);
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cout<<b[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
