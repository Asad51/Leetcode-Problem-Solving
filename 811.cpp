#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> res, doms, domains;
        map<string, int>mp;
        map<string, int>:: iterator it;
        int count;

        for(int i=0; i<cpdomains.size(); i++){
        	doms = split(cpdomains[i],' ');
        	stringstream(doms[0]) >> count; //string to integer
        	domains = split(doms[1], '.');
        	string s = "";

        	for(int j=domains.size()-1; j>=0; j--){
                if(j<(domains.size()-1)){
                    s = domains[j] + "." + s;
                }
                else{
                    s = domains[j];
                }

        		if(mp.find(s)!=mp.end()){
        			mp[s] = mp[s] + count;
        		}
        		else{
        			mp[s] = count;
        		}
        	}

        }

        for(it=mp.begin(); it!=mp.end(); it++){
        	res.push_back(toString(it->second)+" "+it->first);
        }
        return res;
    }

    string toString(int val){
        string s = "";
        while(val){
            char ch = (val%10)+48;
            s = s + ch;
            val = val/10;
        }
        reverse(s.begin(), s.end());
        return s;
    }

    vector<string> split(string str, char delim){
    	string s = "";
    	vector<string> sp;
    	for(int i=0; i<str.size(); i++){
    		if(str[i] == delim){
                sp.push_back(s);
                s = "";
    		}
    		else{
    			s = s + str[i];
    		}
    	}
        sp.push_back(s);
    	return sp;
    }
};

int main(){
	int n;
	string s2;
	//cin>>n;
	vector<string> subDom, res;
    string s[4] = {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
	for(int i=0; i<4; i++){
		subDom.push_back(s[i]);
	}

	Solution ss;
	res = ss.subdomainVisits(subDom);
	for(int i=0; i<res.size(); i++){
		cout<<res[i]<<endl;
	}
	return 0;
}
