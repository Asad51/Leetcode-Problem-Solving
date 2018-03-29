#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector< vector<int> > matrixReshape( vector<vector<int> >& nums, int r, int c) {
        int r1, c1;
        vector< vector<int> > numsr;
        vector< int > tmp, mid;

        r1 = nums.size();
        c1 = nums[0].size();
        if(r*c != r1*c1){
            return nums;
        }

        for(int i=0; i<r1; i++){
            for(int j=0; j<c1; j++){
                mid.push_back(nums[i][j]);
            }
        }
        int k = 0;
        for(int i=0; i<r; i++){
            tmp.clear();
            for(int j=0; j<c; j++){
                tmp.push_back(mid[k]);
                k++;
            }
            numsr.push_back(tmp);
        }
        return numsr;
    }
};

int main(int argc, char const *argv[]) {
    int r1,c1,r2,c2,a;
    cin>>r1>>c1>>r2>>c2;
    vector< vector<int> > nums, numsr;
    vector<int> temp;
    for(int i=0; i<r1; i++){
        temp.clear();
        for(int j=0; j<c1; j++){
            cin>>a;
            temp.push_back(a);
        }
        nums.push_back(temp);
    }

    Solution ss;
    numsr = ss.matrixReshape(nums, r2, c2);
    int r3 = numsr.size();
    int c3 = numsr[0].size();
    for(int i=0; i<r3; i++){
        for(int j=0; j<c3; j++){
            cout<<numsr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
