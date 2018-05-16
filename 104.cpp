/**
 *Given a binary tree, find its maximum depth.
 *The maximum depth is the number of nodes along the longest 
 *path from the root node down to the farthest leaf node.
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
	int maxDepth(TreeNode* root) {
		if(root==NULL)
			return 0;
		int c = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
        	c++;
	        int s = q.size();
	        for(int i=0; i<s; i++) {
	            TreeNode* t = q.front();
	            q.pop();
	            if(t->left) 
	               	q.push(t->left);
	            if(t->right) 
	                q.push(t->right);   
	        }
		}
	    return c;
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
	cout<<s.maxDepth(root)<<endl;
	return 0;
}
