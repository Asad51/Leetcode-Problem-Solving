/**
 * Given a non-empty binary tree, 
 * return the average value of the nodes on each level in the form of an array.
 *
 * 
 */

#include "bits/stdc++.h"
using namespace std;

struct TreeNode {
    int val;
   TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
	            long temp = 0;
	            int s = q.size();
	            for(int i=0; i<s; i++) {
	                TreeNode* t = q.front();
	                q.pop();
	                if(t->left) 
	                	q.push(t->left);
	                if(t->right) 
	                	q.push(t->right);
	                temp += t->val;
	            }
	            res.push_back((double)temp/s);
		    }
	    return res;
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	Solution s;
	vector<double>v;
	v = s.averageOfLevels(root);
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}
