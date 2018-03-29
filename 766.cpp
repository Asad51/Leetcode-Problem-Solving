#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix( vector<vector<int> >& matrix) {
        int r, c;
        set<int> check;
        r = matrix.size();
        c = matrix[0].size();
        for(int i=r-1; i>=0; i--){
            check.clear();
            int k = i;
            for(int j=0; j<c && k<r; j++, k++){
                check.insert(matrix[k][j]);
            }
            if(check.size()!=1){
                return false;
            }
        }

        for(int i=1; i<c; i++){
            int k = i;
            check.clear();
            for(int j=0; j<r && k<c ; j++, k++){
                check.insert(matrix[j][k]);
            }
            if(check.size()!=1){
                return false;
            }
        }
        return true;
    }
};

int main(int argc, char const *argv[]) {
    int r, c, a;
    cin>>r>>c;
    vector< vector<int> > mat;
    vector<int>tmp;

    for(int i=0; i<r; i++){
        tmp.clear();
        for(int j=0; j<c; j++){
            cin>>a;
            tmp.push_back(a);
        }
        mat.push_back(tmp);
    }

    Solution s;
    cout<<s.isToeplitzMatrix(mat)<<endl;
    return 0;
}
