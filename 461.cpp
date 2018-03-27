#include <bits/stdc++.h>
using namespace std;

class Solution {
    string sx, sy;
public:
    int hammingDistance(int x, int y) {
        int n=0;
        sx = makeBinaryString(x);
        sy = makeBinaryString(y);
        //cout<<sx<<":"<<sy<<endl;
        for(int i=0; i<32; i++){
            if(sx[i] != sy[i]){
              n++;
            }
        }
        return n;
    }

    string makeBinaryString(int x){
        string tmp = "00000000000000000000000000000000";
        int rem, i=31;
        char ch;

        while(x!=0){
            rem = x%2;
            x = x/2;
            ch = 48+rem;
            tmp[i] = ch;
            i--;
        }

        return tmp;

    }
};

int main(int argc, char const *argv[]) {
  int x,y;
  cin>>x>>y;
  Solution ss;
  cout<<ss.hammingDistance(x,y)<<endl;
  return 0;
}
