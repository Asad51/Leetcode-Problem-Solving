#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>res;
        string rows[3] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
        for(int i=0; i<3; i++){
            sort(rows[i].begin(), rows[i].end());
        }
        for(int i=0; i<words.size(); i++){
            bool isSame = true;
            int row;
            for(int j=0; j<3; j++){
                if(binary_search(rows[j].begin(), rows[j].end(), toUpper(words[i][0])))
                {
                    row = j;
                    break;
                }
            }
            for(int k=0; k<words[i].size(); k++){
                if(!binary_search(rows[row].begin(), rows[row].end(), toUpper(words[i][k])))
                {
                    isSame = false;
                    break;
                }
            }
            
            if(isSame){
                res.push_back(words[i]);
            }
        }
        return res;
    }

    char toUpper(char ch){
        if(ch>='a' && ch<='z'){
            ch = ch - 32;
            return ch;
        }
        return ch;
    }
};

int main(int argc, char const *argv[]) {
    string ssss[4] = {"Hello", "Dad", "Alaska", "Peace"};
    vector<string>words, res;
    int n;
    cin>>n;
    string s;
    for(int i=0; i<n; ++i){
        cin>>s;
        words.push_back(s);
    }

    /*for(int i=0; i<words.size(); ++i){
        cout<<words[i]<<endl;
    }*/

    Solution ss;
    res = ss.findWords(words);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<"\n";
    return 0;
}
