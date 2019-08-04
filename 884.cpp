#include <bits/stdc++.h>
using namespace std;

struct Word{
    int wordCount;
    string word;
};

class Solution {
public:
    int hashCode(string s){
        unsigned int b    = 378551;
        unsigned int a    = 63689;
        unsigned int hash = 0;

        for(int i = 0; i < s.size(); i++)
        {
            hash = hash * a + s[i];
            a = a * b;
        }
        return (hash & 0x7FFFFFFF) % 200;
    }
    
    void insertHashMap(Word hashMap[200], string s){
        int hash = hashCode(s);
        while(hashMap[hash].wordCount){
            if(hashMap[hash].word == s){
                hashMap[hash].wordCount++;
                return;
            }
            hash = (hash + 1) % 200;
        }
        hashMap[hash].wordCount++;
        hashMap[hash].word = s;
    }
    
    void createHashMap(Word hashMap[200], string s){
        string tmp = "";
        for(int i = 0; i <= s.size(); i++){
            if(s[i] == ' ' || i ==  s.size()){
                insertHashMap(hashMap, tmp);
                tmp = "";
            }
            else
                tmp += s[i];
        }
    }
    
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string>result;
        Word hashMap[200];
        for(int i = 0; i < 200; i++)
            hashMap[i].wordCount = 0;
        createHashMap(hashMap, A);
        createHashMap(hashMap, B);
        
        for(int i = 0; i < 200; i++){
            if(hashMap[i].wordCount == 1)
                result.push_back(hashMap[i].word);
        }
        
        return result;
    }
};

int main(){
    string A, B;
    getline(cin, A);
    getline(cin, B);
    vector<string>result;
    Solution s;
    result = s.uncommonFromSentences(A, B);
    for(int i = 0; i < result.size(); i++)
        printf("%s ", result[i]);
    printf("\n");
    return 0;
}
