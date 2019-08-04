#include <bits/stdc++.h>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int getImportance(vector<Employee*> &employees, int id) {
        int imp = 0;
        map<int, int>impor;
        for(int i=0; i<employees.size(); i++){
        	impor.insert(make_pair(employees[i]->id, employees[i]->importance));
        }

        for(int i=0; i<employees.size(); i++){
        	if(employees[i]->id == id){
        		imp = subImportance(employees, i, employees[i]->importance);
        		break;
        	}
        }
        return imp;
    }

    int subImportance(vector<Employee*> &employees, int i, imp){
    	for(int j=0; j<employees[i]->subordinates.size(); j++){
        	int tmp = employees[i]->subordinates[j];
        	int p = subImportance(employees, )
        }
        return imp;
    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int m;
	vector<Employee*> emp;
	vector<int>sub;
	int id1, imp, su;
	Employee e[n];
	for(int i=0; i<n; i++){
		cin>>id1>>imp>>m;
		sub.clear();
		for(int j=0; j<m; j++){
			cin>>su;
			sub.push_back(su);
		}
		e[i].id = id1;
		e[i].importance = imp;
		e[i].subordinates = sub;
		emp.push_back(&e[i]);
	}
	int target;
	cin>>target;
	Solution s;
	cout<<s.getImportance(emp, target)<<endl;
	return 0;
}