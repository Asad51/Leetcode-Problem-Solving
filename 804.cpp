#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string words[100];
  string chr[] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
  map<char, string> morse;
  set<string> pat;
  int n;
  string a, tmp;
  cin>>n;

  for(int i=0; i<n; i++){
    cin>>a;
    words[i] = a;
  }

  for(int i=0; i<26; i++){
    morse.insert(make_pair('a'+i, chr[i]));
  }

  for(int i=0; i<n; i++){
    tmp = "";
    for(int j=0; j<words[i].size(); j++){
      char ch = words[i][j];
      tmp = tmp + morse[ch];
    }
    pat.insert(tmp);
  }

  cout<<pat.size()<<endl;
  return 0;
}


/**
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        map <char, string> morse;
        set <string> pat;
        string chr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

        for(int i=0; i<26; i++ ){
            morse.insert(make_pair('a'+i, chr[i]));
        }



        for(int i=0; i<words.size(); i++){
            string tmp = "";
            for(int j=0; j<words[i].size(); j++){
                char ch = words[i][j];
                tmp = tmp + morse[ch];
            }
            pat.insert(tmp);
        }

        return pat.size();
    }
};

**/
