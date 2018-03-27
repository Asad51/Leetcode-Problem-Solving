#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
      map<char, int>charWidths;
      vector<int> len;
      map<char, int>:: iterator itr;
      int totalWidth=0, rem=0, line=0;
      for(int i=0; i<widths.size(); i++){
        char ch = 'a'+i;
        charWidths.insert(make_pair(ch, widths[i]));
      }

      for(int i=0; i<S.size(); i++){
        totalWidth = totalWidth + charWidths[S[i]];
        if((totalWidth+charWidths[S[i+1]])>100){
          totalWidth = 0;
          line++;
        }
      }

      if(totalWidth>0)
        line++;

      len.push_back(line);
      len.push_back(totalWidth);

      return len;
    }
};

int main(int argc, char const *argv[]) {
  vector<int> widths, len;
  vector<int>:: iterator itr;
  string s;
  int n;
  for(int i=0; i<26; i++){
    cin>>n;
    widths.push_back(n);
  }
  cin>>s;

  Solution ss;
  len = ss.numberOfLines(widths, s);
  for(itr = len.begin(); itr!=len.end(); itr++){
    cout<<*itr<<endl;
  }
  return 0;
}
