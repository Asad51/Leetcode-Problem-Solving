#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int n = 0;
        for(int i=0; i<S.size(); i++){
            for(int j=0; j<J.size(); j++){
                if(S[i]==J[j]){
                    n++;
                    break;
                }
            }
        }

        return n;
    }
};

int main(int argc, char const *argv[]) {
  string s,j;
  cin>>j;
  cin>>s;

  Solution so;
  cout<<so.numJewelsInStones(j,s)<<endl;
  return 0;
}
