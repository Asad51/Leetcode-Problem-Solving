#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector< vector<int> > v;
    int dimx, dimy, y, x;
public:

    int maxAreaOfIsland(vector<vector<int> >& grid) {
        v.assign(grid.begin(), grid.end());
        dimx = v.size();
        dimy = v[0].size();
        int mx = 0, count;
        for(int i=0; i<dimx; i++){
            for(int j=0; j<dimy; j++){
                count = 0;
                if(v[i][j]==1){
                    x = i;
                    y = j;
                    count = checkNode(i, j);
                }

                if(count>mx)
                    mx = count;
            }
        }
        return mx;
    }

    int checkNode(int r, int c){
        int tmp = 0, count = 0;
        //cout<<"r c"<<r<<c<<" Val: "<<v[r][c]<<endl;
        if(v[r][c] != 1 ){
            return 0;
        }
        v[r][c] = -1;

        if(c>0){
            tmp = checkNode(r, c-1);
            count = count + tmp;
        }

        if(c<dimy-1){
            tmp = checkNode(r, c+1);
            count = count + tmp;
        }

        if(r>0){
            tmp = checkNode(r-1, c);
            count = count + tmp;
        }

        if(r<dimx-1){
            tmp = checkNode(r+1, c);
            count = count + tmp;
        }

        count++;
        //cout<<"Count: "<<count<<endl;
        return count;
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

    cout<<s.maxAreaOfIsland(mat)<<endl;
    return 0;
}
