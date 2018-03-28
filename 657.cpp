#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
      int x=0, y=0;
      for(int i=0; i<moves.size(); i++){
        if(moves[i]=='U'){
          y = y+1;
        }
        else if(moves[i]=='D'){
          y = y-1;
        }
        else if(moves[i]=='R'){
          x = x+1;
        }
        else if(moves[i]=='L'){
          x = x-1;
        }
      }

      if(x==0 && y==0){
        return true;
      }
      else{
        return false;
      }
    }
};

int main(int argc, char const *argv[]) {
  string s;
  cin>>s;
  Solution ss;
  cout<<ss.judgeCircle(s)<<endl;
  return 0;
}
